#include <stdio.h>

void preencher(int mat[4][4]) {

    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Digite o valor do elemento [%d][%d]: ", i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int matperm(int mat[4][4]) {

    int i, j;
    int perm = 0;
    int cont = 0, cont1 = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (mat[i][j] == 0) {
                cont++;
            }
            if (mat[i][j] == 1) {
                cont1++;
            }
        }
    }
    if (cont == (i*j)-4 && cont1 == i) {
        perm = 1;
    }

    return perm;

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

int main() {

    int A[4][4], valor;

    preencher(A);
    valor = matperm(A);
    exibir(A);
    if (valor == 1) {
        printf("Esta matriz eh de permutacao. \n\n");
    }
    else {
        printf("Esta matriz nao eh de permutacao. \n\n");
    }

    return 0;
}

