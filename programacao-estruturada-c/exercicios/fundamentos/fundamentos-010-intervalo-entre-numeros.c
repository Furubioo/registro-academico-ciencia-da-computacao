#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, b, i, produto = 1, soma = 0;

    printf("***Intervalo entre numeros*** \n\n");
    printf("(Utilize um segundo numero maior que o primeiro.) \n\n");
    
    printf("Informe o primeiro numero: ");
    scanf("%d", &a);
    printf("Informe o segundo numero: ");
    scanf("%d", &b);

    while(a > b) {
        printf("Voce digitou a > b; Digite b > a. \n\n");
        printf("Informe o primeiro numero: ");
        scanf("%d", &a);
        printf("Informe o segundo numero: ");
        scanf("%d", &b);
    }
    printf("\n");
    printf("Os numeros pares, incluindo os digitados sao: \n");
    for (i = a; i <= b; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
            soma +=i;
        }
    }  
    printf("\n\n");
    printf("A soma dos numeros pares digitados eh: %d \n", soma);
    
    for (i = a; i <= b; i++) {
        if (i % 2 != 0) {
            produto *= i;
        }    
    }
    printf("O produto dos numeros impares, incluindo os digitados eh: %d. \n\n", produto);

    return 0;
}

