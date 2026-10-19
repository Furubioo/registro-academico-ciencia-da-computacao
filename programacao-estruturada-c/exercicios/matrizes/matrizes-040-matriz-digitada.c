#include <stdio.h>

void preencher(int mat[4][4]) {

    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Digite o elemento [%d][%d] da matriz: ",i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void exibir(int mat[4][4]) {

    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

}

void divisao(int mat[4][4]) {

    int i, j;
    int a = mat[0][0], b = mat[1][1], c = mat[2][2], d = mat[3][3];

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == 0) {
                mat[i][j] = mat[i][j] / a;
            }
            if (i == 1) {
                mat[i][j] = mat[i][j] / b;
            }
            if (i == 2) {
                mat[i][j] = mat[i][j] / c;
            }
            if (i == 3) {
                mat[i][j] = mat[i][j] / d;
            }
        }
    }

}

int main() {

    int A[4][4];

    printf("Preenchimento da matriz: \n");
    preencher(A);
    printf("\nMatriz digitada: \n");
    exibir(A);
    divisao(A);
    printf("\nMatriz apos a divisao: \n");
    exibir(A);

    return 0;
}

