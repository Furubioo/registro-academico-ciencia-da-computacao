#include <stdio.h>

void preencher(int mat[5][5]) {

    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("Informe o valor do elemento [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

}

int simetria(int mat[5][5]) {

    int i, j;
    int simetrico = 0;
    int cont = 0;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (mat[i][j] == mat[j][i]) {
                cont+=1;
            }
        }
    }
    if (cont == i * j) {
        simetrico = 1;
    }

    return simetrico;

}

int main() {

    int A[5][5], valor;

    printf("Prennchimento da matriz A: \n\n");
    preencher(A);
    valor = simetria(A);
    if (valor == 1) {
        printf("\nA matriz digitada eh simetrica. \n\n");
    }
    else {
        printf("\nA matriz digitada nao eh simetrica. \n\n");
    }

    return 0;
}

