#include <stdio.h>

void preencher(int mat[3][4]) {

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("Digite o elemento [%d][%d] da matriz: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void ctransposta(int m1[3][4], int m2[4][3]) {

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            m2[j][i] = m1[i][j];
        }
    }

}

void exibir(int mat[4][3]) {

    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int A[3][4], B[4][3];

    preencher(A);
    ctransposta(A,B);
    printf("Matriz transposta da matriz digitada: \n");
    exibir(B);

    return 0;
}

