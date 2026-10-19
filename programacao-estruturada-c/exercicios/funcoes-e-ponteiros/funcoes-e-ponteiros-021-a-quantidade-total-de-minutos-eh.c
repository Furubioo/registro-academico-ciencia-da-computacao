#include <stdio.h>

int mintotal(int horas, int minutos);
void conversao(int minconversao, int *pmin, int *phora);

int main() {

    int tempoH, tempoM, tempoT, minconversao;
    char resposta;

    while (1) {
        printf("Digite o valor de hora(s): ");
        scanf("%d", &tempoH);
        printf("Digite o valor de minuto(s): ");
        scanf("%d", &tempoM);

        tempoT = mintotal(tempoH, tempoM);
    
        printf("A quantidade total de minutos eh %d \n\n", tempoT);

        printf("\nSegunda conversao:\n\n");
        printf("Informe o valor em minutos: ");
        scanf("%d", &minconversao);

        conversao(minconversao, &tempoH, &tempoM);

        printf("Valor em horas: %d\n", tempoH);
        printf("Valor em minutos: %d\n\n", tempoM);

        printf("Deseja finalizar o codigo?\n\n(s == sim)(n == nao): ");
        getchar();
        scanf("%c", &resposta);

        if (resposta == 's') {
            printf("Fim do codigo.\n\n");
            break;
        }
        if (resposta == 'n') {
            continue;
  
        }
        if (resposta != 's' && resposta != 'n') {
            printf("Digite um caractere valido!\n");
            printf("Deseja continuar as conversoes?\n\n(s == sim)(n == nao)");
            getchar();
            scanf("%c", &resposta);
        }
        
        return 0;
    }
}

int mintotal(int horas, int minutos) {

    int total;

    total = (horas * 60) + minutos;

    return total;

}

void conversao(int minconversao, int *pmin, int *phora) {

    *pmin = minconversao / 60;
    *phora = minconversao % 60; 

}


