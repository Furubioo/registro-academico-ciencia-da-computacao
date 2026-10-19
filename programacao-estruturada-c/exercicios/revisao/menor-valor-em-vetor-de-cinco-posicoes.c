#include <stdio.h>

int main(void) {
    int valores[5];
    int i;
    int menor;

    for (i = 0; i < 5; i++) {
        printf("Valor %d: ", i + 1);
        if (scanf("%d", &valores[i]) != 1) {
            return 1;
        }
    }
    menor = valores[0];
    for (i = 1; i < 5; i++) {
        if (valores[i] < menor) {
            menor = valores[i];
        }
    }
    printf("Menor valor: %d\n", menor);
    return 0;
}
