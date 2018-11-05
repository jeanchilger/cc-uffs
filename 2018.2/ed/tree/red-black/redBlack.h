#ifndef _$RBT$21_$1a
#define _$RBT$21_$1a

#include <stdio.h>
#include <stdlib.h>

struct TNode {
    int value;
    struct TNode *left;
    struct TNode *right;
    struct TNode *parent;
    int color; // 0 - Red, 1 - Black
};

typedef struct TNode Node;

// Checks whether the tree is empty or not.
int empty(Node *);

// Inserts a new element in the tree.
// If the insertion makes the tree skewed, it is rebalanced following Red-Black rules.
void insert(Node **, int);

// Searchs for a given value in the tree and returns a pointer to its node.
// If not found, returns NULL.
Node *search(Node *, int);

// Traverse the tree Pre Order and prints the nodes.
void printPreOrder(Node *);

// Traverse the tree In Order and prints the nodes.
void printInOrder(Node *);

// Traverse the tree Post Order and prints the nodes.
void printPostOrder(Node *);

// Clear the entire tree.
void clear(Node *);

// Calculates the height of the tree at the given node.
// By default, the root is counted. 
int calcTreeHeight(Node *);
 
// Counts the number of the nodes in the tree.
int countNumberOfNodes(Node *);

// Prints the menu, showing avaiable options.
void showMenu();

#endif
