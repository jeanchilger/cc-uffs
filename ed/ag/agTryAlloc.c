#include <stdio.h>
#include <stdlib.h>

struct tperson {
    char name [25];
    int age;
    float height;
    float weight;
};

unsigned long memoryBasis = sizeof(struct tperson);
int memoryBound =  sizeof(struct tperson) * 2;


void insert (struct tperson* people, int* index) {

    //shitty code 2
    if (sizeof(people) >= memoryBound) {
        printf("booooooooooooooooooo\n");
        people = (struct tperson*) realloc(people, memoryBound+(memoryBasis*20));
        memoryBound = sizeof(people);

    }

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
    for (int i = 0; i < index; i++) {
        printf("--> %dº\n", i+1);
        printf("+ %s\n", people[i].name);
        printf("%d ano(s)\n", people[i].age);
        printf("%.2fm\n", people[i].height);
        printf("%.2fkg\n", people[i].weight);
        printf("----------------------\n");
    }

}

int main () {
    int index = 0;
    int op;
    struct tperson * people;

    // shitty code
    people = (struct tperson*) malloc(memoryBound);

    // Main menu
    printf("OLÁ!\n");
    printf("1 -> Nova pessoa;\n");
    printf("2 -> Mostrar tudo;\n");
    printf("0 -> Sair;\n");

    while (1) {
        printf("\nOperação: ");
        scanf(" %d", &op);
        if (!op) {
            break;

        } else if (op == 1) {
            printf("\n%dº pessoa\n", index + 1);
            insert(people, &index);

        } else {
            printAll(people, index);

        }
    }

    free(people);


    return 0;
}
