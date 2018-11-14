#include <stdio.h>

int main() {

    int n, var, i;
    scanf(" %d", &n);

    int l[n];
    for (i = 0; i < n; i++) {
        scanf(" %d", &l[i]);
    }

    var = -999;
    for (i = n-1; i >= 0; i--) {
        if (l[i] > var) {
            var = l[i];
            printf("%d ", var);
        }
    }
    printf("\n");

    return 0;
}
