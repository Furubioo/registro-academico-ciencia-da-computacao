#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("*Digite 10 valores* \n\n");

    int v[10], i;

    for (i = 0; i < 10; i++) {
        printf("Digite: ");
        scanf("%d", &v[i]);
    }
    for (i = 0; i < 10; i++) {
        if (v[i] > v[0]) {
            v[0] = v[i];
        }
    }
       printf("O maior numero digitado foi %d \n\n", v[0]); 
return 0;
}
    
