#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n1, n2, s, p, q;
    printf("Informe dois numeros e voce descobrira: \n\n");
    printf("- A soma desses numeros; \n");
    printf("- O produto do primeiro numero pelo quadrado do segundo; \n");
    printf("- O quadrado do primeiro numero \n \n");

    printf("Informe-os a seguir. \n \n");
    printf("Primeiro numero: ");
    scanf("%d", &n1);
    printf("Segundo numero: ");
    scanf("%d", &n2);

    s = n1 + n2;
    printf("A soma desses numeros eh %d \n\n", s);

    p = n1 * (n2 * n2);
    printf("O produto do primeiro numero pelo quadrado do segundo eh: %d \n\n", p);

    q = n1 * n1;
    printf("O quadrado do primerio numero eh: %d \n\n", q);
return 0;
}

