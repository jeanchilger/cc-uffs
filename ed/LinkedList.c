#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;

} node;

void push_back(node** current, node** begin, int val) {
    /*
     * Adds a new element at the end of the list.
     * */

    if (*begin == NULL) {
        (*current) = (node*)malloc(sizeof(node));
        (*current) -> value = val;
        (*current) -> next = NULL;
        *begin = *current;


    } else {
        //printf("%p\n", *current);
        (*current) -> next = (node*)malloc(sizeof(node));
        (*current) -> next -> value = val;
        (*current) -> next -> next = NULL;
        (*current) = (*current) -> next;

    }
}

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
     * Returns wether an element is in the list
     * */

    while (b != NULL) {
        if (b -> value == val) return 1;
        b = b -> next;
    }

    return 0;
} 

void print(node *b) {
    /*
     * Prints all elements of the list.
     * */
    
    while (b != NULL) {
        printf("%d, ", b->value);
        b = b -> next;
    }

    printf("\n");

}

void clear(node* b) {
    if (b == NULL) return;
    clear(b->next);
    free(b);
}

int main() {

    node *begin = NULL;
    node *list = NULL;

    int val;
    while (scanf(" %d", &val) != EOF) {
        push_back(&list, &begin, val);
        //printf("%d\n", begin -> value);
        
    }

    list = begin;

    print(begin);
    printf("%d\n", find(begin, 5));
    printf("%d\n", find(begin, 50));
    clear(begin);

    return 0;
}
