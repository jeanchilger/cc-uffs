#include <stdio.h>

int negate(char * a, char * r) {
    printf("a");
    int i;
    for (i = 0; i < 8; i++) {
        r[i] = (char)(!(a[i] - '0'));
    }
    printf("%s", r);
}

int main() {
    
    char a[9];
    char r[9];

    scanf("%s", a);
    printf("%s", a);
    negate(a, r);
    

    printf("%s", r);

    return 0;
}
