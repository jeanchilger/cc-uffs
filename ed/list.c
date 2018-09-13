#include <stdio.h>
#include <stdlib.h>

typedef struct tlist {
    int value;
    struct tlist* next;
} list;

void push_back(int val, list* st) {
    st -> value = val;
    st -> next = (list*)malloc(sizeof(list));
    st -> next -> next = NULL;

}

void get(int i, list* st) {
    int c = 0;
    
    while (c < i) {
        st = st -> next;
        c++;
    }

    printf("%d\n", st -> value);
}

void del(int i, list* st) {
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
    while (st -> next != NULL) {
        printf("%d ", st -> value);
        st = st -> next;
    }

    printf("\n");
}

void clear(list* st) {
    if (st == NULL) return;
    clear(st -> next);
    free(st);
}

int main () {

    list* mylist = (list*)malloc(sizeof(list));
    list* first = mylist;
    int val;

    while (scanf(" %d", &val) != EOF) {
        push_back(val, mylist);
        mylist = mylist -> next;
    }

    mylist = first;

    printAll(mylist);
    //del(5, mylist);
    printAll(mylist);

    clear(first);

    return 0;
}
