#include <stdio.h>

int main() {

    int i, valor[10], maior;

    for (i = 0; i < 10; i++) {
        printf("Digite o valor [%d]: ", i);
        scanf("%d", &valor[i]);
        if (valor[i] > valor[i-1]) {
            maior = valor[i];
        }
    }

    printf("O maior valor digitado foi: %d \n", maior);

    return 0;
}

