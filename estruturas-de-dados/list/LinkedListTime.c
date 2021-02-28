#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int value;
    struct node *next;

} node;
 

void insert(node** current, node** begin, int val) {
    /*
     * Adds a new element at the end of the list.
     * */

    if (*begin == NULL) {
        (*current) = (node*)malloc(sizeof(node));
        (*current) -> value = val;
        (*current) -> next = NULL;
        *begin = *current;


    } else {
        (*current) -> next = (node*)malloc(sizeof(node));
        (*current) -> next -> value = val;
        (*current) -> next -> next = NULL;
        (*current) = (*current) -> next;

    }
}

node * search(node* begin, int val) {
    /*
     * Returns the index of a given value in the list.
     * Returns -1 if value doesn't exists.
     * */
    
    while (begin != NULL) {
        if (begin -> value == val) return begin;
        begin = begin -> next;
    }

    return NULL;

}

void clear(node* begin) {
    /*
     * Erases the whole list.
     * */

    if (begin == NULL) return;
    clear(begin -> next);
    free(begin);
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

int main() {

    node *begin = NULL;
    node *current = NULL;
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
	            insert(&begin, &current, rand() % 100);
            }
            
            tend = clock();

            time_spent = (double)(tend - tbegin) / CLOCKS_PER_SEC;
            printf("The insertion took %4.5lf seconds.\n", time_spent);

        } else if (opt == 2) {
            printf("Value to search: ");
            scanf(" %d", &val);
            
            tbegin = clock();
            node* elem = search(begin, val);
            if (elem == NULL) {
                printf ("%d not found\n", val);
            
            } else {
                printf("%d found\n", val);
            }
            tend = clock();
			
			time_spent = (double)(tend - tbegin) / CLOCKS_PER_SEC;
            printf("The search took %4.5lf seconds.\n", time_spent);
        
        } else if (opt == 3) {
            clear(begin);
            begin = NULL;
        
        } else if (opt == 9) {
            showMenu();
        
        } else if (opt == 0) {
            printf("Goodbye.\n");
            if (begin != NULL) {
            	clear(begin);
            }
            break;

        } else {
            printf("What did you say?\n");
        }

    }

    return 0;
}

