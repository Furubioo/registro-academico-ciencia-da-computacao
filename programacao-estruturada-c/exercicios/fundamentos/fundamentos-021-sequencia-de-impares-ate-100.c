#include <stdlib.h>
#include <stdio.h>

int main() {
    int cont;

    printf("Sequencia de impares ate 100 \n\n");

    cont = 1;

    do {
        if (cont % 2 != 0) {
            printf("%d \n", cont);
        }
        cont++; 
    }
    while (cont < 100);
return 0;
}

