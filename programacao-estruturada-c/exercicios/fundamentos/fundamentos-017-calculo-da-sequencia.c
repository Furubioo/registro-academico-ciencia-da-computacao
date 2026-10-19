#include <stdio.h>

void quantidade(float qtd);

float funcao1(float qtd);

float funcao2(float qtd);

int main() {

    float QTD;

    printf("Calculo da sequencia: \n\n");
    printf("e = 1 + 1/1! + 1/2! + 1/3! + ... \n\n");
    printf("Digite quantos valores da sequencia \nquer ver e o seu resultado: ");
    scanf("%f", &QTD);

    if (QTD < 3) {
        printf("Valor invalido. \nInforme um valor valido(>3): ");
        scanf("%f", &QTD);
    }

    quantidade(QTD);
    funcao2(QTD);

    return 0;
}

void quantidade(float qtd) {

    float i;
    float n1 = 1, n2 = 2;

    printf("\nSua sequencia: \n\ne = 1 + 1 / %.0f! + 1 / %.0f!", n1, n2);

    for (i = 3; i < qtd; i++) {
        printf(" + 1 / %.0f!", i);
    }


}

float funcao1(float qtd) {

    float i, b = 1;

    for (i = 1; i <= qtd-1; i++) {
        b *= i;
    }

    return b;
}

float funcao2(float qtd) {

    float i, e;

    e = 1.00 + (1.00 / 1.00) + (1.00 / (2.00 * 1.00));

    if (qtd > 3) {
        for (i = 4; i <= qtd; i++) {
            e += (1 / (funcao1(i)));
        }
    }
        printf("\nO valor aproximado dessa sequencia eh %.2f \n\n", e);

    return e;
}

