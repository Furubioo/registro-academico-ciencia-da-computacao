#include <stdio.h>
#include <stdlib.h>

int main(){
  char nome[10];
  int idade;
  printf("Qual eh o seu nome? ");
  scanf(" %9s", nome);
  printf("Qual eh a sua idade? ");
  scanf(" %d", &idade);
  printf("Ola, %s, voce possui %d anos", nome, idade);
return 0;
}


