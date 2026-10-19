#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, j, elementos[2][2], elementos1[2][2], somaelementos[2][2];

    printf("Digite a sua primeira matriz: \n\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Elemento [%d] [%d]: ", i, j);
            scanf("%d", &elementos[i][j]);
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d", elementos[i][j]);
        }
        printf("\n");
    }
    printf("Essa eh a sua primeira matriz 2x2. \n\n");

    printf("Digite a sua segunda matriz 2x2: \n\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("Elemento [%d] [%d]: ", i, j);
            scanf("%d", &elementos1[i][j]);
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d", elementos1[i][j]);
        }
        printf("\n");
    }

    printf("Essa eh a sua segunda matriz 2x2. \n\n");

    printf("A soma das matrizes eh:\n");

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            somaelementos[i][j] = elementos[i][j] + elementos1[i][j];         
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d", somaelementos[i][j]);
        }
        printf("\n");
    }
return 0;
}

