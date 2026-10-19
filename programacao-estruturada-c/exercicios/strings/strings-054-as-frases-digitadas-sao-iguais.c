#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compara(char f1[51], char f2[51]) {

    int i, tam1 = strlen(f1) - 1, tam2 = strlen(f2) - 1;
    int cont = 0;
    int comp = 0;

    if (tam1 == tam2) {
        for (i = 0; i < tam1; i++) {
            if (tolower(f1[i]) == tolower(f2[i])) {
                cont++;
            }
        }
    }
    if (cont == tam1) {
        comp = 1;
    }

    return comp;
}

int main() {

    char frase1[51], frase2[51];
    int valor;

    printf("Digite a primeira frase: ");
    fgets(frase1, sizeof(frase1), stdin);
    printf("Digite a segunda frase: ");
    fgets(frase2, sizeof(frase2), stdin);

    valor = compara(frase1, frase2);

    if (valor == 1) {
        printf("\nAs frases digitadas sao iguais. \n\n");
    }
    else {
        printf("\nAs frases digitadas sao diferentes. \n\n");
    }

    return 0;
}

// Lista 1 ordenacao

//  Questão 1

