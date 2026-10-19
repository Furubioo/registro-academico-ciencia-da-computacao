#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verifica(char nome[101]) {

    int i, j, tam;
    int cont1 = 0, cont2 = 0, cont3 = 0;
    int valido = 0;

    tam = strlen(nome);

    for (i = 0; i < tam; i++) {
        if (isalpha(nome[i])) {
            cont1++;
        }
        if (isspace(nome[i]) && nome[i] != '\n') {
            cont2++;
        }

    }
    for (j = 0; j < tam - 1; j++) {
        cont3++;
    }
    if (cont1 + cont2 == cont3) {
        valido = 1;
    }

    return valido;

}

int main() {

    char nome[101]; 
    int validacao;

    printf("Digite o seu nome: ");
    fgets(nome, 101, stdin);


    validacao  = verifica(nome);
    while (validacao != 1) {
        printf("Nome invalido. Digite novamente: ");
        fgets(nome, 101, stdin);
        validacao  = verifica(nome);

    }
    printf("\nOla, %sprazer em te conhecer! \n\n", nome);



    return 0;
}

// Lista 2 de Strings

// Questão 1

