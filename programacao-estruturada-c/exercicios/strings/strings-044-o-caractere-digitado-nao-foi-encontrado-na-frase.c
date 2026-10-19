#include <stdio.h>
#include <string.h>

int qtdvezes(char frase[101], char caractere) {

    int i, cont = 0;
    int tam = strlen(frase);

    for (i = 0; i < tam; i++) {
        if (frase[i] == caractere) {
            cont++;
        }

    }

    return cont;

}

int main() {

    char vet[101];
    char carac;
    int retorno;

    printf("Digite uma frase: ");
    fgets(vet, 101, stdin);
    printf("Digite um caractere: ");
    scanf("%c", &carac);
    fflush(stdin);
    retorno = qtdvezes(vet, carac);


    if (retorno == 0) {
        printf("O caractere digitado nao foi encontrado na frase digitada. \n\n");
    }
    else {
        printf("O caractere digitado foi encontrado %d vezes na frase digitada. \n\n", retorno);
    }
    

    return 0;
}

// Questão 2

