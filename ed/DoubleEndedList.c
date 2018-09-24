#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *previous;

} node;
 
////////// INSERTION

void insert(node **begin, node** current, int index, int val) { 
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
        (*current) -> next = (node*)malloc(sizeof(node));
        (*current) -> next -> value = val;
        (*current) -> next -> next = NULL;
        (*current) -> next -> previous = (*current);        
        (*current) = (*current) -> next;

    }
}

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

////////// OTHER

void delete(node **b, int i) {
    /*
     * Removes a element of a given index from the list.
     * */

    if (i == 0) {
        (*b) -> next -> previous = NULL;
        (*b) = (*b) -> next;

    } else {
        node *aux1;
        node *aux2;

        int c = 0;
        while (c < i-1) {
            (*b) = (*b) -> next;
            c++;
        }
    
        aux1 = (*b) -> next -> next;
        aux2 = (*b) -> next -> previous;

        (*b) -> next = aux1;
        (*b) -> next -> previous = aux2;
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

void print(node *b, char sep) {
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

int main() {

    node *begin = NULL;
    node *end = NULL;
    node *list = NULL;
    char sep = ' ';

    int val;
    while (scanf(" %d", &val) != EOF) {
        push_back(&list, &begin, val);
        //printf("%d\n", begin -> value);
    }

    end = list;
    list = begin;

    //update(begin, 5, 40);
    //delete(&list, 0);
    insert(&begin, &list, 0, 999);
    
    list = begin;
    
    print(begin, sep);
    printR(end, sep);
    //printf("%d\n", has(begin, 5));
    //printf("%d\n", has(begin, 50));
    clear(begin);

    return 0;
 
}
