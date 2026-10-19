#include <stdio.h>

int main(void) {
    int vetor[9];
    int matriz[3][3];
    int i;
    int j;

    for (i = 0; i < 9; i++) {
        printf("vetor[%d]: ", i);
        if (scanf("%d", &vetor[i]) != 1) {
            return 1;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz[i][j] = vetor[i * 3 + j];
        }
    }

    puts("Matriz 3x3:");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d", matriz[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
