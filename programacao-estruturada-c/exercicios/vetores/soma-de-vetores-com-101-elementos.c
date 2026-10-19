#include <stdio.h>

#define TAM 101

static int preencher(float vetor[TAM], const char *rotulo) {
    for (int i = 0; i < TAM; i++) {
        printf("%s, valor %d: ", rotulo, i + 1);
        if (scanf("%f", &vetor[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

static float somar(const float vetor[TAM]) {
    float soma = 0.0f;
    for (int i = 0; i < TAM; i++) {
        soma += vetor[i];
    }
    return soma;
}

int main(void) {
    float vetor_x[TAM];
    float vetor_y[TAM];

    if (!preencher(vetor_x, "Vetor X") || !preencher(vetor_y, "Vetor Y")) {
        return 1;
    }

    float soma_x = somar(vetor_x);
    float soma_y = somar(vetor_y);
    printf("Soma do vetor X: %.2f\n", soma_x);
    printf("Soma do vetor Y: %.2f\n", soma_y);
    printf("Soma dos dois vetores: %.2f\n", soma_x + soma_y);
    return 0;
}
