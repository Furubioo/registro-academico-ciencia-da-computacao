#include <stdio.h>

int main(void) {
    int matriz[10][15];
    int i;
    int j;
    long soma = 0;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 15; j++) {
            printf("matriz[%d][%d]: ", i, j);
            if (scanf("%d", &matriz[i][j]) != 1) {
                return 1;
            }
            soma += matriz[i][j];
        }
    }
    printf("Soma dos elementos: %ld\n", soma);
    return 0;
}
