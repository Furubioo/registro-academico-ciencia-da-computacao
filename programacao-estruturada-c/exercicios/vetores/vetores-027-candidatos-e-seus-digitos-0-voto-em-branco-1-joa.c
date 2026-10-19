#include <stdio.h>
#define tam 5


int main() {

    int branco[tam] = {0}, joao[tam] = {0}, maria[tam] = {0}, pedro[tam] = {0}, luis[tam] = {0}, ana[tam] = {0}, luiza[tam] = {0}, silvia[tam] = {0}, andre[tam] = {0};
    int i = 0, digito, perc0, perc1, perc2, perc3, perc4, perc5, perc6, perc7, perc8;
    int k;
    char escolha;
    int vetsoma0 = 0, vetsoma1 = 0, vetsoma2 = 0, vetsoma3 = 0, vetsoma4 = 0, vetsoma5 = 0, vetsoma6 = 0, vetsoma7 = 0, vetsoma8 = 0;

    while(1) {
        printf("Candidatos e seus digitos: \n\n0 - Voto em branco\n1 - Joao\n2 - Maria\n3 - Pedro\n4 - Luis\n5 - Ana\n6 - Luiza\n7 - Silvia\n8 - Andre");

        printf("\nEm quem deseja votar?(Utilize o digito)\n");
        scanf("%d", &digito);

        if (digito == 0) {
            branco[i] += 1;
        }

        if (digito == 1) {
            joao[i] += 1;
        }

        if (digito == 2) {
            maria[i] += 1;
        }

        if (digito == 3) {
            pedro[i] += 1;
        }

        if (digito == 4) {
            luis[i] += 1;
        }

        if (digito == 5) {
            ana[i] += 1;
        }

        if (digito == 6) {
            luiza[i] += 1;
        }

        if (digito == 7) {
            silvia[i] += 1;
        }

        if (digito == 8) {
            andre[i] += 1;

        }

        i++;

        printf("Outro eleitor ira votar?");
        getchar();
        scanf("%c", &escolha);

        if (escolha == 'S' || escolha == 's') {
            continue;
        }

        for (k = 0; k < 5; k++) {
            vetsoma0 += branco[k];
            vetsoma1 += joao[k];
            vetsoma2 += maria[k];
            vetsoma3 += pedro[k];
            vetsoma4 += luis[k];
            vetsoma5 += ana[k];
            vetsoma6 += luiza[k];
            vetsoma7 += silvia[k];
            vetsoma8 += andre[k];
        }

        perc0 = (vetsoma0 * 100) / i;
        perc1 = (vetsoma1 * 100) / i;
        perc2 = (vetsoma2 * 100) / i;
        perc3 = (vetsoma3 * 100) / i;
        perc4 = (vetsoma4 * 100) / i;
        perc5 = (vetsoma5 * 100) / i;
        perc6 = (vetsoma6 * 100) / i;
        perc7 = (vetsoma7 * 100) / i;
        perc8 = (vetsoma8 * 100) / i;

        if (escolha == 'N' || escolha == 'n') {
            printf("Votos em branco: %d\n", vetsoma0);
            printf("Percentual: %d%%\n", perc0);
            printf("Votos em Joao: %d\n", vetsoma1);
            printf("Percentual: %d%%\n", perc1);
            printf("Votos em Maria: %d\n", vetsoma2);
            printf("Percentual: %d%%\n", perc2);
            printf("Votos em Pedro: %d\n", vetsoma3);
            printf("Percentual: %d%%\n", perc3);
            printf("Votos em Luis: %d\n", vetsoma4);
            printf("Percentual: %d%%\n", perc4);
            printf("Votos em Ana: %d\n", vetsoma5);
            printf("Percentual: %d%%\n", perc5);
            printf("Votos em Luiza: %d\n", vetsoma6);
            printf("Percentual: %d%%\n", perc6);
            printf("Votos em Silvia: %d\n", vetsoma7);
            printf("Percentual: %d%%\n", perc7);
            printf("Votos em Andre: %d\n", vetsoma8);
            printf("Percentual: %d%%\n", perc8);

           
            break;
        }

        if (escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n') {
            printf("Caractere invalido!\n");
            printf("Outro eleitor ira votar?");
            getchar();
            scanf("%c", &escolha);
        }

    }

    return 0;
}

#define tam 5
