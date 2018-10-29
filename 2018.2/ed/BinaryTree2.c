#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    /*
     * Left: lesser than value.
     * Right: bigger than value.
     * */

    long long int value;
    struct Node *right;
    struct Node *left;
} node;

#define SIZE 1000000

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

void printI(node *root) {
    /*
     * Prints the elements in increasing order.
     * */

    if (root == NULL) return;

    printI(root -> left);
    printf(" %d", root -> value);
    printI(root -> right);    
}

void printD(node *root) {
    /*
     * Prints the elements in decreasing order.
     * */

    if (root == NULL) return;

    printD(root -> right);
    printf(" %d", root -> value);
    printD(root -> left);
}

void clear(node *root) {
    /*
     * Clear the entire list
     * */

    if (root == NULL) return;
    clear(root -> left);
    clear(root -> right);
    free(root);
}

void showMenu() {
	printf("\n\t\t  MENU\n");
    printf("================================================\n");
    printf(" | 1 - Insert element                         |\n");
    printf(" | 2 - Search value                           |\n");
    printf(" | 3 - Print elements                         |\n");
    printf(" | (X)4 - Erase element                       |\n");
    printf(" | 5 - Clean list                             |\n");
    printf(" | 9 - Show menu                              |\n");
    printf(" | 0 - Exit                                   |\n");
    printf("================================================\n");
}

int main () {
    node* begin = NULL;
    node* end = NULL;
    node* root = NULL;
    int val, opt;

    long int i;
    clock_t tbegin, tend;
    double time_spent;
 
    tbegin = clock();
    for(i = 0; i <= SIZE; i++) {
        printf("%ld\r\r\r\r\r\r\r", i);
        insert(&root, rand());
    }
    tend = clock();
    time_spent = (double)(tend - tbegin)/CLOCKS_PER_SEC;
    printf("\n%4.2lf\n", time_spent);

    showMenu();
    while (1) {
        printf("\n>>> ");
        scanf(" %d", &opt);

/*        if (opt == 1) {
            printf("Value to insert: ");
            scanf(" %d", &val);

            insert(&root, val);

        } else*/ if (opt == 2) {
            printf("Value to search: ");
            scanf(" %d", &val);
            
            node* elem = search(root, val);
            if (elem == NULL) {
                printf ("%d not found\n", val);
            
            } else {
                printf("%d found\n", val);
            }

        } else if (opt == 3) {
            printf("Crescente (1)\\decrescente (2): ");
            scanf(" %d", &val);
            if (val == 1) {
                printI(root);

            } else {
                printD(root);
            }
        
        /*} else if (opt == 4) {*/
        
        } else if (opt == 5) {
            clear(root);
            root = NULL;
        
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
