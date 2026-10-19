#include <stdio.h>
#include <stdlib.h>

int main() {

    int lista, i, n, menor;

    printf("***Lista de numeros(menor numero)**** \n\n");
    printf("Digite a quantidade de numeros que quer digitar: ");
    scanf("%d", &lista);
    
    menor = n;

    for(i = 1; i <= lista; i++) {
        printf("Digite o valor: ");
        scanf("%d", &n);
        if (menor > n) {
            menor = n;
        }
    }
        printf("O menor numero digitado foi %d. \n\n", menor);
return 0;
}


