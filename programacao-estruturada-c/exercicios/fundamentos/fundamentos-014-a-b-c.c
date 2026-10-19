#include <stdio.h>
#include <stdlib.h>

int ordem(float A, float B, float C) {

    if (A < B && A < C && B < C) {
        printf("A = %.2f \nB = %.2f \nC = %.2f \n\n",A ,B ,C);
    }
    else if (A < B && A < C && B > C) {
        printf("A = %.2f \nB = %.2f \nC = %.2f \n\n",A ,C ,B);
    }
    else if (A > B && A < C && B < C) {
        printf("A = %.2f \nB = %.2f \nC = %.2f \n\n",B ,A ,C);
    }
    else if (A < B && A > C && B > C) {
        printf("A = %.2f \nB = %.2f \nC = %.2f \n\n",C ,A ,B);
    }
    else if (A > B && A > C && B < C) {
        printf("A = %.2f \nB = %.2f \nC = %.2f \n\n",B ,C ,A);
    }
    else if (A > B && A > C && B > C) {
        printf("A = %.2f \nB = %.2f \nC = %.2f \n\n",C ,B ,A);
    }

    return 0;
}

int main() {

    float a, b, c;

    printf("**Organizacao de numeros** \n\n");

    printf("**Digite 3 valores** \n\n");
    printf("Digite o primeiro: ");
    scanf("%f", &a);
    printf("Digite o segundo: ");
    scanf("%f", &b);
    printf("Digite o terceiro: ");
    scanf("%f", &c);

    printf("Ordem correta: \n\n");
    ordem(a,b,c);

    return 0;
}

