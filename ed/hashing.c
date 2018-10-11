#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define OVERFLOW 10

int hashing(int key) {
    return key % SIZE;
}

void initArray(int *array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        array[i] = -1;
    }
}

void insert(int *array, int size, int overflow, int val) {
    int i;
    for (i = size; i < size+overflow; i++) {
        if (array[i] == -1) {
            array[i] = val;
            return;
        }
    }
    printf("NO MORE, I YIELD!\n");
    
}

void print(int *array, int length) {
    int i;
    for (i = 0; i < length; i++) {
        if (array[i] != -1) {
            printf(" %d", array[i]);
        }
    }
}

int main () {

    int size, overflow;
    size = 100;
    overflow = 10;
    
    /*printf("SIZE: ");
    scanf(" %d", &size);

    printf("OVERFLOW: ");
    scanf(" %d", &overflow);*/
    
    int array[size+overflow];
    initArray(array, size+overflow);

    int i, pos, n;
    for (i = 0; i < size+overflow; i++) {
        n = rand() % 1000;
        pos = hashing(n);
        if (array[pos] == -1) {
            array[pos] = n;
        
        } else {
            insert(array, size, overflow, n);

        }
    }    

    print(array, size+overflow);

    return 0;
}
