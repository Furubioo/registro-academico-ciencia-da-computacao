#include <stdio.h>

#define ORDEM 5

static int preencher(float matriz[ORDEM][ORDEM], const char *rotulo) {
    for (int i = 0; i < ORDEM; i++) {
        for (int j = 0; j < ORDEM; j++) {
            printf("%s[%d][%d]: ", rotulo, i, j);
            if (scanf("%f", &matriz[i][j]) != 1) {
                return 0;
            }
        }
    }
    return 1;
}

static void exibir(const float matriz[ORDEM][ORDEM]) {
    for (int i = 0; i < ORDEM; i++) {
        for (int j = 0; j < ORDEM; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    float a[ORDEM][ORDEM];
    float b[ORDEM][ORDEM];
    float produto[ORDEM][ORDEM];

    if (!preencher(a, "A") || !preencher(b, "B")) {
        return 1;
    }
    for (int i = 0; i < ORDEM; i++) {
        for (int j = 0; j < ORDEM; j++) {
            produto[i][j] = a[i][j] * b[i][j];
        }
    }
    printf("Produto elemento a elemento:\n");
    exibir(produto);
    return 0;
}
