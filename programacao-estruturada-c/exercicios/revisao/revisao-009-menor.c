#include <stdio.h>

int main() {

    int i, menor = 0, vetor[5];

    for (i = 0; i < 5; i++) {
        printf("Digite o valor [%d]: ", i);
        scanf("%d", &vetor[i]);

        if (i == 0) {
            menor = vetor[0];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    printf("Menor: %d \n", menor);

    return 0;
}

