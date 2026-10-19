#include <stdio.h>

int main(void) {
    int matriz[2][3];

    printf("Digite os elementos da matriz 2x3:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            if (scanf("%d", &matriz[i][j]) != 1) {
                return 1;
            }
        }
    }

    printf("Matriz digitada:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
