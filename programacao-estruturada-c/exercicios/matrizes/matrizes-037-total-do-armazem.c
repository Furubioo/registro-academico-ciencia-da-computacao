#include <stdio.h>
#define l 20
#define c 100

void preencher(int mat[l][c]) {

    int i, j;

    for (j = 0; j < c; j++) {
        for (i = 0; i < l; i++) {
            printf("Informe a qtd estocada do produto %d no armazem %d: ", j, i);
            scanf("%d", &mat[i][j]);
        }
    }
}

void tArmazem(int mat[l][c], int vet[]) {

    int i, j;

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            vet[i] += mat[i][j]; 
        }
    }
}

void tEstocados(int mat[l][c], int vet[]) {

    int i, j;

    for (j = 0; j < c; j++) {
        for (i = 0; i < l; i++) {
            vet[j] += mat[i][j];
        }
    }
}

int main() {

    int A[l][c], totalPorArmazem[l] = {0}, totalPorProduto[c] = {0};
    int i, j;

    printf("Preenchimento da qtd. por armazem: \n");
    preencher(A);
    tArmazem(A, totalPorArmazem);
    tEstocados(A, totalPorProduto);

    for (i = 0; i < l; i++) {
        printf("\nTotal do armazem %d: %d \n", i, totalPorArmazem[i]);
    }
    for (j = 0; j < c; j++) {
        printf("\nTotal do produto %d: %d \n", j, totalPorProduto[j]);
    }
    printf("\n");

    return 0;
}

