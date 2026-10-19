#include <stdio.h>
#include <string.h>

int main(void) {
    char frase[201];
    char caractere;
    size_t i;
    int ocorrencias = 0;

    printf("Frase: ");
    if (fgets(frase, sizeof frase, stdin) == NULL) {
        return 1;
    }
    frase[strcspn(frase, "\n")] = '\0';
    printf("Caractere procurado: ");
    if (scanf(" %c", &caractere) != 1) {
        return 1;
    }
    for (i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == caractere) {
            ocorrencias++;
        }
    }
    printf("Ocorrencias de '%c': %d\n", caractere, ocorrencias);
    return 0;
}
