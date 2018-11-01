#ifndef BST$X_Y123
#define BST$X_Y123

typedef struct TNode {
    /*
     * Left: lesser than value.
     * Right: bigger than value.
     * */

    int value;
    struct TNode *left;
    struct TNode *right;
} Node;

// Checks if the Tree is empty
int empty (Node *);

// Inserts a new value into the Tree
void insert (Node **, int);

// Searches for a given value
Node *search (Node *, int);

// Prints the values in increasing order
void printInOrder(Node *);

// Clear the entire list
void clear(Node *);

// Shows the menu with the avaiable operations
void showMenu();

#endif
