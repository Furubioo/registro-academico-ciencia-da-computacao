#include <stdio.h>

void preencher(float mat[3][4]) {

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("Digite o valor do elemento [%d][%d]: ", i, j);
            scanf("%f", &mat[i][j]);
        }
        
    }

}

void soma(float matA[3][4], float matB[3][4], float matC[3][4]) {

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            matC[i][j] = matA[i][j] + matB[i][j];
        }
    }

}

void exibir(float mat[3][4]) {

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }

}


int main() {

    float matA[3][4], matB[3][4], matC[3][4];

    printf("Preenchimento da matriz A: \n");
    preencher(matA);
    printf("\nPreenchimento da matriz B: \n");
    preencher(matB);
    soma(matA, matB, matC);

    printf("Matriz A: \n");
    exibir(matA);
    printf("\nMatriz B: \n");
    exibir(matB);
    printf("\nMatriz C(soma): \n");
    exibir(matC);

    return 0;
}

