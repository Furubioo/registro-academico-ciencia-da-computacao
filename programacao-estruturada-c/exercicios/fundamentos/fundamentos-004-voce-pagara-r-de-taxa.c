#include <stdio.h>
#include <stdlib.h>

int main() {

    int anofab;
    float valortab, taxa1, taxa2;
    
    printf("Informe o ano de fabricacao do carro: ");
    scanf("%d", &anofab);
    printf("Informe o valor de tabela do carro: ");
    scanf("%f", &valortab);

    if (anofab < 2000) {
        taxa1 = (1 / 100) * valortab;
        printf("Voce pagara R$ %.2f de taxa. \n", taxa1);
    }
    else if (anofab >= 2000) {
        taxa2 = (1.5 / 100) * valortab;
        printf("Voce pagara R$ %.2f de taxa. \n", taxa2);
    }

    return 0;
}

