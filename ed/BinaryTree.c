#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    /*
     * Left: lesser than value.
     * Right: bigger than value.
     * */

    int value;
    struct Node *right;
    struct Node *left;
} node;

int empty (node *root) {
    /*
     * Returns wether or not the list is empty.
     * */

    return (root == NULL);
}

void insert (node **root, int val) {
    /*
     * Inserts a new element at the list.
     * The element is inserted in a sorted way.
     * */

    if (empty((*root))) {
        (*root) = (node*)malloc(sizeof(node));
        (*root) -> right = NULL;
        (*root) -> left = NULL;
        (*root) -> value = val;
        
    } else {
        if (val >= (*root) -> value) {
            insert(&((*root) -> right), val);
        
        } else {
            insert(&((*root) -> left), val);
        }
    }
}

node *search (node *root, int val) {
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

void print(node *root) {
    /*
     * Prints the elements in "sorted" order.
     * */

    if (root == NULL) return;

    print(root -> left);
    printf(" %d", root -> value);
    print(root -> right);
    //printf(" %d", root -> value);
}

void showMenu() {
	printf("\n\t\t  MENU\n");
    printf("================================================\n");
    printf(" | 1 - Insert element                         |\n");
    printf(" | 2 - Search value                           |\n");
    printf(" | 3 - Print elements                         |\n");
    printf(" | (X)4 - Erase element                       |\n");
    printf(" | (X)5 - Clean list                          |\n");
    printf(" | 9 - Show menu                              |\n");
    printf(" | 0 - Exit                                   |\n");
    printf("================================================\n");
}

int main () {
    node* begin = NULL;
    node* end = NULL;
    node* root = NULL;
    int val, opt;

    showMenu();
    while (1) {
        printf("\n>>> ");
        scanf(" %d", &opt);

        if (opt == 1) {
            printf("Value to insert: ");
            scanf(" %d", &val);

            insert(&root, val);

        } else if (opt == 2) {
            printf("Value to search: ");
            scanf(" %d", &val);
            
            node* elem = search(root, val);
            if (elem == NULL) {
                printf ("%d not found\n", val);
            
            } else {
                printf("%d found\n", val);
            }

        } else if (opt == 3) {
            print(root);
        
        /*} else if (opt == 4) {
        
        } else if (opt == 5) {*/
        
        } else if (opt == 9) {
            showMenu();
        
        } else if (opt == 0) {
            printf("Goodbye.\n");
            break;

        } else {
            printf("What did you said?\n");
        }

    }
}
