#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *previous;

} node;

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

node* find(node* b, int val) {
    /*
     * Returns a pointer to a given value in the list.
     * */
    
    while (b != NULL) {
        if (b -> value == val) break;
        b = b -> next;
    }

    return b;
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
        (*current) -> next = (node*)malloc(sizeof(node));
        (*current) -> next -> value = val;
        (*current) -> next -> next = NULL;
        (*current) -> next -> previous = (*current);        
        (*current) = (*current) -> next;
    }
}

void insertBefore(node** begin, int val, int newVal) {
    /*
     * Searches for an value and inserts a new element before that value
     * */
    
    node* elem = find((*begin), val);
    if (elem != NULL) {
    
		node* new = (node*)malloc(sizeof(node));
		new -> value = newVal;
		
		if (elem -> previous == NULL) {
			new -> previous = NULL;
			new -> next = (*begin);
			(*begin) -> previous = new;
			(*begin) = new;
			
		} else {
			elem -> previous -> next = new;
			new -> previous = elem -> previous;
			elem -> previous = new;
			new -> next = elem;
		}
		
   	} else {
        printf("Lista vazia\n");
   	}
}

////////// OTHER

void erase(node** begin, node** end, node** elem) {
    /*
     * Removes a element from the list.
     * */

	if ((*begin) == (*end)) {
		node* aux = (*begin);
		(*begin) = NULL;
		(*end) = NULL;

		free(aux);

    } else {
        if ((*elem) -> previous == NULL) {
            node* aux = (*begin);
            (*begin) -> next -> previous = NULL;
            (*begin) = (*begin) -> next;
        
            free(aux);
    
        } else if ((*elem) -> next == NULL) {
            node* aux = (*end);
            (*end) -> previous -> next = NULL;
            (*end) = (*end) -> previous;

            free(aux);
    
        } else {
            node* aux;    
            
            aux = (*elem);

            (*elem) -> next -> previous = (*elem) -> previous;
            (*elem) -> previous -> next = (*elem) -> next;

            free(aux);
        }
    }
}

void clear(node* b) {
    /*
     * Erases the whole list.
     * */

    if (b == NULL) return;
    clear(b->next);
    free(b);
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

void update(node *b, int old, int new) {
    /*
     * Updates a value from the list.
     * */

    while(b != NULL) {
        if (b -> value == old) {
            b -> value = new;
            return;
        }
        b = b -> next;
    }

    printf("Valor nao encontrado\n");
}

void showMenu() {
	printf("\n\t\tMENU\n");
    printf("===================================================\n");
    printf(" |\t1 - Inserir elemento (ao fim)            |\n");
    printf(" |\t2 - Inserir elemento antes de um valor   |\n");
    printf(" |\t3 - Imprimir elementos                   |\n");
    printf(" |\t4 - Imprimir em ordem inversa            |\n");
    printf(" |\t5 - Atualizar valor                      |\n");
    printf(" |\t6 - Buscar valor                         |\n");
    printf(" |\t7 - Excluir valor                        |\n");
    printf(" |\t8 - Limpar lista                         |\n");
    printf(" |\t9 - Mostrar menu                         |\n");
    printf(" |\t0 - Sair                                 |\n");
    printf("===================================================\n");
}

int main() {

    node* begin = NULL;
    node* end = NULL;
    node* list = NULL;
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
        	printf("Elemento existente: ");
        	scanf(" %d", &val2);
            
            insertBefore(&begin, val2, val1);

    // PRINT
        } else if (opt == 3) {
        	if (begin != NULL) {
		        print(begin, sep);

		    } else {
		    	printf("Lista Vazia!!\n");
		    }

    // PRINT REVERSED
        } else if (opt == 4) {
	        if (end != NULL) {
		        printR(end, sep);

		    } else {
		    	printf("Lista Vazia!!\n");
		    }

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
            else printf ("Valor nao encontrado!\n");

    // DELETE ELEMENT
        } else if (opt == 7) {
            printf("Valor a excluir: ");
            scanf(" %d", &val1);

			node* elem = find(begin, val1);
			if (elem == NULL) {
				printf("Valor nao encontrado :(\n");
			} else {
            	erase(&begin, &end, &elem);
			}

    // CLEAR LIST
        } else if (opt == 8) {
            clear(begin);

            begin = end = list = NULL;
			printf("OK.\n");

	// SHOW MENU
        } else if (opt == 9) {
            showMenu();

        } else if (opt == 999) {
            printf("(^ _ ^)\n");

        } else {
            printf("What did you said?\n");
        }
    }

    return 0; 
}
