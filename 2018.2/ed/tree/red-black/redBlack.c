#include <stdio.h>
#include <stdlib.h>
#include "redBlack.h"

//
// Utility functions

int max (int a, int b) {
    /*
     * Returns the max between a and b.
     * */

    return (a > b) ? a : b;
}

Node *newNode (Node *parent, int val) {
    /*
     * Creates a new node and returns it.
     * */

    Node *new = (Node *)malloc(sizeof(Node));
    new -> value = val;
    new -> left = NULL;
    new -> right = NULL;
    new -> color = 0; // when inserted, node is red.
    new -> parent = parent;

    return new;
}

void leftRotate(Node **node) {
    /*
     * Performs the LEFT rotation in the subtree rooted in the given node.
     * */

}

void rightRotate(Node **node) {
    /*
     * Performs the RIGHT rotation in the subtree rooted in the given node.
     * */
}

void insertionFixUp(Node **root) {
    /*
     * Fixes the possible unbalance caused in the insertion of a new value.
     * */
}

//
// Red-Black Tree functions

int empty(Node *root) {
    /*
     * Checks whether the tree is empty or not.
     * */

    return (root == NULL);
}

void insert(Node **root, int val, Node *parent) {
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
}

Node *search(Node *root, int val) {
    /*
     * Searchs for a given value in the tree and returns a pointer to its node.
     * If not found, returns NULL.
     * */

    if (root == NULL) return NULL;
    if (root -> value == val) return root;
    if (val > root -> value) return search(root -> right, val);
    if (val < root -> value) return search(root -> left, val);
}

void printPreOrder(Node *root) {
    /*
     * Traverse the tree Pre Order and prints the nodes.
     * */

    if (empty(root)) return;
    printf("v: %d\n", root -> value);
    if (!empty(root -> parent)) {
        printf("p: %d\n\n", root -> parent -> value);
    }
    printPreOrder(root -> left);
    printPreOrder(root -> right);
}

void printInOrder(Node *root) {
    /*
     * Traverse the tree In Order (increasing) and prints the nodes.
     * */
 
    if (root == NULL) return;
    printInOrder(root -> left);
    printf(" %d", root -> value);
    printInOrder(root -> right);
}

void printPostOrder(Node *root) {
    /*
     * Traverse the tree Post Order and prints the nodes.
     * */

    if (root == NULL) return;
    printPostOrder(root -> left);
    printPostOrder(root -> right);
    printf(" %d", root -> value);
}

void printBFS(Node *root) {
    /*
     * Traverse the tree using BFS and prints the nodes.
     * */
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

int calcTreeHeight(Node *root) {
    /*
     * Calculates the height of the tree at the given node.
     * By default, the root is counted.
     * */

    return 1;
}

int countNumberOfNodes(Node *root) {
    /*
     * Counts the number of the nodes in the tree.
     * */

    return 1;
}

void showMenu() {
    printf("\n\t\t  MENU\n");
    printf("================================================\n");
    printf(" | 1 - Insert element                         |\n");
    printf(" | 2 - Search value                           |\n");
    printf(" | 3 - Print elements                         |\n");
    printf(" | (X)4 - Erase element                       |\n");
    printf(" | 5 - Clean list                             |\n");
    printf(" | 6 - Calc. tree height                      |\n");
    printf(" | 7 - Number of nodes                        |\n");
    printf(" | 9 - Show menu                              |\n");
    printf(" | 0 - Exit                                   |\n");
    printf("================================================\n");
}

