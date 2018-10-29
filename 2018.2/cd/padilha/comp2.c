#include <stdio.h>

void sumOne(char * output, int length) {
    int i;
    int remain = 1;
    char curr;
    for (i = length-1; i >= 0; i--) {
        curr = output[i];

        output[i] = ((curr - '0') + remain > 1) ? '0' : ((curr - '0') + remain) + '0';
        remain = (int)((curr - '0') + remain > 1);
    }
}

void getComp(char * input, char * output, int length) {
    int i;
    for (i = 0; i < length; i++) {
        output[i] = (!(input[i] - '0') + '0');
    }

    sumOne(output, length);
}


int convert(char * input) {

    return 0;
}

int main() {

    char a[9];
    char r[9];

    while(scanf("%s", a) != EOF) {
        getComp(a, r, 8);
        printf("%s\n", r);

    }

    return 0;
}
