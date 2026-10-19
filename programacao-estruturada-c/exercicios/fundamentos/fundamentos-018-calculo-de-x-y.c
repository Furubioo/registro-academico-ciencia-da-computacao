#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    float x, y, result = 1;

    printf("***Calculo de x^y*** \n\n");
    printf("Digite o valor da base: ");
    scanf("%f", &x);
    printf("Digite o valor do expoente: ");
    scanf("%f", &y);

        for(i = 1; i <= (int)y; i++) {
            result = result * x;
        }
    printf("O valor de %.2f^%.2f eh %.2f", x, y, result);    
return 0;
}

