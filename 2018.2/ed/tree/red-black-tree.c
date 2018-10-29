#include <stdlib.h>
#include <stdio.h>

typedef struct TNode {
    struct TNode *left;
    struct TNode *right;
    struct TNode *parent;
    int value;
    int color; // 0 - BLACK / 1 - RED
} Node;

int getColor(Node *root);

int main() {


    return 0;
}
