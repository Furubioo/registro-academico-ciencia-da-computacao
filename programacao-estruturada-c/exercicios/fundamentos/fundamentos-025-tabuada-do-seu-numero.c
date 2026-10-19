#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, r;

    printf("***Tabuada do seu numero***\n\n");
    printf("Digite o seu numero: ");
    scanf("%d", &n);

    printf("A tabuada do numero %d eh:\n\n", n);

    for (i = 1; i <=10; i++) {
        r = i * n;
        printf("%d x %d = %d \n", n, i, r);
        printf("\n");
    }
return 0;
}

