#include <stdio.h>
#include <stdlib.h>

int main() {

    float preco, percentual, desconto, vfinal;

    printf("***Calculo de desconto de um produto***\n\n");
    printf("Informe o preco do produto em R$: ");
    scanf("%f", &preco);
    printf("Informe o percentual de desconto: ");
    scanf("%f", &percentual);

    desconto = preco * (percentual / 100);
    vfinal = preco - desconto;

    printf("Preco real do produto em R$: %.2f \n", preco);
    printf("Quanto voce pagara pelo produto em R$: %.2f \n", vfinal);
    printf("Quanto voce esta economizando em R$: %.2f \n", desconto);

    return 0;
}

