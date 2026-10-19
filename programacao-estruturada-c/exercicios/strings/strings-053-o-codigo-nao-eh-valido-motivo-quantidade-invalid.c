#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verificacao(char codigo[51]) {

    int i, tam = strlen(codigo);
    int contL = 0, contN = 0;

    if (tam != 9) {
        return 1;
    }

    for (i = 0; i < tam; i++) {

        if (i == 0 && tolower(codigo[i]) != 'a') {
            return 2;
            break;
        }
        if (isalpha(codigo[i])) {
            contL++;
        }
        if (isdigit(codigo[i])) {
            contN++;
        }
        if (i == 3 && contL != 4) {
            return 2;
            break;
        }
        if (i == 8 && contN != 5) {
            return 2;
            break;
        }
        
    }

    return 3;

}

void leiturasegura(char Codigo[]) {

    int i, tam = strlen(Codigo);

    for (i = 0; i < tam; i++) {
        if (Codigo[i] == '\n') {
            Codigo[i] = '\0';
        }
    }

}

int main() {

    char Codigo[51], valor;

    printf("Digite o codigo: ");
    fgets(Codigo, sizeof(Codigo), stdin);
    leiturasegura(Codigo);

    valor = verificacao(Codigo);

    if (valor == 1) {
        printf("O codigo %s nao eh valido. Motivo: quantidade invalida de caracteres. \n\n", Codigo);
    }

    if (valor == 2) {
        printf("O codigo %s nao eh valido. Motivo: Formato incorreto. \n\n", Codigo);
    }

    if (valor == 3) {
        printf("O codigo %s eh valido. \n\n", Codigo);
    }


    return 0;

}


// Questão 5

