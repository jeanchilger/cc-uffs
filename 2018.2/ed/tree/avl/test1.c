#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void insertRandonNumbers(Node **root, long int n, int max) {
    /*
     * Inserts n random numbers, from 0 to max, in the tree.
     * */

    long int i;
    int val;

    printf("Inserting %ld numbers...\n", n);
    for (i = 0; i < n; i++) {
        val = rand() % max;
        insert(root, val);
        printf("%d\r\r\r\r\r\r", val);
    }
}

int main() {
	int opt, val, max;
    long int n;
	Node *root = NULL;

    printf("How many numbers? ");
    scanf(" %ld", &n);
    printf("Max range of the numbers ([0, max[): ");
    scanf(" %d", &max);
    insertRandonNumbers(&root, n, max);
    
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
            
            Node* elem = search(root, val);
            if (elem == NULL) {
                printf ("%d not found\n", val);
            
            } else {
                printf("%d found\n", val);
            }

        } else if (opt == 3) {
            printf(" 1 - Pre-Order\n 2 - In-Order\n 3 - Post-Order\n 4 - BFS\n: ");
            int n;
            scanf(" %d", &n);
            if (n == 1) {
                printPreOrder(root);                                    
            
            } else if (n == 2) {
                printInOrder(root);
            
            } else if (n == 3) {
                printPostOrder(root);                                                  

            } else if (n == 4) {
                printBFS(root);
            }
        
        } else if (opt == 4) {
        
        } else if (opt == 5) {
            clear(root);
            root = NULL;
        
        } else if (opt == 6) {
            int h = calcTreeHeight(root);
            printf("%d, counting root,\n", h);
            printf("%d, not counting.\n", h - 1);

        } else if (opt == 7) {
            int n = countNumberOfNodes(root);
            printf("Number of nodes: %d\n", n);

        } else if (opt == 9) {
            showMenu();
        
        } else if (opt == 0) {
            printf("Goodbye.\n");
            break;

        } else {
            printf("What did you said?\n");
        }
    }
    return 0;
}
