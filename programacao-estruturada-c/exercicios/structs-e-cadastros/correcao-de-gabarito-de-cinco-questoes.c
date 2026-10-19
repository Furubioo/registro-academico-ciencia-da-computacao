#include <ctype.h>
#include <stdio.h>

#define TAM 5

static int preencher(char vetor[TAM], const char *rotulo) {
    for (int i = 0; i < TAM; i++) {
        printf("%s da questao %d: ", rotulo, i + 1);
        if (scanf(" %c", &vetor[i]) != 1) {
            return 0;
        }
        vetor[i] = (char)tolower((unsigned char)vetor[i]);
    }
    return 1;
}

int main(void) {
    char gabarito[TAM];
    char respostas[TAM];
    int acertos = 0;

    if (!preencher(gabarito, "Gabarito") || !preencher(respostas, "Resposta")) {
        return 1;
    }
    for (int i = 0; i < TAM; i++) {
        acertos += gabarito[i] == respostas[i];
    }
    printf("Quantidade de acertos: %d\n", acertos);
    return 0;
}
