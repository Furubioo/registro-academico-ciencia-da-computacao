#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, n, result;
    printf("***Calculo de fatorial*** \n");
    printf("Informe o seu numero: ");
    scanf("%d", &num);

    n = num;
    result = 1;

    while(n>1) {
        result *= n;
        n--;
    }
    printf("O fatorial do seu numero eh %d \n", result);
return 0;
}

