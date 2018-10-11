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

void insertVector(int *array, long int last, int val) {
   while (1) {
       if (last == 0 || array[last-1] < val) {
           array[last] = val;
           break;
       }
       array[last] = array[last-1];
       last--;
   }
}

int main () {

	long int i, length;
	int val;

	printf("Numero de elementos: ");
	scanf(" %li", &length);

	int array[length], a;

	for (i=0; i < length; i++) {
		a = (int)(rand() % 1000);
		insertVector(array, i, a);
	}

	for (i=0; i < length; i++) {
		printf(" %li", array[i]);
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
