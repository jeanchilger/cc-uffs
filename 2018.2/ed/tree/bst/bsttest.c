#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main() {

    Node* begin = NULL;
    Node* end = NULL;
    Node* root = NULL;
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
            
            Node* elem = search(root, val);
            if (elem == NULL) {
                printf ("%d not found\n", val);
            
            } else {
                printf("%d found\n", val);
            }

        } else if (opt == 3) {
            /*printf("Crescente (1)\\decrescente (2): ");
            scanf(" %d", &val);
            if (val == 1) {*/
            
            printInOrder(root);

            /*} else {
                printD(root);
            }*/
        
        /*} else if (opt == 4) {*/
        
        } else if (opt == 5) {
            clear(root);
            root = NULL;
        
        } else if (opt == 6) {
            int h = treeHeight(root);
            printf("%d, with root,\n", h);
            printf("%d, without.\n", h - 1);

        } else if (opt == 7) {
            int n = countNodes(root);
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
