#include <stdio.h>
#include <math.h>

int main() {

    float x,y,z;
    float *px, *py, *pz;
    float mult, div, elev;

    printf("Digite 3 numeros reais:\n\n");
    printf("Primeiro numero: ");
    scanf("%f", &x);
    printf("Segundo numero: ");
    scanf("%f", &y);
    printf("Terceiro numero: ");
    scanf("%f", &z);

    px = &x;
    py = &y;
    pz = &z;

    mult = *px * 4;
    div = *py / 3;
    elev = pow(*pz, 2);
    
    printf("\n\nPrimeiro numero x 4 = %.2f\n", mult);
    printf("Segundo numero / 3 = %.2f\n", div);
    printf("Terceiro numero ^ 2 = %.2f\n", elev);

    return 0;
}

