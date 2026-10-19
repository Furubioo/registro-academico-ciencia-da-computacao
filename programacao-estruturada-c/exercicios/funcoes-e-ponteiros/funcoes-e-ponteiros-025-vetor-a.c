#include <stdio.h>

void preencher(int vet[5]);
void exibirvet(int vet[5]);
void somarAeB(int vetA[5], int vetB[5], int vetC[5]);


int main() {

    int vetA[5], vetB[5], vetC[5];

    printf("Vetor A: \n\n");
    preencher(vetA);
    printf("Vetor B: \n\n");
    preencher(vetB);

    printf("Vetor A: \n\n");
    exibirvet(vetA);
    printf("Vetor B: \n\n");
    exibirvet(vetB);
    
    somarAeB(vetA, vetB, vetC);
    printf("Vetor soma/resultante: \n\n");
    exibirvet(vetC);

    return 0;
}

void preencher(int vet[5]) {

    int i;

    for (i = 0; i <= 4; i++) {
        printf("Digite o que estara no indice %d: ", i);
        scanf("%d", &vet[i]);
    }
    printf("\n");

}

void exibirvet(int vet[5]) {

    int i;

    for (i = 0; i <= 4; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n\n");

}

void somarAeB(int vetA[5], int vetB[5], int vetC[5]) {

    int i;

    for (i = 0; i <= 4; i++) {

        vetC[i] = vetA[i] + vetB[i];
    }

}

#define tam 101
