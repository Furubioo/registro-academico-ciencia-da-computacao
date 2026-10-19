#include <stdio.h>

#define TOTAL_PESSOAS 5

typedef struct {
    char sexo;
    int filhos;
    int empregada;
} Pessoa;

int main(void) {
    Pessoa pessoas[TOTAL_PESSOAS];
    int i;
    int total = 0;

    for (i = 0; i < TOTAL_PESSOAS; i++) {
        printf("Pessoa %d - sexo (M/F): ", i + 1);
        if (scanf(" %c", &pessoas[i].sexo) != 1) {
            return 1;
        }
        printf("Numero de filhos: ");
        if (scanf("%d", &pessoas[i].filhos) != 1) {
            return 1;
        }
        printf("Empregada (1 para sim, 0 para nao): ");
        if (scanf("%d", &pessoas[i].empregada) != 1) {
            return 1;
        }
        if ((pessoas[i].sexo == 'F' || pessoas[i].sexo == 'f') &&
            pessoas[i].filhos > 0 && pessoas[i].empregada == 0) {
            total++;
        }
    }
    printf("Mulheres desempregadas com filhos: %d\n", total);
    return 0;
}
