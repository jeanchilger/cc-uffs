#include <stdio.h>

struct tperson {
    char name [25];
    int age;
    float height;
    float weight;
};

void insert (struct tperson* people, int* index) {

    printf("Nome: ");
    scanf("%s", people[*index].name);
    printf("Idade: ");
    scanf("%d", &people[*index].age);
    printf("Altura: ");
    scanf("%f", &people[*index].height);
    printf("Peso: ");
    scanf("%f", &people[*index].weight);

    (*index) += 1;
}

void printAll (struct tperson* people, int index) {
    int i;
    for (i = 0; i < index; i++) {
        printf("-->  %s\n", people[i].name);
        printf("%d ano(s)\n", people[i].age);
        printf("%.2fm\n", people[i].height);
        printf("%.2fkg\n", people[i].weight);
        printf("----------------------\n");
    }

}

void delete (struct tperson* people, int index, int* maxSize) {
    int i;
    for (i = 0; i < (*maxSize)-1; i++) {
        if (i >= index) {
            people[i] = people[i+1];
        }
    }
    (*maxSize) -= 1;
}

int main () {
    int index = 0;
    int op;

    int maxP = 20;
    int deleteIndex;

    struct tperson people[maxP];

    printf("OLÁ!\n");
    printf("1 -> Nova pessoa;\n");
    printf("2 -> Mostrar tudo;\n");
    printf("3 -> Deletar pessoa;\n");
    printf("0 -> Sair;\n");

    while (1) {
        printf("\nOperação: ");
        scanf(" %d", &op);
        if (!op) {
            break;
        } else if (op == 1) {
            printf("\n%dº pessoa\n", index + 1);
            insert(people, &index);

        } else if (op == 3) {
            printf("\nPosição para deletar: ");
            scanf("%d", &deleteIndex);
            delete(people, deleteIndex, &index);

        } else {
            printAll(people, index);

        }
    }


    return 0;
}
