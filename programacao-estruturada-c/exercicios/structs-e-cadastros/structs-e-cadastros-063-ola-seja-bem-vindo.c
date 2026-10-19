#include <stdio.h>
#include <string.h>
#include <ctype.h>


int verifica(char codigo[], int tam) {

    int i;
    int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;
    int soma;

    if (strlen(codigo) != 9) {
        return 2;
    }

    for (i = 0; i < tam; i++) {
        if (isupper(codigo[i]) && cont1 == 0) {
            cont1++;
        }
        else if (islower(codigo[i]) && cont2 == 0) {
            cont2++;
        }
        else if (isdigit(codigo[i]) && cont3 == 0) {
            cont3++;
        }
        else if (!isalpha(codigo[i]) && !isdigit(codigo[i]) && !isspace(codigo[i]) && cont4 == 0) {
            cont4++;
        }

    }
    soma = cont1 + cont2 + cont3 + cont4;

    if (soma >=4) {
        return 1;
    }
    else {
        return 3;
    }

}

int main() {

    char codigo[10];
    int valor;

    printf("Digite o seu codigo de acesso: ");
    fgets(codigo, 10, stdin);

    valor = verifica(codigo, strlen(codigo));
    
    if (valor == 1) {
        printf("Ola, seja bem vindo! \n\n");
    }
    else if (valor == 2) {
        printf("Quantidade invalida de caracteres! \n\n");
    }
    else if (valor == 3){
        printf("Formato invalido! \n\n");
    }


}

