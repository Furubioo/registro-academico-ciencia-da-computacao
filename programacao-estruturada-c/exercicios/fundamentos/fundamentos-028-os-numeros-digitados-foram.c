#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, vetor[5];

    printf("Digite 5 numeros: \n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Os numeros digitados foram: \n");
    for(i = 0; i < 5; i++) {
        printf("%d \n", vetor[i]);
    }
return 0;
}

