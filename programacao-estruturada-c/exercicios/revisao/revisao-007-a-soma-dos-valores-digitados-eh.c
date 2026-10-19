#include <stdio.h>

int soma(int *vet, int n) {

    int x, i;

    for (i = 0; i < n; i++) {
        x += vet[i];
    }

    return x;

}

int main() {

    int vetor[5], cont = 0, i, vsoma;

    for (i = 0; i < 5; i++) {
        printf("Digite o valor [%d]: ", i);
        scanf("%d", &vetor[i]);
        cont++;
    }
    vsoma = soma(vetor, cont);
    printf("A soma dos valores digitados eh %d", vsoma);


    return 0;
}

