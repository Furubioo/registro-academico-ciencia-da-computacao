#include <stdio.h>
#include <string.h>
#include <ctype.h>


void leituraS(char nome[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
        }
    }

}

int verifica(char codigo[]) {

    int i, j;
    int contT = 0, contL = 0, contN = 0, contM = 0, cont5 = 0;
    

    if (strlen(codigo) < 10) {
        return 0;
    }

    if (strlen(codigo) == 10) {
        contT++;
    }


    for (i = 0; i < 5; i++) {
        if (isalpha(codigo[i])) {
            contL++;
        }
    }

    for (j = 5; j < 11; j++) {
        if (isdigit(codigo[j])) {
            contN++;
        }
    }
    

    if (isupper(codigo[0])) {
        contM++;
    }

    if (codigo[5] == '0') {
        cont5++;
    }

    if (contT == 1 &&  contL == 5 && contN == 6 && contM == 1 && cont5 == 1) {
        return 1;
    }

    return 0;
}

int main() {

    char codigo[11], nome[51], funcao[51];
    int a;

    printf("Digite o seu nome: ");
    fgets(nome, 51, stdin);
    leituraS(nome, 51);
    
    printf("Digite sua funcao: ");
    fgets(funcao, 51, stdin);
    leituraS(funcao, 51);
    
    printf("Informe o seu codigo: ");
    fgets(codigo, 11, stdin);
    leituraS(codigo, 51);
    
    a = verifica(codigo);

    if (a == 1) {
        printf("\nOla, %s %s, entrada liberada. Seja bem vindo(a)! \n\n", funcao, nome);
    }
    else {
        printf("Codigo de acesso invalido, acesso nao liberado. \n\n");
    }

    return 0;
}

// Questão 4 da lista 2 de strings

