#include <stdio.h>
#include <string.h>
#include <ctype.h>


int verifica(char codigo[]) {

    int i;
    int contM = 0, contm = 0, contN = 0, contS = 0;
    int soma;

    if (strlen(codigo) != 9) {
        return 2;
    }

    for (i = 0; i < 9; i++) {
        if (isupper(codigo[i]) && contM == 0) {
            contM++;
        }
        if (islower(codigo[i]) && contm == 0) {
            contm++;
        }
        if (isdigit(codigo[i]) && contN == 0) {
            contN++;
        }
        if (!isalpha(codigo[i]) && !isdigit(codigo[i]) && !isspace(codigo[i]) && contS == 0) {
            contS++;
        }        
    }

    soma = contM + contm + contN + contS;

    if (soma == 4) {
        return 1;
    }
    else {
        return 3;
    }

}

int main() {

    char codigo[10];
    int valor;

    printf("Digite o seu codigo: ");
    fgets(codigo, 10, stdin);
    valor = verifica(codigo);

    if (valor == 1) {
        printf("Ola, seja bem vindo! \n\n");
    }
    else if (valor == 2) {
        printf("Quantidade invalida de caracteres! \n\n");
    }
    else if (valor == 3) {
        printf("Formato invalido! \n\n");
    }



    return 0;
}

// Questão 2

