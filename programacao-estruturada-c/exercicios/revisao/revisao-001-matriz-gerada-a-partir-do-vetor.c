#include <stdio.h>

void preenchervet(int vet[]) {

    int i;

    for (i = 0; i < 10; i++) {
        printf("Informe o numero %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }
}

void preenchermat(int vet[], int mat[3][3]) {

    int i, j;
    int cont = 0;

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            mat[i][j] = vet[cont];
            cont++;
        }
    }

}

void exibir(int mat[][3]) {

    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }


}

int main() {

    int vetor[10], matriz[3][3];

    preenchervet(vetor);
    preenchermat(vetor, matriz);
    printf("\nMatriz gerada a partir do vetor: ");
    exibir(matriz);



    return 0;
}

// Prova 2 gq 2ª chamada

// 1a Questão:

