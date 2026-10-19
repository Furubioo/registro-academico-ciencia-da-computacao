#include <stdio.h>
#include <stdlib.h>

int main() {
  float num, dobro;
  printf("Informe o numero que deseja saber o dobro: ");
  scanf("%f", &num);
  dobro = num * 2;
  printf("O dobro de %.2f eh %.2f \n\n", num, dobro);
  return 0;

}

