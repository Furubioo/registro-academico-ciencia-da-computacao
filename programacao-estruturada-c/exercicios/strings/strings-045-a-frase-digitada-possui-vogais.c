#include <stdio.h>
#include <string.h>
#include <ctype.h>

int qtdvezes(char vet[51]) {

    int i, cont = 0;
    int tam = strlen(vet);

    for (i = 0; i < tam; i++) {
        vet[i] = tolower(vet[i]);
        if (vet[i] == 'a' || vet[i] == 'e' || vet[i] == 'i' || vet[i] == 'o' || vet[i] == 'u') {
            cont++;
        }

    }

    return cont;
}

int main() {

    char frase[51];
    int retorno;

    printf("Digite uma frase: ");
    fgets(frase, 51, stdin);

    retorno = qtdvezes(frase);
    printf("A frase digitada possui %d vogais.", retorno);

    return 0;
}

// Questão 3

