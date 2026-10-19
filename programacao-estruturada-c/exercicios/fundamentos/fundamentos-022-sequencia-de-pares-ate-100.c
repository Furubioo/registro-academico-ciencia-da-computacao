#include <stdlib.h>
#include <stdio.h>

int main() {
    int i, n, cont;

    printf("**Sequencia de pares ate 100** \n\n");

    n = 100;
    for (i = 1; i <=n; i++){
        cont++;
        if (cont % 2 == 0){
            printf("%d \n", i);
        }
    }
return 0;
}

