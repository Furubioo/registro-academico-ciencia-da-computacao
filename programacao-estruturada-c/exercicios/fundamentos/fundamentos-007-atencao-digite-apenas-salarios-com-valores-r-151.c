#include <stdio.h>
#include <stdlib.h>

int main() {

    float sAtual, nSalario, a1, a2, a3, a4;
    char r;

    printf("ATENCAO: Digite apenas salarios com valores >= R$ 1518,00 \n\n");

    while(1) {
        printf("Informe o seu salario: ");
        scanf("%f", &sAtual);

        if (sAtual >= 1518 && sAtual <=1800) {
            a1 = (20.00 / 100.00) * sAtual;
            nSalario = sAtual + a1;
            printf("O funcionario tera aumento de R$ %.2f e passara a receber R$ %.2f \n", a1, nSalario);
            printf("Deseja continuar executando o programa? responda com 's' ou 'n': ");
            scanf(" %c", &r);
            if (r == 'n') {
                printf("Fim do programa.\n");
                break;
            }
            else {
                continue;
            }
        
        }  

        else if (sAtual > 1800 && sAtual <= 2500) {    
            a2 = (15.00 / 100.00) * sAtual;
            nSalario = sAtual + a2;
            printf("O funcionario tera aumento de R$ %.2f e passara a receber R$ %.2f \n", a2, nSalario);
            printf("Deseja continuar executando o programa? responda com 's' ou 'n': ");
            scanf(" %c", &r);
            if (r == 'n') {
                printf("Fim do programa.\n");
                break;
            }
            else {
                continue;
            }
        
        }        

        else if (sAtual > 2500 && sAtual <= 4000) {    
            a3 = (10.00 / 100.00) * sAtual;
            nSalario = sAtual + a2;
            printf("O funcionario tera aumento de R$ %.2f e passara a receber R$ %.2f \n", a3, nSalario);
            printf("Deseja continuar executando o programa? responda com 's' ou 'n': ");
            scanf(" %c", &r);
            if (r == 'n') {
                printf("Fim do programa.\n");
                break;
            }
            else {
                continue;
            }
        
        }

        else if (sAtual > 4000) {    
            a4 = (5.00 / 100.00) * sAtual;
            nSalario = sAtual + a4;
            printf("O funcionario tera aumento de R$ %.2f e passara a receber R$ %.2f \n", a4, nSalario);
            printf("Deseja continuar executando o programa? responda com 's' ou 'n': ");
            scanf(" %c", &r);
            if (r == 'n') {
                printf("Fim do programa.\n");
                break;
            }
            else {
                continue;
            }
        }
    }

    return 0;
}

