#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    float pi = 3.1415;
    float r, c, a, v;

    printf("Informe o raio: ");
    scanf("%f", &r);

    c = 2 * pi * r;
    a = pi * pow(r,2);
    v = 3.0/4.0 * pi * pow(r,3);

    printf("O comprimento da circunferencia eh %.2f \n", c);
    printf("A area da circunferencia eh %.2f \n", a);
    printf("O volume do circulo eh %.2f \n", v);
    
    return 0;
}

// informar o valor da conta, o numero de dias em atraso, o valor da multa por dia e o percentual de juros a ser aplicado

