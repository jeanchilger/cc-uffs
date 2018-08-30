#include <stdio.h>

void countdown(int n) {
    if (n == 0) {
        printf("\n");
        return;
    }
    printf("%d ", n);
    countdown(n-1);
}

void print(int n) {
    if (n == 0) {
        printf("");
        return;
    }
    print(n-1);
    printf("%d ", n);
}

int mult(int a, int b) {
    if (b == 0) {
        return 0;
    }

    return a + mult(a, b-1);
}

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }

    return a * power(a, b-1);
}

int div (int a, int b) {
    
}

int main () {

    // print(10);
    printf("%d\n", power(2, 4));
    // print2(10, 0);
    return 0;
}
