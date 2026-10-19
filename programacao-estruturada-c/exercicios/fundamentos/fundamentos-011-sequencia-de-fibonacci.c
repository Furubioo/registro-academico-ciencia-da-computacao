#include <stdio.h>
#include <stdlib.h>

int main() {

    int n1 = 1, n2 = 1, n3 = 2, n4 = 0, n5 = 0, n6 = 0, a, i;

    printf("***Sequencia de Fibonacci*** \n\n");

    printf("Atencao!! Voce deve digitar um numero > 3.\n\n");

    printf("Digite quantos termos quer ver \n(N-esimo termo da sequencia de fibonacci): ");
    scanf("%d", &a);

    if (a <= 3) {
        printf("Valor incorreto! \n");
        printf("Digite novamente: ");
        scanf("%d", &a);
    }

    printf("%d %d %d ", n1, n2, n3);
    
    for (i = 4; i <= a; i++){
        n4 = n2;
        n5 = n3;
        n6 = n5 + n4;
        printf("%d ", n6);
        n2 = n3;
        n3 = n6;    

    }   
    printf("\n");

    return 0;
}

