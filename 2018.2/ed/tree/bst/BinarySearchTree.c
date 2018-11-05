#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int max(int a, int b) {
    /*
     * Returns the max between a and b.
     * */

    return (a > b) ? a : b;
}

int empty(Node *root) {
    /*
     * Returns wether or not the list is empty.
     * */

    return (root == NULL);

}

void insert(Node **root, int val) {
    /*
     * Inserts a new element to the Tree.
     * */

    if (empty((*root))) {
        (*root) = (Node*)malloc(sizeof(Node));
        (*root) -> right = NULL;
        (*root) -> left = NULL;
        (*root) -> value = val;

    } else {
        if (val > (*root) -> value) {
            insert(&((*root) -> right), val);

        } else if (val < (*root) -> value) {
            insert(&((*root) -> left), val);

        } else {
            printf("I yield!!\n");
            return;
        }
    }
}

Node *search (Node *root, int val) {
    /*
     * Searches for a given value.
     * If the value is found within the list, returns a pointer to it.
     * Else, returns NULL.
     * */
     
    if (root == NULL) {
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

void printInOrder(Node *root) {
    /*
     * Prints the elements in increasing order.
     * */

    if (root == NULL) return;
    printInOrder(root -> left);
    printf(" %d", root -> value);
    printInOrder(root -> right);
}

void eraseElement(Node **root, int val) {
    printf("I don't work!\n");
}

void clear(Node *root) {
    /*
     * Clear the entire list
     * */
    
    if (root == NULL) return;
    clear(root -> left);
    clear(root -> right);
    free(root);                 
}

int treeHeight(Node *root) {
    /*
     * Calculates the height of the tree.
     * */

    if (root == NULL) return 0;
    return max(1 + treeHeight(root -> left), 
               1 + treeHeight(root -> right));                    
}

int countNodes(Node *root) {
    /*
     * Counts the number of nodes.
     * */

    if (root == NULL) return 0;
    return countNodes(root -> left) + countNodes(root -> right) + 1;
}

void printBFS(Node *root, int h) {
    if (root == NULL) return;
    printBFS(root -> left, h-1);
    printBFS(root -> right, h-1);
    if (h == 0) printf(" %d", root -> value);

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
