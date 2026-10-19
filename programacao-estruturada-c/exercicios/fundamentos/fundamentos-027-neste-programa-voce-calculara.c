#include <stdio.h>
#include <stdlib.h>

int main() {

    int r;
    float c, a, v;
    const double pi = 3.141592; 

    printf("Neste programa, voce calculara: \n\n");
    printf("- O comprimento da circunferencia;\n");
    printf("- A area do circulo;\n");
    printf("- O volume da esfera;\n \n");

    printf("Digite o valor do raio: ");
    scanf("%d", &r);

    c = 2 * pi * r;
    printf("O comprimento da circunferencia(raio %d) eh: %.2f \n\n", r, c);

    a = pi * (r * r);
    printf("A area do circulo(raio %d) eh: %.2f \n\n", r, a);

    v = 3.0 / 4.0 * pi * (r * r * r);
    printf("O volume da esfera(raio %d) eh %.2f \n\n", r ,v);
return 0;
}

