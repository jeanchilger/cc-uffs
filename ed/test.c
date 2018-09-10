#include <stdio.h>
#include <stdlib.h>

typedef struct tlist {
    int value;
    struct tlist* next;
} list;

void append(int val, list* st) {
    st -> value = val;
    st -> next = (list*)malloc(sizeof(list));
    st -> next = NULL;

}

void append2(int val, list* st) {
    printf("adsadsad\n");
    if (st == NULL) { 

    
    } else { // For the first element
        st -> value = val;
        st -> next = NULL;
    }
}

void get(int i, list*st) {
    int c = 0;
    
    while (c < i) {
        st = st -> next;
        c++;
    }

    printf("%d\n", st -> value);
}

void printAll(list* st) {
    while (st != NULL) {
        printf("%d ", st -> value);
        st = st -> next;
    }

    printf("\n");
}

void deleteList(list* st) {
    if (st == NULL) return;
    deleteList(st -> next);
    free(st);
}

int main () {

    list* mylist = (list*)malloc(sizeof(list));
    list* first = mylist;
    int val;

    while (scanf(" %d", &val) != EOF) {
        append(val, mylist);
        mylist = mylist -> next;
    }

    mylist = first;
    printAll(mylist);
    // get(5, mylist);
    deleteList(first);

    return 0;
}
