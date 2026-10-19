#include <stdlib.h>
#include <stdio.h>

int main() {
    int i, n, soma;

    printf("**Soma de 1 ate o numero digitado** \n\n");
    printf("Digite um valor: ");
    scanf("%d", &n);

    soma = 0;
    for (i = 1; i <=n; i++) {
        soma +=i;
    }
    printf("A soma, a partir do numero 1 ate o numero digitado eh: \n%d \n\n", soma);
return 0;
}

