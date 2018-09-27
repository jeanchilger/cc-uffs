#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *previous;

} node;

int length = 0;
 
////////// SEARCH

void at(node *b, int index) {
    /*
     * Returns the element at the given index.
     * */

    int c = 0;
    while (c < index) {
        b = b -> next;
        c++;
    }
    printf("%d\n", b -> value);
}

int find(node* b, int val) {
    /*
     * Returns the index of a given value in the list.
     * Returns -1 if value doesn't exists.
     * */

    int c = 0;
    
    while (b != NULL) {
        if (b -> value == val) return c;
        b = b -> next;
        c++;
    }

    return -1;
}

int has(node* b, int val) {     
    /*
     * Returns wether an element is in the list
     * */

    while (b != NULL) {
        if (b -> value == val) return 1;
        b = b -> next;
    }

    return 0;
}

////////// INSERTION

void insert(node** begin, node** current, int index, int val) { 
    /*
     * Inserts an element in a given index of the list.
     * */

    int c = 0;
    while (c < index) {
        c++;
        (*current) = (*current) -> next;
    }   
    
    node *new = (node*)malloc(sizeof(node));
    new -> value = val;

    new -> previous = (*current) -> previous;
    new -> next = (*current);

    if (!index) {
        (*current) -> previous = new;
        (*begin) = new;
    
    } else {
        (*current) -> previous -> next = new;
        (*current) -> next -> previous = new;
    }

    length++;

}

void push_back(node** current, node** begin, int val) {
    /*
     * Adds a new element at the end of the list.
     * */

    if (*begin == NULL) {
        (*current) = (node*)malloc(sizeof(node));
        (*current) -> value = val;
        (*current) -> next = NULL;
        (*current) -> previous = NULL;
        *begin = *current;


    } else {
        printf("C: %d\n", (*current)->value);
        (*current) -> next = (node*)malloc(sizeof(node));
        (*current) -> next -> value = val;
        (*current) -> next -> next = NULL;
        (*current) -> next -> previous = (*current);        
        (*current) = (*current) -> next;

    }

    length++;
}

void insertBefore(node** begin, node** current, int old, int newVal) {
    /*
     * Searches for an value and inserts a new element after that value
     * */
    
    printf("asdadasdasda");
    while ((*current) -> value != old) {
        (*current) = (*current) -> next;

    }
    
    printf("asd %d\n", (*current)->value);
     
    node* new = (node*)malloc(sizeof(node));
    new -> value = newVal;
    
    new -> previous = (*current) -> previous;
    new -> next = (*current);
                        
    (*current) -> previous -> next = new;
    (*current) -> next -> previous = new;

    length++;

}

////////// OTHER

void erase(node** b, int i) {
    /*
     * Removes a element of a given index from the list.
     * */

    if (length != 0) {
        if (i == 0) {
            node* aux = (*b);
            (*b) -> next -> previous = NULL;
            (*b) = (*b) -> next;
        
            free(aux);
    
        } else if (i == length-1) {
            printf("asdasdasd\n");
            node* aux = (*b);
            (*b) -> previous -> next = NULL;
            (*b) = (*b) -> previous;

            free(aux);
    
        } else {
            node* aux;
            node* aux1;
            node* aux2;
    
            int c = 0;
            while (c < i) {
                (*b) = (*b) -> next;
                c++;
            }
            aux = (*b);

            aux1 = (*b) -> next;
            aux2 = (*b) -> previous;

            // TODO add a shit for the last shit;
            (*b) -> next -> previous = aux2;
            (*b) -> previous -> next = aux1;

            free(aux);
        }

        length--;

    } else {
        printf("Lista Vazia!!\n");

    }
}

void clear(node* b) {
    /*
     * Erases the whole list.
     * */

    if (b == NULL) return;
    clear(b->next);
    free(b);

    length = 0;
}

void print(node* b, char sep) {
    /*
     * Prints all elements of the list, separated by sep.
     * Starts at the beginning;
     * */
    
    while (b -> next != NULL) {
        printf("%d%c ", b->value, sep);
        b = b -> next;
    }

    printf("%d\n", b->value);
}

void printR(node *e, char sep) {
    /*
     * Prints all elements of the list in reversed order, separated by sep.
     * */

    while (e -> previous != NULL) {
        printf("%d%c ", e -> value, sep);
        e = e -> previous;
    }
    printf("%d\n", e -> value);
}

void update(node *b, int val, int new) {
    /*
     * Updates a value from the list.
     * */

    while(b != NULL) {
        if (b -> value == val) {
            b -> value = new;
            return;
        }
        b = b -> next;
    }

    printf("Value wasn't found\n");
}

void showMenu() {
	printf("\n\t\tMENU\n");
    printf("===================================================\n");
    printf(" |\t0 - Sair                                 |\n");
    printf(" |\t1 - Inserir elemento (ao fim)            |\n");
    printf(" |\t2 - Inserir elemento depois de um valor  |\n");
    printf(" |\t3 - Imprimir elementos                   |\n");
    printf(" |\t4 - Imprimir em ordem inversa            |\n");
    printf(" |\t5 - Atualizar valor                      |\n");
    printf(" |\t6 - Buscar valor                         |\n");
    printf(" |\t7 - Excluir valor                        |\n");
    printf(" |\t8 - Limpar lista                         |\n");
    printf(" |\t9 - Mostrar menu novamente               |\n");
    printf("===================================================\n");
}

int main() {
            //TODO INSERIR ELEMENTO ANTES NOT WORKING

    node *begin = NULL;
    node *end = NULL;
    node *list = NULL;
    char sep = ' ';

    int val1, val2, opt;
    showMenu();

    while (1) {
        
        printf("\n>>> ");
        scanf(" %d", &opt);

        // EXIT
        if (opt == 0) {
        	break;

        // PUSH BACK
        } else if (opt == 1) {
            list = end;
        	printf("Valor a inserir: ");
        	scanf(" %d", &val1);
        	push_back(&list, &begin, val1);

            end = list;

        // INSERT BEFORE
        } else if (opt == 2) {
        	printf("Valor a inserir: ");
        	scanf(" %d", &val1);
        	printf("Elemento anterior: ");
        	scanf(" %d", &val2);
        	printf("asd\n\n");
            
            list = begin;
            insertBefore(&begin, &list, val2, val1);

        // PRINT
        } else if (opt == 3) {
	        print(begin, sep);

        // PRINT REVERSED
        } else if (opt == 4) {
	        printR(end, sep);

        // UPDATE VALUE
        } else if (opt == 5) {
        	printf("Valor antigo: ");
            scanf(" %d", &val1);
            printf("Valor novo: ");
            scanf(" %d", &val2);

            update(begin, val1, val2);

        // FIND VALUE
        } else if (opt == 6) {
            printf("Valor a ser buscado: ");
            scanf(" %d", &val1);

            if (has(begin, val1)) printf("Valor existe!\n");
            else printf ("Valor não encontrado!!!!\n");

        // DELETE ELEMENT
        } else if (opt == 7) {
            printf("Valor a excluir: ");
            scanf(" %d", &val1);

            list = begin;

            int index = find(begin, val1);
            erase(&list, index);

            if (index == length-1) end = list;

        // CLEAR LIST
        } else if (opt == 8) {
            clear(begin);
            free(end);
            free(list);

        } else if (opt == 9) {
            showMenu();

        } else if (opt = 999) {
            printf("(ಠ‿ಠ)\n");

        } else {
            printf("Sorry, I don't know what this means!\n");
        }

        printf("L: %d\n", length);
    }

    return 0; 
}
