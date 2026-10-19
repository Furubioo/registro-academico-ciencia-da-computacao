#include <stdio.h>
#include <stdlib.h>

int main() {
    float notas, result, soma;
    soma = 0;
    int i;
    for(i = 0; i < 10; i++) {
        printf("Digite a nota: ");
        scanf("%f", &notas);
        soma +=notas;
    }
    result = soma / 10;
    printf("A media das 10 notas eh: %.2f \n\n", result);
return 0;
}

