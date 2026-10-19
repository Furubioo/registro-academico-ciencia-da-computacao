#include <stdio.h>

int main(void) {
    int numero;
    int candidato;

    puts("** Saiba o proximo numero primo **");
    printf("Digite o numero: ");
    if (scanf("%d", &numero) != 1) {
        return 1;
    }

    for (candidato = numero + 1;; candidato++) {
        int divisor;
        int primo = candidato > 1;

        for (divisor = 2; divisor * divisor <= candidato; divisor++) {
            if (candidato % divisor == 0) {
                primo = 0;
                break;
            }
        }
        if (primo) {
            printf("O proximo numero primo eh: %d\n", candidato);
            return 0;
        }
    }
}

