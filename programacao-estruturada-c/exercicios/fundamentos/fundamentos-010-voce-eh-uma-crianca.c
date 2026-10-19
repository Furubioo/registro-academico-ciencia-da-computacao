#include <stdio.h>
#include <stdlib.h>

int main() {
    int idade;
    printf("Digite qual a sua idade: ");
    scanf("%d", &idade);
    if(idade <= 12){
      printf("Voce eh uma crianca");
    }
    else if(idade >12 && idade <=17) {
      printf("Voce eh um adolescente");
    }
    else if(idade >=18 && idade <=59) {
      printf("Voce eh um adulto");
    }
    else if(idade >=60) {
      printf("Voce eh um idoso");
    }
return 0;
}


