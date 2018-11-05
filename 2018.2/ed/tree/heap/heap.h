#ifndef _$HEA123$_P
#define _$HEA123$_P

#include <stdio.h>
#include <stdlib.h>

struct TNode {
    int value;
    struct TNode *left;
    struct TNode *right;
};

typedef TNode Node;

// Checks wether the tree is empty or not.
int empty(Node *);

// Inserts a new element to the tree.
void insert(Node **, int);

// Prints the menu, showing avaiable options.
void showMenu();
