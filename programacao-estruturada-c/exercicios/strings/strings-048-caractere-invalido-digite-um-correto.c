#include <stdio.h>
#include <string.h>
#include <ctype.h>

void altera(char frase[51], char letra) {

    int i, tam;
    tam = strlen(frase);

    for (i = 0; i < tam; i++) {
        if (tolower(frase[i]) == letra) {
            frase[i] = toupper(frase[i]);
        }
    }
}

int main () {

    char frase[51], caractere;

    printf("Digite uma frase: ");
    fgets(frase, 51, stdin);
    printf("Digite uma letra: ");
    scanf("%c", &caractere);
    getchar();
    
    while (isalpha(caractere) == 0) {
        printf("Caractere invalido! Digite um correto: ");
        scanf("%c", &caractere);
        getchar();
    }
    altera(frase, caractere);
    printf("Frase alterada: %s", frase);

    return 0;
}

// Questão 6

