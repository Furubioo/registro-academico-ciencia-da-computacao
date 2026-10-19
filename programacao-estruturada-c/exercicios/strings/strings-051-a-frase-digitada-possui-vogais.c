#include <stdio.h>
#include <string.h>
#include <ctype.h>

int qtdvogais(char frase[]) {

    int i, tam = strlen(frase), cont = 0;

    for (i = 0; i < tam; i++) {
        if (isalpha(frase[i])) {
            frase[i] = tolower(frase[i]);
            if (frase[i] == 'a') {
                cont++;
            }
            if (frase[i] == 'e') {
                cont++;
            }
            if (frase[i] == 'i') {
                cont++;
            }
            if (frase[i] == 'o') {
                cont++;
            }
            if (frase[i] == 'u') {
                cont++;
            }
        }
    }

    return cont;

}

int main() {

    char frase[51];
    int valor;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    valor = qtdvogais(frase);
    printf("A frase digitada possui %d vogais. \n\n", valor);

    return 0;
}

// Questão 2

