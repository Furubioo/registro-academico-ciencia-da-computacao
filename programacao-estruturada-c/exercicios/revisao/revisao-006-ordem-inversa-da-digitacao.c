#include <stdio.h>

int main() {

    int i, j, valor[6];

    for (i = 0; i < 6; i++) {
        printf("Digite o valor [%d]: ", i);
        scanf("%d", &valor[i]);
    }
    printf("\n");
    printf("Ordem inversa da digitacao: ");
    for (j = 5; j >= 0; j--) {
        printf("%d  ", valor[j]);
    }
    printf("\n");

    return 0;
}

