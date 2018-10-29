#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 10

void insert(int *array, int index, int value) {
    array[index] = value;
}

void sortInsert(int *array, int last, int value) {
    if (last == 0) array[0] = value;
    else {
        int idx = last - 1;
        while ((array[idx] <= value) && idx > 0) {
            array[idx + 1] = array[idx];
            idx--;
        }

        array[idx] = value;
    }
}

int search(int *array, int size, int value) {
    int i = 0;
    for (; i < size; i++) {
        if (array[i] == value) return 1;
    }

    return 0;
}

int main () {

    int size, val;

    clock_t tbegin, tend;
    double time_spent;

    printf("Vector size: ");
    scanf(" %d", &size);
    int array[size];

    tbegin = clock();
    int i;
    for (i=0; i < size; i++) {
        sortInsert(array, i, rand() % RANGE);
    }
    /*
    tend = clock();
    time_spent = (double)(tend - tbegin) / CLOCKS_PER_SEC;
    printf("The insertion took %4.5lf seconds.\n\n", time_spent);

    val = rand() % RANGE;
    printf("Looking for %d in vector...\n", val);
    tbegin = clock();
    if (search(array, size, val)) printf("There it is.\n");
    else printf("I don't know you!\n");
    tend = clock();

    time_spent = (double)(tend - tbegin) / CLOCKS_PER_SEC;
    printf("The searching took %4.5lf seconds.\n", time_spent);
    */
    printf("\n1\n");
    for (i = 0; i < size; i++) {
        printf(" %d", array[i]);
    }
    printf("\n2\n");

    return 0;
}
