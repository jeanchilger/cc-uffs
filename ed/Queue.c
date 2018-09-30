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

void enqueue (node** tail, node** head, int val) {
    if ((*tail) == NULL) {
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
    printf("AAAA: %d", (*tail) -> value);
}

void dequeue (node** head) {
    if (empty ((*head))) {
        printf("ERROR: queue is empty, you cannot remove elements.\n");
        return;

    } else {
        node* aux = (*head);
        (*head) = (*head) -> next;

        free(aux);
    }
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

void showMenu () {
        printf(" \t\tMENU\n");
        printf(" |---------------------------------------|\n");
        printf(" | 1 - Inserir valor                     |\n");
        printf(" | 2 - Remover valor                     |\n");
        printf(" | 3 - Mostrar frente                    |\n");
        printf(" | 9 - Mostrar menu                      |\n");
        printf(" | 0 - Sair                              |\n");
        printf(" |---------------------------------------|\n");
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
            int elem = get_front (head);
            if (elem != -999) {
                printf("Elemento à frente é: %d.\n", elem);
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
