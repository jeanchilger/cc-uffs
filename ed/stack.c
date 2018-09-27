#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* bottom;
} node;

// Commonly used

int empty(node* top);

//

void push (node** top, int val) {
    /*
     * Adds an element at the top of the stack.
     * */

    if (empty(*top)) {
        (*top) = (node*)malloc(sizeof(node));
        (*top) -> value = val;
        (*top) -> bottom = NULL;

    } else {
        node* aux = (*top);
        (*top) = (node*)malloc(sizeof(node));
        (*top) -> bottom = aux;
        (*top) -> value = val;
    }
}

void pop (node** top) {
    /*
     * Removes the first element at the top of the stack.
     * */

    if (!empty(*top)) {
        node* aux = (*top);
        (*top) = (*top) -> bottom;

        free(aux);

    } else {
        printf("ERROR: stack is empty, you cannot remove elements.\n");
    }
}

int get_top (node* top) {
    /*
     * Returns the value of the element at the top of the stack.
     * Return -999 if the stack is empty.
     * */

    if(!empty(top)) {
        return top -> value;

    } else {
        printf("ERROR: stack is empty, nothing to show.\n");
        return -999;
    }
}

int empty (node* top) {
    /*
     * Returns wether the stack is empty or not.
     * */

    if (top == NULL) return 1;
    else return 0;
}

void showMenu () {
    printf(" \t\tMENU\n");
    printf(" |---------------------------------------|\n");
    printf(" | 1 - Inserir valor                     |\n");
    printf(" | 2 - Remover valor                     |\n");
    printf(" | 3 - Mostrar topo                      |\n");
    printf(" | 9 - Mostrar menu                      |\n");
    printf(" | 0 - Sair                              |\n");
    printf(" |---------------------------------------|\n");
}

int main () {

    node* top = NULL;
    int opt, val;

    showMenu();
    while (1) {
        printf(">>> ");
        scanf(" %d", &opt);

        if (opt == 1) {
            printf("Inserir valor: ");
            scanf(" %d", &val);

            push(&top, val);

        } else if (opt == 2) {
            pop(&top);

        } else if (opt == 3){
            int target = get_top(top);
            if (target != -999) {
                printf("%d\n", target);
            }
        
        } else if (opt == 0) {
            printf("Goodbye.\n");
            break;

        } else {
            printf("What did you said???\n");
        }

    }

    return 0;
}
