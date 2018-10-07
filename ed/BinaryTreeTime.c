#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void clear(node *root) {
    /*
     * Clear the entire list.
     * */

    if (root == NULL) return;
    clear(root -> left);
    clear(root -> right);
    free(root);
}

void showMenu() {
	printf("\n\t\t  MENU\n");
    printf("================================================\n");
    printf(" | 1 - Insert elements                        |\n");
    printf(" | 2 - Search value                           |\n");
    printf(" | 3 - Clean list                             |\n");
    printf(" | 9 - Show menu                              |\n");
    printf(" | 0 - Exit                                   |\n");
    printf("================================================\n");
}

int main () {
    node* root = NULL;
    int val, opt;
	int i;

    clock_t tbegin, tend;
    double time_spent;

    showMenu();
    while (1) {
        printf("\n>>> ");
        scanf(" %d", &opt);

        if (opt == 1) {
            printf("How many values to insert: ");
            scanf(" %d", &val);

			tbegin = clock();
            for (i = 0; i < val; i++) {
            	printf("%d\r\r\r\r\r", i);
	            insert(&root, rand() % 100);
            }
            
            tend = clock();

            time_spent = (double)(tend - tbegin) / CLOCKS_PER_SEC;
            printf("The insertion took %4.5lf seconds.\n", time_spent);

        } else if (opt == 2) {
            printf("Value to search: ");
            scanf(" %d", &val);
            
            tbegin = clock();
            node* elem = search(root, val);
            if (elem == NULL) {
                printf ("%d not found\n", val);
            
            } else {
                printf("%d found\n", val);
            }
            tend = clock();
			
			time_spent = (double)(tend - tbegin) / CLOCKS_PER_SEC;
            printf("The search took %4.5lf seconds.\n", time_spent);
        
        } else if (opt == 3) {
            clear(root);
            root = NULL;
        
        } else if (opt == 9) {
            showMenu();
        
        } else if (opt == 0) {
            printf("Goodbye.\n");
            if (root != NULL) {
            	clear(root);
            }
            break;

        } else {
            printf("What did you say?\n");
        }

    }
}
