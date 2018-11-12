/*
 * The tree of this program starts with some random numbers in it.
 * The user can insert numbers after that.
 * */

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void insertRandonNumbers(Node **root, long int n, long int max) {
    /*
     * Inserts n random numbers, from 0 to max, in the tree.
     * */

    long int i;
    long int val;

    printf("Inserting %ld numbers...\n", n);
    for (i = 0; i < n; i++) {
        val = rand() % max;
        insert(root, val);
    }
}

int main() {
	int opt;
    long int n, val, max;
	Node *root = NULL;
    
    showMenu();

    while (1) {
        printf("\n>>> ");
        scanf(" %d", &opt);
        
        if (opt == 1) {
            clear(root);
            printf("Tree was cleaned\n\n");
            printf("How many numbers? ");
            scanf(" %ld", &n);
            printf("Max range of the numbers [0, max): ");
            scanf(" %ld", &max);
            insertRandonNumbers(&root, n, max);

        } else if (opt == 2) {
            printf("Value to search: ");
            scanf(" %ld", &val);
            
            Node* elem = search(root, val);
            if (elem == NULL) {
                printf ("%ld not found\n", val);
            
            } else {
                printf("%ld found\n", val);
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
            long int h = calcTreeHeight(root);
            printf("%ld, counting root,\n", h);
            printf("%ld, not counting.\n", h - 1);

        } else if (opt == 7) {
            long int n = countNumberOfNodes(root);
            printf("Number of nodes: %ld\n", n);

        } else if (opt == 9) {
            showMenu();
        
        } else if (opt == 0) {
            printf("Goodbye.\n");
            break;

        } else if (opt == 999) {
            printf("( ͡° ͜ʖ ͡°)\n");

        } else {
            printf("What did you said?\n");
        }
    }
    return 0;
}
