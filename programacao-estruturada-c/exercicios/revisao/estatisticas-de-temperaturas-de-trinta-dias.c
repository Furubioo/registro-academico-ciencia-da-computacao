#include <stdio.h>

int main(void) {
    float temperaturas[30];
    int i;
    float maior;
    float menor;
    float soma = 0.0f;

    for (i = 0; i < 30; i++) {
        printf("Temperatura do dia %d: ", i + 1);
        if (scanf("%f", &temperaturas[i]) != 1) {
            return 1;
        }
        soma += temperaturas[i];
    }
    maior = temperaturas[0];
    menor = temperaturas[0];
    for (i = 1; i < 30; i++) {
        if (temperaturas[i] > maior) {
            maior = temperaturas[i];
        }
        if (temperaturas[i] < menor) {
            menor = temperaturas[i];
        }
    }
    printf("Media: %.2f | Menor: %.2f | Maior: %.2f\n", soma / 30.0f,
           menor, maior);
    return 0;
}
