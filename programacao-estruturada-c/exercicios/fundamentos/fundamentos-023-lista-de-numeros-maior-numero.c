#include <stdlib.h>
#include <stdio.h>

int main() {

    int n, cont, maior1, maior2;

    printf("***Lista de numeros(maior numero)**** \n\n");

    cont = 1;
    maior1 = 0;
    maior2 = 0;

    while(cont <= 10) {
        printf("Digite o valor: ");
        scanf("%d", &n);

        if (n > maior1) {
            maior2 = maior1;
            maior1 = n;
        }
        cont++;
    }
        printf("Os maiores numeros digitados nesse conjunto foram %d e %d \n\n", maior1, maior2 );
return 0;
}

// após digitar o primeiro numero e armazená-lo numa variável, se o proximo for maior ou igual, armazenar numa nova variavel, e o antigo vai para outra.

