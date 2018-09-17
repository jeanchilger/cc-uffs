#include <stdio.h>

void t(int*p) {
    int a = 56;
    printf("%p\n", p);
    printf("Bjarne Stroustrup\n");
    p = &a;
}

int main() {

    int b = 1;
    t(&b);

    printf("%d\n", b);

    return 0;
}
