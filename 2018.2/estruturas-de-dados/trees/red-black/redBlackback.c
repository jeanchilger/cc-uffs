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

Node **parent(Node **node) {
    /*
     * Utility function to get the parent of a node.
     * */

    if (!empty(*node)) {
        return &((*node) -> parent);
    }

    return NULL;
}

Node **grandParent(Node **node) {
    /*
     * Utility function to get the grand parent of a node.
     * */

    if (!empty(*node)) {
        return parent(&((*node) -> parent));
    }

    return NULL;
}

Node **uncle(Node **node) {
    /*
     * Utility function to get the uncle of a node.
     * */

    if (!empty(*node)) {
        Node *gp = (*grandParent(node));
        if (!empty(gp)) {
            if ((*parent(node)) == (*grandParent(node)) -> left) {
                return (&((*grandParent(node)) -> right));

            } else if ((*parent(node)) == (*grandParent(node)) -> right) {
                return (&((*grandParent(node)) -> left));
            }
        }
    }

    return NULL;
}

void leftRotate(Node **node) {
    /*
     * Performs the LEFT rotation in the subtree rooted in the given node.
     * */

    Node *a = (*node);
    Node *b = a -> right;
    Node *s2 = b -> left;

    a -> right = s2;
    b -> left = a;

    (*node) = b;
}

void rightRotate(Node **node) {
    /*
     * Performs the RIGHT rotation in the subtree rooted in the given node.
     * */

    Node *a = (*node);
    Node *b = (*node) -> left;
    Node *s2 = b -> right;

    a -> left = s2;
    b -> right = a;

    (*node) = b;
}

void insertionFixUp(Node **node) {
    /*
     * Fixes the possible unbalance caused in the insertion of a new value.
     * */

    if (empty(*parent(node))) { 
        // node is root
        (*node) -> color = BLACK;

    } else {
        if (!empty(*uncle(node)) && (*uncle(node)) -> color == RED) {
            // node has a red uncle
            (*parent(node)) -> color = BLACK;
            (*uncle(node)) -> color = BLACK;
            (*grandParent(node)) -> color = RED;

        } else {
            // node has a black uncle
            if ((*parent(node)) == (*grandParent(node)) -> left) {
                if ((*node) == (*parent(node)) -> left) {
                    //left left case
                    int parentColor = (*parent(node)) -> color;
                    (*parent(node)) -> color = (*grandParent(node)) -> color;
                    (*grandParent(node)) -> color = parentColor;
                    
                    rightRotate(grandParent(node));

                } else if ((*node) == (*parent(node)) -> right) {
                    // left right case
                    leftRotate(parent(node));

                    int parentColor = (*parent(node)) -> color;
                    (*parent(node)) -> color = (*grandParent(node)) -> color;
                    (*grandParent(node)) -> color = parentColor;

                    rightRotate(grandParent(node));
                } 

            } else if ((*parent(node)) == (*grandParent(node)) -> right) {
                if ((*node) == (*parent(node)) -> right) {
                    // right right case
                    int parentColor = (*parent(node)) -> color;
                    (*parent(node)) -> color = (*grandParent(node)) -> color;
                    (*grandParent(node)) -> color = parentColor;

                    leftRotate(grandParent(node));

                } else if ((*node) == (*parent(node)) -> left) {
                    // right left case
                    leftRotate(parent(node));
                     
                    int parentColor = (*parent(node)) -> color;             
                    (*parent(node)) -> color = (*grandParent(node)) -> color;
                    (*grandParent(node)) -> color = parentColor;
                    
                    rightRotate(grandParent(node));
                }
            }
        }
    }
}

//
// Red-Black Tree functions

int empty(Node *root) {
    /*
     * Checks whether the tree is empty or not.
     * */

    return (root == NULL);
}

void insert(Node **root, long int val, Node *parent) {
    /*
     * Inserts a new element in the tree.
     * If the insertion makes the tree skewed, it is rebalanced following Red-Black rules.
     * */

    if (empty((*root))) {
        (*root) = newNode(parent, val);

    } else {
        if (val > (*root) -> value) {
            insert(&((*root) -> right), val, (*root));

        } else if (val < (*root) -> value) {
            insert(&((*root) -> left), val, (*root));

        } else {
            //printf("Baka!!\nValue already exists.\n");
            return;
        }
    }

    insertionFixUp(root);
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

