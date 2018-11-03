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

// 1 - Checks if the Tree is empty.
int empty (Node *);

// 2 - Inserts a new value into the Tree.
void insert (Node **, int);

// 3 - Searches for a given value.
Node *search (Node *, int);

// 4 - Removes a single element from the tree.
void eraseElement(Node **, int);

// 5 - Prints the values in increasing order.
void printInOrder(Node *);

// 6 - Clear the entire list.
void clear(Node *);

// 7 - Calculates the height of the tree.
int treeHeight(Node *);

// 8 - Counts the number of nodes.
int countNodes(Node *);

// 9 - Shows the menu with the avaiable operations.
void showMenu();

#endif
