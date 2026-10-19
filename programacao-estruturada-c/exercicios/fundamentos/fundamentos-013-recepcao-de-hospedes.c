#include <stdio.h>
#include <stdlib.h>

int main() {

    int escolha;
    printf("Recepcao de hospedes \n \n");
    printf("Opcoes: \n 1. Fazer check-in \n 2.Chamar servico de quarto \n 3.Fazer pedido \n");
    printf("Qual opcao gostaria de escolher?");
    scanf("%d", &escolha);

    switch(escolha) {
        case 1:
          printf("Voce fez check-in \n \n");
          break;
        case 2:
          printf("Voce chamou o servico de quarto \n \n");
          break;
        case 3:
          printf("Voce fez um pedido \n \n");
          break;
//     default:
      printf("Numero invalido \n\n");
      break;
    }
return 0;
}

