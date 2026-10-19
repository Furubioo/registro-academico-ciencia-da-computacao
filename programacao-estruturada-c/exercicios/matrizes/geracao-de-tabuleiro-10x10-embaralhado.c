#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

int main(void) {
    int tabuleiro[TAMANHO][TAMANHO];
    int valores[TAMANHO * TAMANHO];

    for (int i = 0; i < 50; i++) {
        valores[i] = 1;
        valores[i + 50] = 2;
    }

    srand((unsigned int)time(NULL));
    for (int i = TAMANHO * TAMANHO - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temporario = valores[i];
        valores[i] = valores[j];
        valores[j] = temporario;
    }

    for (int i = 0, posicao = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = valores[posicao++];
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
