#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

//
// Utility functions

int max(int a, int b) {
    /*
     * Returns the max between a and b.
     * */
    
    return (a > b) ? a : b;      
}

int abs(int x) {
    /*
     * Returns the absolute value of the given number.
     * */

    if (x < 0) x *= -1;
    return x;
}

Node *newNode(int val) {
    /*
     * Creates a new tree node and returns it.
     * */

    Node *node = (Node *)malloc(sizeof(Node));
    node -> left = NULL;
    node -> right = NULL;
    node -> value = val;
    node -> height = 0;
    return node;
}

int getHeight(Node *node) {
    /*
     * Returns the height attribute of a node.
     * No calculation is done.
     * */

    if (node == NULL) return 0;
    return node -> height;
}

void leftRotate(Node **node) {
    /*
     * Execute the LEFT rotation in the subtree where the given node is the root.
     * */
    
    Node *a = (*node);
    Node *b = a -> right;
    Node *aux = b -> left;

    b -> left = a;
    a -> right = aux;

    a -> height = max(getHeight(a -> left), getHeight(a -> right)) + 1;
    b -> height = max(getHeight(b -> left), getHeight(b -> right)) + 1;

    (*node) = b;
}

void rightRotate(Node **node) {
    /*
     * Executes the RIGHT rotation in the subtree where the given node is the root.
     * */

    Node *a = (*node);
    Node *b = a -> left;
    Node *aux = b -> right;

    b -> right = a;
    a -> left = aux;

    a -> height = max(getHeight(a -> left), getHeight(a -> right)) + 1;
    b -> height = max(getHeight(b -> left), getHeight(b -> right)) + 1;

    (*node) = b;
} 

//
// AVL functions

int empty(Node *root) {
    /*
     * Checks whether the tree is empty or not.
     * */

    return (root == NULL);
}

void insert(Node **root, int val) {
    /*
     * Inserts a new element in the tree.
     * If the insertion makes the tree skewed, it is rebalanced.
     * */

    if (empty((*root))) {
        (*root) = newNode(val);
    
    } else {
        if (val > (*root) -> value) {
            insert(&((*root) -> right), val);
                    
        } else if (val < (*root) -> value) {
            insert(&((*root) -> left), val);
                                
        } else {
            //printf("Baka!!\nValue already exists.\n");
            return;
        }    
    }
    
    // Updates the heights after new node is inserted
    (*root) -> height = 1 + max(getHeight((*root) -> left), 
                                getHeight((*root) -> right));

    // Checks if tree is unbalanced
    int balance = abs(getHeight((*root) -> left) - getHeight((*root) -> right));
    if (balance > 1) {
        
        if (getHeight((*root) -> left) > getHeight((*root) -> right)) {
  
            // left left case
            if (getHeight((*root) -> left -> left) > getHeight((*root) -> left -> right)) {
                rightRotate(root);


            // left right case
            } else {
                leftRotate(&((*root) -> left));
                rightRotate(root);
            }

        } else {
            
            // right right case
            if (getHeight((*root) -> right -> right) > getHeight((*root) -> right -> left)) {
                leftRotate(root);


            // right left case
            } else {
                rightRotate(&((*root) -> right));
                leftRotate(root);
            }
        }
    }
}

Node *search(Node *root, int val) {
    /*
     * Searchs for a given value in the tree and returns a pointer to it.
     * If not found, returns NULL.
     * */

    return NULL;
}

void printPreOrder(Node *root) {
    /*
     * Traverse the tree Pre Order and prints the nodes.
     * */
     
    if (root == NULL) return;
    printf("| %d: %d ", root -> value, root -> height);
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

void clear(Node *root) {
    /*
     * Clear the entire tree.
     * */

    if (root == NULL) return;
    clear(root -> left);
    clear(root -> right);
    free(root);
}

int calcTreeHeight(Node *node) {
    /*
     * Calculates the height of the tree at the given node.
     * By default, the root is counted.
     * */
   
    if (node == NULL) return 0;
    return max(1 + calcTreeHeight(node -> left), 
               1 + calcTreeHeight(node -> right));
}

int countNumberOfNodes(Node *root) {
    /*
     * Counts the number of the nodes in the tree.
     * */

    if (root == NULL) return 0;
    return countNumberOfNodes(root -> left) + countNumberOfNodes(root -> right) + 1;
}

void showMenu() {
    printf("\n\t\t  MENU\n");
    printf("================================================\n");
    printf(" | 1 - Insert element                         |\n");
    printf(" | (X)2 - Search value                        |\n");
    printf(" | 3 - Print elements                         |\n");
    printf(" | (X)4 - Erase element                       |\n");
    printf(" | 5 - Clean list                             |\n");
    printf(" | 6 - Calc. tree height                      |\n");
    printf(" | 7 - Number of nodes                        |\n");
    printf(" | 9 - Show menu                              |\n");
    printf(" | 0 - Exit                                   |\n");
    printf("================================================\n");
}
