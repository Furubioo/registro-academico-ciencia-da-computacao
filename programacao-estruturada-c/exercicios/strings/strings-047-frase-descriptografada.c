#include <stdio.h>
#include <string.h>
#include <ctype.h>

void descriptografa(char frase[81]) {

    int i, tam;
    tam = strlen(frase);

    for (i = 0; i < tam; i++) {
        frase[i] = tolower(frase[i]);
        if (frase[i] == '@') {
            frase[i] = 'a';
        }
        if (frase[i] == '$') {
            frase[i] = 'e';
        }
        if (frase[i] == '&') {
            frase[i] = 'i';
        }
        if (frase[i] == '#') {
            frase[i] = 'o';
        }
        if (frase[i] == '%') {
            frase[i] = 'u';
        }
    }

}

int main() {

    char frase[81];

    printf("Digite uma frase(criptografada): ");
    fgets(frase, 81, stdin);
    descriptografa(frase);
    printf("Frase descriptografada: %s", frase);

    return 0;
}

// Questão 5

