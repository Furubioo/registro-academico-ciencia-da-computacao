#include <stdio.h>

void preencher(int mat[4][4]) {

    int i, j;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            printf("Digite o elemento [%d][%d] da matriz: ",i,j);
            scanf("%d", &mat[i][j]);
        }
    }

}

int somaD(int mat[4][4]) {

   int i, j, soma = 0; 

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == 0 && j > 0) {
                soma += mat[i][j];
            }
            if (i == 1 && j > 1) {
                soma += mat[i][j];
            }
            if (i == 2 && j == 3) {
                soma += mat[i][j];
            }
        }
    }
    return soma;
}

int main() {

    int A[4][4], valor;

    printf("Preenchimento da matriz: \n");
    preencher(A);
    valor = somaD(A);
    printf("Soma dos elementos situados acima da diagonal principal: %d \n\n", valor);

    return 0;
}

