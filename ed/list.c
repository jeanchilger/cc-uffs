#include <stdio.h>
#include <stdlib.h>

typedef struct tlist {
    int value;
    struct tlist* next;
} list;

int length = 0;
list *begin;

void push_back(int val, list* st) {
    /*
     * Adds a new element at the end of the list.
    */

    if (st == NULL) {

        st = (list*)malloc(sizeof(list));
        st -> value = val;
        st -> next = NULL;

        if (length == 0) {
            begin = st;
    
        }
    
    } else {
        printf("SSASSS\n");
    }

    length++;
}

void get(int i, list* st) {
    /*
     * Prints the i-th element of the list.
    */

    int c = 0;
    
    while (c < i) {
        st = st -> next;
        c++;
    }

    printf("%d\n", st -> value);
}

void del(int i, list* st) {
    // TODO BUGADO
    int c = 0;
    while (c < i-1) {
        st = st -> next;
        c++;
    }

    if (st -> next != NULL) {
        st -> next = st -> next -> next;
    } 
}

void printAll(list* st) {
    /*
     * Prints all elements within the list.
    */
    int i = 0;
    while (st != NULL) {
        printf("[%d] %d ", i, st -> value);
        st = st -> next;
        i++;
    }

    printf("\n");
}

void clear(list* st) {
    if (st == NULL) return;
    clear(st -> next);
    free(st);
}

int main () {

    list* mylist = NULL;

    int val;

    //printf("%p\n", mylist);
    while (scanf(" %d", &val) != EOF) {
        push_back(val, mylist);
        printf("AAAAAAAAAAAAAAAAAA %d \n", mylist -> value);
        mylist = mylist -> next;
       
    }

    mylist = begin;
    printAll(mylist);

    return 0;
}
