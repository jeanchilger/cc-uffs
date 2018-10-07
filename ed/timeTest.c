#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node *next;
} node;

void insert(node **begin, node **list, int val) {
    if ((*begin) == NULL) {
        (*begin) = (node*)malloc(sizeof(node));
        (*begin) -> value = val;
        (*begin) -> next = NULL;

    } else {
        (*current) -> next = (node*)malloc(sizeof(node));
        (*current) -> next -> value = val;
        (*current) -> next -> next = NULL;
        (*current) = (*current) -> next;
    }
}

void showMenu() {
    printf("\n\t\t  MENU\n");
    printf("================================================\n");
    printf(" | 1 - Insert element                         |\n");
    printf(" | 2 - Search value                           |\n");
    printf(" | 3 - Clean list                             |\n");
    printf(" | 9 - Show menu                              |\n");
    printf(" | 0 - Exit                                   |\n");
    printf("================================================\n");                                                       
}


int main() {
    
    int val, opt;
    node *begin = NULL;
    node *list = NULL;

    while (1) {
        printf(">>> ");
        scanf(" %d", &opt);

        if (opt == 1) {
            printf("Value to insert: ");
            scanf(" %d", &val);
            insert(&begin, val);

        } else if (opt == 2) {

        } else if (opt == 3) {

        } else if (opt == 9) {
            showMenu();

        } else if (opt == 0) {
            printf("Goodbye.\n");
            break;

        } else {
            printf("What did you say?\n");
        }
    }

    return 0;
}

