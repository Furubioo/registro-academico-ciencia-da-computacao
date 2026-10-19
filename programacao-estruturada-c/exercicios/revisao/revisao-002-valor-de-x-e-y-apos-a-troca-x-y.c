#include <stdio.h>

int main() {

    int x,y;
    int *px, *py;
    px = &y;
    py = &x;

    printf("Digite o primeiro valor: ");
    scanf("%d", &x);

    printf("Digite o segundo valor: ");
    scanf("%d", &y);

    printf("Valor de x e y apos a troca: x=%d; y=%d \n", *px, *py);

    return 0;
}

