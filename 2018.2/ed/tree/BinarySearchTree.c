#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

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
            printf("FUCK YOU!!\n");
            return;
        }
    }
}
