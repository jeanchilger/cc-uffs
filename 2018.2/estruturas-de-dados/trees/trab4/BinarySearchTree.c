#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

//
// Utility functions.
//

long int max(long int a, long int b) {
    /*
     * Returns the max between a and b.
     * */

    return (a > b) ? a : b;
}

long int power(long int b, long int e) {
    long int i;
    long int r = 1;
//    printf(" e: %ld || b: %ld\n", e, b);
    if (!e) return 1;
    for (i = 0; i < e; i++) {
        r *= b;
    }

//    printf("pow: %ld \n", b);
    return b;
}

Node *findMaxNode(Node *root) {
    /*
     * Returns the node with MAX value within the subtree rooted in root.
     * */

    if (empty(root)) return NULL;
    if (empty(root -> right)) return root;
    return findMaxNode(root -> right);
}

Node *findMinNode (Node *root) {
    /*
     * Returns the node with MIN value within the subtree rooted in root.
     * */

    if (empty(root)) return NULL;
    if (empty(root -> left)) return root;
    return findMinNode(root -> left);
}

Node *newNode(long int val) {
    /*
     * Returns a new node.
     * */

    Node *new = (Node *)malloc(sizeof(Node));
    new -> left = NULL;
    new -> right = NULL;
    new -> value = val;

    return new;
}

void printSpaces(long int n) {
    /*
     * Prints n spaces.
     * */

    printf(" %ld ESPAÇOS\n\n", n);
    long int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
}

//
// BST functions.
//

int empty(Node *root) {
    /*
     * Returns wether or not the list is empty.
     * */

    return (root == NULL);

}

void insert(Node **root, long int val) {
    /*
     * Inserts a new element to the Tree.
     * */

    if (empty((*root))) {
        (*root) = newNode(val);

    } else {
        if (val > (*root) -> value) {
            insert(&((*root) -> right), val);

        } else if (val < (*root) -> value) {
            insert(&((*root) -> left), val);

        } else {
            return;
        }
    }
}

Node *search (Node *root, long int val) {
    /*
     * Searches for a given value.
     * If the value is found within the list, returns a pointer to it.
     * Else, returns NULL.
     * */

    if (empty(root)) {
        return NULL;
    }

    if ((root -> value) == val) {
        return root;

    } else if (val > (root -> value)) {
        return search(root -> right, val);

    } else {
        return search((root -> left), val);
    }

}

void erase(Node **root, Node **parent, long int val) {
    /*
     * Deletes the node with given value from the tree.
     * */

    if (empty(*root)) {
        return ;
    }

    if (((*root) -> value) == val) {
        if (empty((*root) -> left) && empty((*root) -> right)) {
            // The node to be deleted is a leaf
            free(*root);
            (*root) = NULL;

        } else if (empty((*root) -> left) || empty((*root) -> right)) {
            // Node has one child

            if (parent == NULL || (*parent) == NULL) {
                if (empty((*root) -> left)) {
                    Node *tmp = (*root) -> right;
                    free(*root);
                    (*root) = tmp;

                } else if (empty((*root) -> right)) {
                    Node *tmp = (*root) -> left;
                    free(*root);
                    (*root) = tmp;

                }
            } else {
                if ((*root) == (*parent) -> left) {
                    if (empty((*root) -> left)) {
                        Node *tmp = (*root) -> right;
                        free(*root);
                        (*parent) -> left = tmp;

                    } else {
                        Node *tmp = (*root) -> left;
                        free(*root);
                        (*parent) -> left = tmp;
                    }

                } else {
                    if (empty((*root) -> left)) {
                        Node *tmp = (*root) -> right;
                        free(*root);
                        (*parent) -> right = tmp;

                    } else {
                        Node *tmp = (*root) -> left;
                        free(*root);
                        (*parent) -> right = tmp;
                    }
                }
                //free(*root);
                return ;
            }

        } else {
            // Node has two child
            Node *p = getPredecessor(*root, NULL, val);
            long int rValue = (*root) -> value;
            (*root) -> value = p -> value;
            p -> value = rValue;
            erase(&((*root) -> left), root, rValue);
        }

    } else if (val > ((*root) -> value)) {
        erase(&((*root) -> right), root, val);

    } else {
        erase(&((*root) -> left), root, val);
    }
}

void printPreOrder(Node *root) {
    /*
     * Traverse the tree Pre Order and prints the nodes.
     * */

    if (empty(root)) return;
    printf(" %ld", root -> value);
    printPreOrder(root -> left);
    printPreOrder(root -> right);
}

void printInOrder(Node *root) {
    /*
     * Traverse the tree In Order (increasing) and prints the nodes.
     * */

    if (empty(root)) return;
    printInOrder(root -> left);
    printf(" %ld", root -> value);
    printInOrder(root -> right);
}

void printPostOrder(Node *root) {
    /*
     * Traverse the tree Post Order and prints the nodes.
     * */

    if (empty(root)) return;
    printPostOrder(root -> left);
    printPostOrder(root -> right);
    printf(" %ld", root -> value);
}

void bfs(Node *root, long int lvl, long int h, long int l) {
    /*
     * Performs the BFS in tree printing the visited nodes.
     * */

    if (empty(root) || lvl < 0) return;
    if (lvl == 0) {
        //long int s = power(2, h - l);
        //printSpaces(s);
        printf(" %ld", root -> value);
    }
    bfs(root -> left, lvl - 1, h, l);
    bfs(root -> right, lvl - 1, h, l);
}

void printBFS(Node *root) {
    /*
     * Traverse the tree using Breadth First Search and prints the nodes.
     * */

    long int i;
    long int h = calcTreeHeight(root);
    for (i = 0; i < h; i++) {
        bfs(root, i, h, i);
        printf("\n");
    }
}

void clear(Node *root) {
    /*
     * Clear the entire list
     * */

    if (empty(root)) return;
    clear(root -> left);
    clear(root -> right);
    free(root);
}

long int calcTreeHeight(Node *root) {
    /*
     * Calculates the height of the tree.
     * */

    if (empty(root)) return 0;
    return max(1 + calcTreeHeight(root -> left),
               1 + calcTreeHeight(root -> right));
}

long int countNumberOfNodes(Node *root) {
    /*
     * Counts the number of nodes.
     * */

    if (empty(root)) return 0;
    return countNumberOfNodes(root -> left) + countNumberOfNodes(root -> right) + 1;
}

Node *getPredecessor(Node *root, Node *pred, long int val) {
    /*
     * Returns the value of the In-Order predecessor of the given node.
     * */

    if (empty(root)) return NULL;
    if (root -> value == val) {
        if (!empty(root -> left)){
            return findMaxNode(root -> left);

        } else {
            return pred;
        }
    }

    if (root -> value < val) {
        return getPredecessor(root -> right, root, val);

    } else {
        return getPredecessor(root -> left, pred, val);
    }
}

Node *getSucessor(Node *root, Node *suc, long int val) {
    /*
     * Returns the value of the In-Order sucessor of the given node.
     * */

    if (empty(root)) return NULL;
    if (root -> value == val) {
        if (!empty(root -> right)) {
            return findMinNode(root -> right);
        } else {
            return suc;
        }
    }

    if (root -> value > val) {
        return getSucessor(root -> left, root, val);

    } else {
        return getSucessor(root -> right, suc, val);
    }


}

void showMenu() {
    printf("\n\t\t  MENU\n");
    printf("================================================\n");
    printf(" | 1  - Insert elements                        |\n");
    printf(" | 2  - Search value                           |\n");
    printf(" | 3  - Erase element                          |\n");
    printf(" | 4  - Print elements                         |\n");
    printf(" | 5  - Clean list                             |\n");
    printf(" | 6  - Calc. tree height                      |\n");
    printf(" | 7  - Number of nodes                        |\n");
    printf(" | 8  - Get predecessor                        |\n");
    printf(" | 9  - Get sucessor                           |\n");
    printf(" | 10 - Show menu                              |\n");
    printf(" | 0  - Exit                                   |\n");
    printf("================================================\n");
}
