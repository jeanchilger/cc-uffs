#include <stdio.h>
#include <stdlib.h>
#include "redBlack.h"

//
// Utility functions

long int max (long int a, long int b) {
    /*
     * Returns the max between a and b.
     * */

    return (a > b) ? a : b;
}

Node *newNode (Node *parent, long int val) {
    /*
     * Creates a new node and returns it.
     * */

    Node *new = (Node *)malloc(sizeof(Node));
    new -> value = val;
    new -> left = NULL;
    new -> right = NULL;
    new -> color = RED; // when inserted, node is red.
    new -> parent = parent;

    return new;
}

Node *getParent(Node *node) {
    /*
     * Utility function to get the parent of a node.
     * */

    //printf("parent\n");
    if (!empty(node)) {
        return (node) -> parent;
    }


    return NULL;
}

Node *getGrandParent(Node *node) {
    /*
     * Utility function to get the grand parent of a node.
     * */

    //printf("grandParent\n");
    if (!empty(node)) {
        return getParent(node -> parent);
    }

    return NULL;
}

Node *getUncle(Node *node) {
    /*
     * Utility function to get the uncle of a node.
     * */

    if (!empty(node)) {
        Node *gp = getGrandParent(node);
       // printf("uncle\n");
        if (!empty(gp)) {
            if (getParent(node) == gp -> left) {
                return gp -> right;

            } else if (getParent(node) == gp -> right) {
                return gp -> left;
            }
        }
    }

    return NULL;
}

Node *leftRotate(Node *node) {
    /*
     * Performs the LEFT rotation in the subtree rooted in the given node.
     * */

    Node *a = node;
    Node *b = a -> right;
    Node *s2 = b -> left;

    a -> right = s2;
    b -> left = a;

    return b;
}

Node* rightRotate(Node **node) {
    /*
     * Performs the RIGHT rotation in the subtree rooted in the given node.
     * */

    Node *a = (*node);
    Node *b = a -> left;
    Node *s2 = b -> right;

    if (!empty(s2)) {
        s2 -> parent = a;
    }
    //a -> parent -> left = b;
    b -> parent = a -> parent;
    a -> parent = b;

    b -> right = a;
    a -> left = s2;

    return b;
}

void insertionFixUp(Node **node) {
    /*
     * Fixes the possible unbalance caused in the insertion of a new value.
     * */

    // BUG: o nó grandParent não está sendo atualizado por algum motivo;

    if (empty(*node)) return;

    if (!empty(*node) && empty(getParent(*node))) {
        // node is root
        printf("NODE IS ROOT\n");
        (*node) -> color = BLACK;
        return;
    }

    if(!empty(getParent(*node)) && getParent(*node) -> color == RED) {
        Node *parent = getParent(*node);
        Node *uncle = getUncle(*node);
        Node *grandParent = getGrandParent(*node);

        printf("NODE NOT THE ROOT\n");
        if (!empty(uncle) && uncle -> color == RED) {
            // node has a red uncle
            printf("NODE HAS RED UNCLE\n");
            parent -> color = BLACK;
            uncle -> color = BLACK;
            grandParent -> color = RED;

        } else if(!empty(grandParent)) {
            // node has a black uncle
            printf("NODE HAS BLACK UNCLE\n");

            if (!empty(grandParent)
                    && parent == (grandParent -> left)) {
                if ((*node) == parent -> left) {
                    //left left case
                    printf("LEFT LEFT\n");
                    int parentColor = parent -> color;
                    parent -> color = grandParent -> color;
                    grandParent -> color = parentColor;

                    // printf("BBBBBBBBBBBBBBBBBB: %ld\n", (*node) -> right -> value);
                    rightRotate(&grandParent);
                    // printf("R %ld\n", (*node) -> right -> value);
                    // printf("L %ld\n", (*node) -> left -> value);
                    printBFS(grandParent);
                    // printf("AAAAAAAAAAAAAAAAAA: %ld\n", (*node) -> right -> value);
            //
            } else if ((*node) == parent -> right) {
                    // left right case
                    printf("LEFT RIGHT\n");
            //
                    (*node) = leftRotate(parent);

                    int parentColor = parent -> color;
                    parent -> color = grandParent -> color;
                    grandParent -> color = parentColor;

                    // (*node) = rightRotate(grandParent);
            //
                }

            } else if (!empty(grandParent)
                    && parent == grandParent -> right) {
                if ((*node) == parent -> right) {
                    // right right case
                    printf("RIGHT RIGHT\n");
            //
                    int parentColor = parent -> color;
                    parent -> color = grandParent -> color;
                    grandParent -> color = parentColor;

                    (*node) = leftRotate(grandParent);
            //
                } else if ((*node) == parent -> left) {
                    // right left case
                    printf("RIGHT LEFT\n");
            //
                    (*node) = leftRotate(parent);

                    int parentColor = parent -> color;
                    parent -> color = grandParent -> color;
                    grandParent -> color = parentColor;

                    // (*node) = rightRotate(grandParent);
            //
                }
            }
        }
    }

    Node *gp = getGrandParent(*node);
    insertionFixUp(&(gp));
}

//
// Red-Black Tree functions

int empty(Node *root) {
    /*
     * Checks whether the tree is empty or not.
     * */

    return (root == NULL);
}

void insert(Node **root, long int val) {
    /*
     * Inserts a new element in the tree.
     * If the insertion makes the tree skewed, it is rebalanced following Red-Black rules.
     * */

    if (empty(*root)) {
        (*root) = newNode(NULL, val);
        insertionFixUp(root);

    } else {

        // printf("AAAAA %ld\n", (*root) -> value);
        // Node *a = (*root);
        // (a) -> value = 666;
        // printf("BBBBBBB %ld\n", (*root) -> value);
        // return;

        Node *current = (*root);
        Node *parent = current;

        while (!empty(current)) {
            parent = current;
            if (val > current -> value) {
                // printf("CUR righ: %ld\n", current -> value);
                current = current -> right;

            } else if (val < current -> value) {
                // printf("CUR left: %ld\n", current -> value);
                current = current -> left;
                // printf("END CUR\n");

            } else {
                //printf("Baka!!\nValue already exists.\n");
                return;
            }
        }

        // printf("check PARENT: %ld\n", parent -> value);
        if (val > parent -> value) {
            parent -> right = newNode(parent, val);
            insertionFixUp(&(parent -> right));
            printf("T1\n");

        } else if (val < parent -> value) {
            parent -> left = newNode(parent, val);
            if (val == 5) {
                // tests
                printf("SSSSSSSS\n");
                Node *gp = getGrandParent(parent -> left);
                printInOrder(gp);
                printf("\n\n");
                Node *b = rightRotate(&gp);
                gp -> value = b -> value;
                gp -> left = b -> left;
                gp -> right = b -> right;
                gp -> parent = b -> parent;
                gp -> color = b -> color;
                return;

            }
            insertionFixUp(&(parent -> left));
            printf("T2\n");

        } else {
            return;
        }
    }
}

Node *search(Node *root, long int val) {
    /*
     * Searchs for a given value in the tree and returns a pointer to its node.
     * If not found, returns NULL.
     * */

    if (root == NULL) return NULL;
    if (root -> value == val) return root;
    if (val > root -> value) return search(root -> right, val);
    if (val < root -> value) return search(root -> left, val);
}

void erase(Node **root, long int val) {
    /*
     * Removes a single element from the tree.
     * */

    printf("I don't work!!\n");
}

void printPreOrder(Node *root) {
    /*
     * Traverse the tree Pre Order and prints the nodes.
     * */

    if (empty(root)) return;
    printf(" %ld\n", root -> value);
    printPreOrder(root -> left);
    printPreOrder(root -> right);
}

void printInOrder(Node *root) {
    /*
     * Traverse the tree In Order (increasing) and prints the nodes.
     * */

    if (root == NULL) return;
    printInOrder(root -> left);
    printf(" %ld", root -> value);
    printInOrder(root -> right);
}

void printPostOrder(Node *root) {
    /*
     * Traverse the tree Post Order and prints the nodes.
     * */

    if (root == NULL) return;
    printPostOrder(root -> left);
    printPostOrder(root -> right);
    printf(" %ld", root -> value);
}

void bfs(Node *root, long int i) {
    /*
     * Helper function to prints all nodes at the ith level.
     * */

    if (empty(root)) return;
    if (i == 0) printf("\tval: %ld | color: %d ", root -> value, root -> color);
    bfs(root -> left, i - 1);
    bfs(root -> right, i - 1);
}

void printBFS(Node *root) {
    /*
     * Traverse the tree using BFS and prints the nodes.
     * */

    long int i;
    for (i = 0; i < calcTreeHeight(root); i++) {
        bfs(root, i);
        printf("\n");
    }
}

void clear(Node *root) {
    /*
     * Clear the entire tree.
     * */

    if (root == NULL) return;
    clear(root -> left);
    clear(root -> right);
    free(root);
}

long int calcTreeHeight(Node *root) {
    /*
     * Calculates the height of the tree at the given node.
     * By default, the root is counted.
     * */

    if (empty(root)) return 0;
    return max(1 + calcTreeHeight(root -> left),
               1 + calcTreeHeight(root -> right));
}

long int calcTreeBlackHeight(Node *root) {
    /*
     * Calculates the black-height of the tree at the given node.
     * */

    if (empty(root)) return 1;
    if (root -> color) return max(1 + calcTreeBlackHeight(root -> left),
                                  1 + calcTreeBlackHeight(root -> right));
}

long int countNumberOfNodes(Node *root) {
    /*
     * Counts the number of the nodes in the tree.
     * */

    if (empty(root)) return 0;
    return 1 + countNumberOfNodes(root -> left) + countNumberOfNodes(root -> right);
}

void showMenu() {
    printf("\n\t\t  MENU\n");
    printf("================================================\n");
    printf(" | 1 - Insert element                         |\n");
    printf(" | 2 - Search value                           |\n");
    printf(" | (X)3 - Erase element                       |\n");
    printf(" | 4 - Print elements                         |\n");
    printf(" | 5 - Clean list                             |\n");
    printf(" | 6 - Calc. tree height                      |\n");
    printf(" | 7 - Number of nodes                        |\n");
    printf(" | 9 - Show menu                              |\n");
    printf(" | 0 - Exit                                   |\n");
    printf("================================================\n");
}
