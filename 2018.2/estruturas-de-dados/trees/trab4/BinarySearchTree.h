#ifndef BST$X_Y123
#define BST$X_Y123

typedef struct TNode {
    long int value;
    struct TNode *left;
    struct TNode *right;

} Node;

// Returns wether or not the list is empty.
int empty (Node *);

// Inserts a new element to the Tree.
void insert (Node **, long int);

// Searches for a given value.
// If the value is found within the list, returns a pointer to it.
// Else, returns NULL.
Node *search (Node *, long int);

// Deletes the node with given value from the tree.
void erase(Node **, Node **, long int);

// Traverse the tree Pre Order and prints the nodes.
void printPreOrder(Node *);

// Traverse the tree In Order (increasing) and prints the nodes.
void printInOrder(Node *);

// Traverse the tree Post Order and prints the nodes.
void printPostOrder(Node *);

// Traverse the tree using Breadth First Search and prints the nodes.
void printBFS(Node *);

// Clear the entire list
void clear(Node *);

// Calculates the height of the tree.
long int calcTreeHeight(Node *);

// Counts the number of nodes.
long int countNumberOfNodes(Node *);

// Returns the value of the In-Order predecessor of the given node.
Node *getPredecessor(Node *, Node *, long int);

// Returns the value of the In-Order sucessor of the given node.
Node *getSucessor(Node *, Node *, long int);

// Shows the menu with the avaiable operations.
void showMenu();

#endif
