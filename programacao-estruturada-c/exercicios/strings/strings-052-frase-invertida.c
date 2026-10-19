#include <stdio.h>
#include <string.h>
#include <ctype.h>

void inverter(char frase[]) {

    int i, tam = strlen(frase);
    int tam1 = tam-1;
    char contrario[101];

    for (i = 0; i < tam; i++) {
        contrario[i] = frase[tam1];
        tam1--;
    }
    for (i = 0; i < tam; i++) {
        frase[i] = contrario[i];
    }

}

void leiturasegura(char frase[]) {

    int i, tam = strlen(frase);

    for (i = 0; i < tam; i++) {
        if (frase[i] == '\n') {
            frase[i] = '\0';
        }
    }

}

int main() {

    char frase[101];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    leiturasegura(frase);
    inverter(frase);
    printf("Frase invertida: \n");
    printf("%s \n\n", frase);


    return 0;
}

// Questão 3

