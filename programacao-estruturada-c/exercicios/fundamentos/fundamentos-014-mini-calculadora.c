#include <stdio.h>
#include <stdlib.h>

int main() {

    int escolha;
    printf("Mini-calculadora \n");
    printf("1. Soma \n2. Subtracao \n3. Multiplicacao \n4. Divisao \n");
    printf("Escolha qual operacao realizar: ");
    scanf("%d", &escolha);

    switch(escolha) {
        float n1, n2, soma, n3, n4, sub, n5, n6, mult, n7, n8, div;

        case 1:
          printf("Informe o primeiro numero: ");
          scanf("%f", &n1);
          printf("Informe o segundo numero: ");
          scanf("%f", &n2);
          soma = n1 + n2;
          printf("A soma desses numeros eh %.2f. \n\n", soma);
          break;
        case 2:
          printf("Informe o primeiro numero: ");
          scanf("%f", &n3);
          printf("Informe o segundo numero: ");
          scanf("%f", &n4);
          if(n4 > n3) {
            sub = n4 - n3;
            printf("A subtracao desses numeros eh %.2f. \n\n", sub);
            break;
          }
          sub = n3 - n4;
          printf("A subtracao desses numeros eh %.2f. \n\n", sub);          
          break;
        case 3:
          printf("Informe o primeiro numero: ");
          scanf("%f", &n5);
          printf("Informe o segundo numero: ");
          scanf("%f", &n6);
          mult = n5 * n6;
          printf("A multiplicacao desses numeros eh %.2f.", mult);
          break;
        case 4:
          printf("Informe o primeiro numero: ");
          scanf("%f", &n7);
          printf("Informe o segundo numero: ");
          scanf("%f", &n8);
          if (n8 > n7) {
            div = n8 / n7;
            printf("A divisao entre esses numeros eh %.2f.", div);
            break;
          }
          div = n7 / n8;
          printf("A divisao entre esses numeros eh %.2f.", div);
          break;
    }
return 0;
}

