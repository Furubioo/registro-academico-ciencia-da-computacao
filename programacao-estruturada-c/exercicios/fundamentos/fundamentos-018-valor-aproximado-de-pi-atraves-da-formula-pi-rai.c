#include <stdio.h>
#include <math.h>

void serie(float termosS);

float calculo1(float termosS);

float calculofinal(float s);

int main() {

    float ntermos, valorS, valorF;

    printf("Valor aproximado de pi atraves da formula:\n pi = (raiz cubica de 32 * S)\n\n");
    printf("Onde S: 1 - 1/3^3 + 1/5^3 - 1/7^3 + 1 / 9^3 - ...\n\n");

    printf("Informe o numero de termos da sequencia(S): ");
    scanf("%f", &ntermos);

    serie(ntermos);

    valorS = calculo1(ntermos);
    printf("O valor de S eh %f\n", valorS);

    valorF = calculofinal(valorS);
    printf("O valor final de pi nessa sequencia eh %f", valorF);

    return 0;
}

void serie(float termosS) {

    float i;
    float den = 3;
    printf("1");

    termosS-=1;
    for (i = 1; i <= termosS; i++) {
        if((int)i % 2 != 0) {
            printf(" - 1/%0.f^3", den);
        }
        if((int)i % 2 == 0) {
            printf(" + 1/%0.f^3", den);
        }
        den+=2;
    }
    printf("\n");

}

float calculo1(float termosS) {

    float deno = 3, i, s;

    s = 1;

    termosS-=1;
    for (i = 1; i <= termosS; i++) {

        if((int)i % 2 != 0) {
            s -= 1 / (deno * deno * deno);
        }
        if((int)i % 2 == 0) {
            s += 1/ (deno * deno * deno);
        }
        deno+=2;
    }
        
    printf("\n");
    
    return s;
}

float calculofinal(float s) {

    float valor;

    valor = pow(32.00 * s, 1.0 / 3.0);

    return valor;

}

