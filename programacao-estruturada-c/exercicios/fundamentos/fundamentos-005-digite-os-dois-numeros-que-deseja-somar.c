#include <stdio.h>
#include <stdlib.h>

int main(){
  int num1, num2, resultado;

  printf("*Digite os dois numeros que deseja somar* \n");
  printf("Digite o primeiro numero: ");
  scanf("%d", &num1);
  printf("Digite o segundo numero: ");
  scanf("%d", &num2);

  resultado = num1 + num2;

  printf("A soma dos dois numeros eh: %d \n \n", resultado);

  return 0;
}

