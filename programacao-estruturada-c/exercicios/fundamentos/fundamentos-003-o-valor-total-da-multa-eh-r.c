#include <stdio.h>
#include <stdlib.h>

int main() {

    float valor, multad, percjuros, totalmulta, totaljuros, totalmj;
    int atraso;

    printf("Informe o valor da conta: ");
    scanf("%f", &valor);
    printf("Informe o numero de dias em atraso: ");
    scanf("%d", &atraso);
    printf("Informe o valor da multa: ");
    scanf("%f", &multad);
    printf("Informe o percentual de juros: ");
    scanf("%f", &percjuros);
    
    totalmulta = multad * atraso;
    totaljuros = valor * (percjuros / 100) * atraso;
    totalmj = valor + totalmulta + totaljuros;

    printf("O valor total da multa eh R$: %.2f \n", totalmulta);
    printf("O valor total dos juros a ser pago por %d dias de atraso eh R$: %.2f \n", atraso, totaljuros);
    printf("O valor total da conta a ser pago com multa e juros eh R$: %.2f \n", totalmj);

    return 0;
}

