#include <stdio.h>

int main() {

    int i, valor[5], soma = 0;

    for (i = 0; i < 5; i++) {
        printf("Digite o valor [%d]: ", i);
        scanf("%d", &valor[i]);
        soma+=valor[i];
    }

    printf("A soma de todos os valores digitados eh %d \n", soma);

    return 0;
}

