#include <stdio.h>
#include <string.h>
#include <ctype.h>

void conta(char frase[101]) {

    int i, tam;
    tam = strlen(frase);
    int contl = 0, contN = 0, contE = 0, contS = 0;

    for (i = 0; i < tam; i++) {
        frase[i] = tolower(frase[i]);
        if (isalpha(frase[i])) {
            contl++;
        }
        if (isdigit(frase[i])) {
            contN++;
        }
        if (isspace(frase[i]) && frase[i] != '\n') {
            contE++;
        }
        char c = frase[i];
        if (!isalpha(c) && !isdigit(c) && !isspace(c)) {
            contS++;
        }
    }
    printf("Existem %d letras na frase digitada. \nExistem %d digitos numericos na frase digitada. \nExistem %d espacos na frase digitada. \nExistem %d simbolos na frase digitada.", contl, contN, contE, contS);
}

int main() {

    char frase[101];

    printf("Digite uma frase: ");
    fgets(frase, 101, stdin);
    conta(frase);

    return 0;
}

// Questão 7

