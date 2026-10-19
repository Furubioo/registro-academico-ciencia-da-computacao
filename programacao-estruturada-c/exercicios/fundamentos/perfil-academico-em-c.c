#include <stdio.h>

int main(void) {
    const int idade = 20;
    const char sexo = 'm';
    const float altura = 1.80f;
    const char nome[] = "Flavio";

    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Sexo: %c\n", sexo);
    printf("Altura: %.2f\n", altura);
    return 0;
}
