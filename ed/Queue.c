#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} node;

int empty (node* head) {
    /*
     * Returns wether the queue is empty or not.
     * */

    return (head == NULL);
}

int get_front (node* head) {
    /*
    * Returns the next value to be removed in the queue (the first).
    * If queue is empty, returns -999.
    * */

    if (empty(head)) {
        printf("ERROR: queue is empty, nothing to show.\n");
        return -999;
                               
    } else {
        return head -> value;
                      
    }
}


void enqueue (node** tail, node** head, int val) {
    /*
     * Adds a new value at the end of the queue.
     * */

    if (empty((*head))) {
        (*tail) = (node*)malloc(sizeof(node));
        (*tail) -> next = NULL;
        (*tail) -> value = val;
        (*head) = (*tail);

    } else {
        node* aux = (*tail);
        (*tail) = (node*)malloc(sizeof(node));
        (*tail) -> next = NULL;
        (*tail) -> value = val;
        aux -> next = (*tail);
    }
}

void dequeue (node** head) {
    /*
     * Removes the first value of the queue.
     * */

    if (empty ((*head))) {
        printf("ERROR: queue is empty, you cannot remove elements.\n");
        return;

    } else {
        printf("%d was removed.\n", get_front((*head)));
        node* aux = (*head);
        (*head) = (*head) -> next;

        free(aux);
    }
}

void showMenu () {
        printf(" \t\tMENU\n");
        printf(" |---------------------------------------|\n");
        printf(" | 1 - Inserir valor                     |\n");
        printf(" | 2 - Remover valor                     |\n");
        printf(" | 3 - Mostrar frente                    |\n");
        printf(" | 9 - Mostrar menu                      |\n");
        printf(" | 0 - Sair                              |\n");
        printf(" |---------------------------------------|\n");
        printf("\n");
}

int main () {

    node* head = NULL;
    node* tail = NULL;
    int val, opt;

    showMenu();
    while (1) {
        printf(">>> ");
        scanf(" %d", &opt);

        if (opt == 1) {
            printf("Valor a inserir: ");
            scanf(" %d", &val);
            enqueue(&tail, &head, val);

        } else if (opt == 2) {
            dequeue(&head);

        } else if (opt == 3) {
            if (!empty(head)) {
                printf("Elemento à frente é: %d.\n", get_front(head));
            }

        } else if (opt == 9) {
            showMenu();

        } else if (opt == 0) {
            printf("Goodbye.\n");
            break;

        } else {
            printf("What did you said???\n");
        }
    }

    return 0;
}
