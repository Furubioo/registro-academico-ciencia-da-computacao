#include <stdio.h>

void ordena(float *pA, float *pB, float *pC);

int main() {

    float *pA, *pB, *pC;
    float a, b, c;

    pA = &a;
    pB = &b;
    pC = &c;

    printf("**Ordenacao de valores**\n\n");

    printf("Digite o valor de A: ");
    scanf("%f", &a);
    printf("Digite o valor de B: ");
    scanf("%f", &b);
    printf("Digite o valor de C: ");
    scanf("%f", &c);

    ordena(&a, &b, &c);

    printf("\n\nNovo valor de A: %.2f\n", *pA);
    printf("Novo valor de B: %.2f\n", *pB);
    printf("Novo valor de C: %.2f\n", *pC);

return 0;

}

void ordena(float *pA, float *pB, float *pC) {

    float aux1, aux2, aux3;

    if (*pA > *pB) {
        aux1 = *pB;
        *pB = *pA;
        *pA = aux1;
    }

    if (*pB > *pC) {
        aux2 = *pB;
        *pB = *pC;
        *pC = aux2;
    }

    if (*pA > *pB) {
        aux3 = *pB;
        *pB = *pA;
        *pA = aux3;
    }

}

