#include <stdio.h>
#include <stdlib.h>

int main() {

    float horasE, horasF, total;

    printf("**Gratificacao de natal** \n\n");

    printf("Informe a quantidade de horas extras: ");
    scanf("%f", &horasE);
    printf("Informe a quantidade de horas faltosas: ");
    scanf("%f", &horasF);

    total = horasE - (2.0/3.0 * horasF); 

    if (total > 40) {
        printf("O funcionario recebera R$ 400,00 de gratificacao de natal. \n");
    }
    if(total <= 40) {
        if (total > 30) {
            printf("O funcionario recebera R$ 325,00 de gratificacao de natal. \n");
        }
    }
    if(total <= 30) {
        if (total > 20) {
            printf("O funcionario recebera R$ 275,00 de gratificacao de natal. \n");
        }
    }
    if(total <= 20) {
        if (total > 10) {
            printf("O funcionario recebera R$ 250,00 de gratificacao de natal. \n");
        }
    }
    if(total <= 10) {
        printf("O funcionario recebera R$ 200,00 de gratificacao de natal. \n");
    }

    return 0;
}

