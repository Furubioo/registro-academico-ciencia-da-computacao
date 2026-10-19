#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANCAMENTOS 1000000

int main(void) {
    int frequencias[6] = {0};
    srand((unsigned int)time(NULL));

    for (int i = 0; i < LANCAMENTOS; i++) {
        frequencias[rand() % 6]++;
    }

    int possivelmente_viciado = 0;
    const double minimo = LANCAMENTOS * 0.15;
    const double maximo = LANCAMENTOS * 0.17;
    for (int i = 0; i < 6; i++) {
        printf("Face %d: %d\n", i + 1, frequencias[i]);
        if (frequencias[i] < minimo || frequencias[i] > maximo) {
            possivelmente_viciado = 1;
        }
    }

    printf("O dado %s dentro da faixa de frequencia esperada.\n",
           possivelmente_viciado ? "nao esta" : "esta");
    return 0;
}
