#include <stdio.h>
#include <stdlib.h>

void linhas(int N) {

    int i;

    while (N < 0) {
        printf("Valor menor que zero!\n\n");
        printf("Informe um valor > 0: ");
        scanf("%d", &N);
    }

    for (i = 1; i <= N; i++) {
        printf("%d ", i);

    }
    printf("\n");

}

void todaslinhas(int N) {

    int j;
    
    for(j = 1; j <= N; j++) {
        linhas(N);
        N--;
    }
}

int main() {

    int n;

    printf("**Piramide de numeros**\n\n");

    printf("Informe um valor: ");
    scanf("%d", &n);

    todaslinhas(n);

    return 0;

}

