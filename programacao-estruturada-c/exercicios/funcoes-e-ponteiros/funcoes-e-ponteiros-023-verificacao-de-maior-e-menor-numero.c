#include <stdio.h>

void maiormenor(int A, int B, int C, int D, int *pmaior, int *pmenor);

int main() {

    int a, b, c, d;
    int *pmaior, *pmenor;
    int Maior, Menor;
    pmaior = &Maior;
    pmenor = &Menor;

    printf("***Verificacao de maior e menor numero***\n\n");

    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
    printf("Digite o terceiro numero: ");
    scanf("%d", &c);
    printf("Digite o quarto numero: ");
    scanf("%d", &d);

    maiormenor(a, b, c, d, &Maior, &Menor);

    printf("\nMenor valor entre %d, %d, %d e %d: %d\n", a, b, c, d, *pmenor);
    printf("Maior valor entre %d, %d, %d e %d: %d\n\n", a, b, c, d, *pmaior);

    return 0;
}

void maiormenor(int A, int B, int C, int D, int *pmaior, int *pmenor) {

    int menor1, menor2, maior1, maior2;

    if (A < B) {
        menor1 = A;
    }
    else {
        menor1 = B;
    }

    if (C < D) {
        menor2 = C;
    }
    else{
        menor2 = D;
    }

    if (menor1 < menor2) {
        *pmenor = menor1;
    }
    else{
        *pmenor = menor2;        
    }

    if (A > B) {
        maior1 = A;
    }
    else {
        maior1 = B;
    }

    if (C > D) {
        maior2 = C;
    }
    else{
        maior2 = D;
    }

    if (maior1 > maior2) {
        *pmaior = maior1;
    }
    else{
        *pmaior = maior2;        
    }

}

