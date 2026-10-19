#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 1000000

int main(void) {
    int *valores = malloc(TAMANHO * sizeof *valores);
    size_t i;
    long long soma = 0;

    if (valores == NULL) {
        puts("Nao foi possivel alocar o vetor.");
        return 1;
    }

    for (i = 0; i < TAMANHO; i++) {
        valores[i] = (int)(i % 100);
        soma += valores[i];
    }

    printf("Vetor de %d elementos criado. Soma: %lld\n", TAMANHO, soma);
    free(valores);
    return 0;
}
