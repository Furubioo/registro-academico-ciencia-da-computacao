#include <stdio.h>
#include <math.h>

void raizes(float A, float B, float C, float *p1, float *p2, float *p3);

int main() {

    float a, b, c;
    float existeRaizesReais, x1, x2;
    float *p1, *p2, *p3;

    p1 = &existeRaizesReais;
    p2 = &x1;
    p3 = &x2;

    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);

    raizes(a, b, c, &existeRaizesReais, &x1, &x2);

    if (*p1 == 0) {
        printf("Nao ha raizes reais. \n\n");
    }

    if (*p1 == 1) {
        printf("As duas raizes reais sao iguais(x' == x''), portanto x' = %.2f \n\n", *p2);
    }

    if (*p1 == 2) {
        printf("As raizes sao diferentes e sao x'= %.2f e x''= %.2f \n\n", *p2, *p3);
    }   

    return 0;
}


void raizes(float A, float B, float C, float *p1, float *p2, float *p3) {

    float delta;

    delta = B * B - 4.0 * A * C;

    if (delta < 0) {
        *p1 = 0;
    }

    else if (delta == 0) {
        *p2 = -B / (2 * A);
        *p3 = *p2;
        *p1 = 1;
    }
    else {
        *p2 = (-B + pow(delta, 1/2)) / (2 * A);
        *p3 = (-B - pow(delta, 1/2)) / (2 * A);
        *p1 = 2;

    }

}

