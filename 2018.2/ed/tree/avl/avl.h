#ifndef _$AVL_$a23e
#define _$AVL_$a23e

#include <stdio.h>
#include <stdlib.h>

struct TNode {
    long int value;
    struct TNode *left;
    struct TNode *right;
    long int height;
};

typedef struct TNode Node;

// Checks whether the tree is empty or not.
int empty(Node *);

// Inserts a new element in the tree.
// If the insertion makes tree skewed, it is rebalanced.
void insert(Node **, long int);

// Searchs for a given value in the tree and returns a pointer to its node.
// If not found, returns NULL.
Node *search(Node *, long int);

// Traverse the tree Pre Order and prints the nodes.
void printPreOrder(Node *);

// Traverse the tree In Order and prints the nodes.
void printInOrder(Node *);

// Traverse the tree Post Order and prints the nodes.
void printPostOrder(Node *);

// Traverse the tree using Breadth First Search and prints the nodes.
void printBFS(Node *);

// Clear the entire tree.
void clear(Node *);

// Calculates the height of the tree at the given node.
// By default, the root is counted. 
long int calcTreeHeight(Node *);

// Counts the number of the nodes in the tree.
long int countNumberOfNodes(Node *);

// Prints the menu, showing avaiable options.
void showMenu();

#endif
