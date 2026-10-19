#include <stdio.h>
#include <stdlib.h>

int main() {
  int numero;
  printf("Informe o seu numero: ");
  scanf("%d", &numero);
  if(numero % 2 == 0) {
    printf("O seu numero eh par. \n");
  }
  else {
    printf("O seu numero eh impar. \n");
  }
return 0;
}

