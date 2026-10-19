#include <stdio.h>
#define l 3 
#define c 3

void preencher(int mat[l][c]) {

    int i, j;

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("Digite o elemento [%d][%d] da matriz: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

}

int qMagico(int mat[l][c]) {

    int i, j, cont = 0, magico = 0;
    int vet[4] = {0};

    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            if (i == 0) {
                vet[0] += mat[i][j];
            }
            if (j == 0) {
                vet[1] += mat[j][i];
            }
            if (i == j) {
                vet[2] += mat[i][j];
            }
            if (i + j == l-1) {
                vet[3] += mat[i][j];
            }
        }
    }

    for (i = 0; i < 4; i++) {
        if (vet[0] == vet[i]) {
            cont += 1;
        }
    }
    if (cont == 4) {
        magico = 1;
    }
    
    return magico;
    
}

int main() {

    int A[l][c], valor;

    preencher(A);
    valor = qMagico(A);
    if (valor == 1) {
        printf("\nA matriz digitada eh um quadrado magico. \n\n");
    }
    else {
        printf("\nA matriz digitada nao eh um quadrado magico. \n\n");
    }

    return 0;
}

