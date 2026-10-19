#include <stdio.h>
#include <string.h>
#include <ctype.h>

void criptografa(char frase[81]) {

    int i, tam;
    tam = strlen(frase);
    
    for (i = 0; i < tam; i++) {
        frase[i] = tolower(frase[i]);
        if (frase[i] == 'a') {
            frase[i] = '@';
        }
        if (frase[i] == 'e') {
            frase[i] = '$';
        }
        if (frase[i] == 'i') {
            frase[i] = '&';
        }
        if (frase[i] == 'o') {
            frase[i] = '#';
        }
        if (frase[i] == 'u') {
            frase[i] = '%';
        }

    }

}

int main() {

    char frase[81];

    printf("Digite uma frase: ");
    fgets(frase, 81, stdin);

    criptografa(frase);

    printf("Frase criptografada: %s \n", frase);

    return 0;
}

// Questão 4

