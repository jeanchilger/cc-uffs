#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//
// Utility functions

int max(int a, int b) {
    /*
     * Returns the max between a and b.
     * */
}

Node *newNode(int val) {
    Node *new = (Node*)malloc(sizeof(Node));
    new -> left = NULL;
    new -> right = NULL;
    new -> value = val;

    return new;
}

Node **insertBFS(Node **root, int h) {
    /*
     * Performs the BFS in tree inserting a new node when reaches a null node at the end.
     * */
    
    if (empty((*root))) {
        // INSERE
        return root;
    }

    if (h == 1) return root;
    bfs(&((*root) -> left), h - 1);
    bfs(&((*root) -> right), h - 1);                     
}

//
// HEAP functions

int empty(Node *root) {
    /*
     * Returns whether the tree is empty or not.
     * */

    return (root == NULL);
}

void insert(Node **root, int val) {
    /*
     * Inserts a new element to the tree.
     * */

    int i = calcTreeHeight(root);
    insertBFS(root, i, val);
    leaf = newNode(val);
}
