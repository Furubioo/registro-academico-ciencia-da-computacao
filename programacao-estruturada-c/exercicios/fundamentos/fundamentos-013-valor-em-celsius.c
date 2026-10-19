#include <stdio.h>
#include <stdlib.h>

float fahC(float fahrenheit) {

    float celsius;

    celsius = (fahrenheit - 32.00) / 1.8;

    printf("Valor em celsius: %.2f \n\n", celsius);

    return celsius;

}

float Cfah(float celsius) {

    float fahrenheit;

    fahrenheit = celsius * 1.8 + 32;

    printf("Valor em fahrenheit: %.2f \n\n", fahrenheit);

    return fahrenheit;
}

int main() {

    int a;
    char b;
    float n;

    while (1) {

        printf("1. Fahrenheit para Celsius;\n\n2. Celsius para fahrenheit;\n\n");
        printf("(Digite 1 para realizar a primeira conversao)\n");
        printf("(Digite 2 para realizar a segunda conversao)\n\n");

        printf("Digite a sua escolha: ");
        scanf("%d", &a);

        printf("Informe o valor a ser convertido: ");
        scanf("%f", &n);

        if (a == 1) {
            fahC(n);
        }

        if (a == 2) {
            Cfah(n);
        }

        printf("Deseja parar as conversoes? \n(s = sim) (n = nao)\nResponda: ");
        getchar();
        scanf("%c", &b);

        if (b == 's') {
            continue;
        }
        else if (b == 'n') {
            printf("Fim do programa. \n\n");
            break;
        }
         
    }

    return 0;
}


