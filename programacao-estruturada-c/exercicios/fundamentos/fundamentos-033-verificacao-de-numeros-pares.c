#include <stdio.h>
#include <stdlib.h>

int main() {

    int a[10], i;

    printf("**Verificacao de numeros pares** \n\n");

    for (i = 0; i < 10; i++) {
        printf("Digite: ");
        scanf("%d", &a[i]);
    }

    printf("\n");

    printf("Os numeros pares digitados foram:\n\n");
    for (i = 0; i < 10; i++) {
        if (a[i] % 2 == 0) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}

