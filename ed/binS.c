#include <stdio.h>
#include <stdlib.h>

int binSearch(int *array, long int val, int length) {

    int start = 0, end = length-1, mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (array[mid] == val) return mid;

        if (val > array[mid]) start = mid+1;
        else if (val < array[mid]) end = mid-1;
    }
   
    return -1;
}

void insert(int *array, int index, int value) {
    printf(" %d ", value);
    
    if (index == 0) array[0] = value;
    
    while (index > 0) {
        if (array[index-1] < value) break;
        else {
            array[index] = array[index-1];
        }

        index--;
    }

    array[index] = array[index-1];
    array[index] = value;
} 

int main () {

	long int i, length;
	int val;

	printf("Numero de elementos: ");
	scanf(" %li", &length);

	int array[length], a;

	for (i=0; i < length; i++) {
		a = (int)(rand() % 1000);
		insert(array, i, a);
	}
    printf("\n");

	for (i=0; i < length; i++) {
		printf(" %d", array[i]);
	}

	printf("\nValor pra procurar: ");
	scanf(" %d", &val);

	if (binSearch(array, val, length) != -1) {
		printf("Achô!\n");

	} else {
		printf("NAO\n");
	}

    return 0;
}
