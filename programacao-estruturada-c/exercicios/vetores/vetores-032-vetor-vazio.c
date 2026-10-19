#include <stdio.h>

void insercao(float vet[], int *contvet, int decisao) {

    int i, j;

    for (i = 0; i < 10; i++) {
        if (vet[0] == 0) {
            printf("Vetor vazio!\n");
        }
        if (vet[9] >= 1 || vet[9] < 0) {
            printf("Vetor cheio! \n");
            break;
        }
        printf("Informe o valor armazenado em [%d]: ", i);
        scanf("%f", &vet[i]);

        while (vet[i] == 0) {
            printf("Digite um valor valido!(>=1 ou <=1): ");
            scanf("%f", &vet[i]);
        }
        while (decisao == 1 && vet[i] < 0) {
            printf("Este vetor recebe apenas valores positivos.\nDigite um valor positivo em [%d]: ", i);
            scanf("%f", &vet[i]);
        }   
        while (decisao == 3 && vet[i] > 0) {
            printf("Este vetor recebe apenas valores negativos.\nDigite um valor negativo em [%d]: ", i);
            scanf("%f", &vet[i]);
        }
        (*contvet)++;
    
        if (i > 0) {
            for (j = 0; j < i; j++) {
                if (vet[i] == vet[j]) {
                    printf("Esse valor ja foi digitado.\n");
                    printf("Digite outro valor em [%d]: ", i);
                    scanf("%f", &vet[i]);
                }
            }
        }
    }
}

void exibir(float vet[], int *contvet) {

    int i;

    for (i = 0; i < *contvet; i++) {
        printf("%.2f  ", vet[i]);
    }


}

int busca(float vet[], int *contvet, float vprocura) {

    int i;
    int cont = 0;

    for (i = 0; i < *contvet; i++) {
        if (vprocura == vet[i]) {
            cont++;
            break;
        }
    }

    return cont;
    
}

void exibirOpcoes() {

    printf("\n1 - Armazenar valores no vetor A(positivos)\n");
    printf("2 - Exibir vetor A(positivos)\n");
    printf("3 - Armazenar valores no vetor B(negativos)\n");
    printf("4 - Exibir vetor B(negativos)\n");
    printf("5 - Buscar valor no vetor A\n");
    printf("6 - Buscar valor no vetor B\n");
    printf("7 - Finalizar o programa\n");

}



int main() {

    float positivos[10] = {0}, negativos[10] = {0};
    int contP = 0, contN = 0;
    float x1, x2;
    int decisao;
    
    float valprocura;

    do {
        exibirOpcoes();
        printf("\nEscolha a sua opcao: ");
        scanf("%d", &decisao);


        switch(decisao) {

            case 1:
                insercao(positivos, &contP, decisao);
                break;
            case 2: 
                exibir(positivos, &contP);
                break;
            case 3:
                insercao(negativos, &contN, decisao);
                break;
            case 4:
                exibir(negativos, &contN);
                break;
            case 5: 
                printf("Digite o valor: ");
                scanf("%f", &valprocura);
                x1 = busca(positivos, &contP, valprocura);
                if (x1 == 1) {
                    printf("O valor foi encontrado no vetor. \n");
                }
                else if (x1 == 0) {
                    printf("\nO valor nao foi encontrado no vetor. \n");
                }
                break;
            case 6:
                printf("Digite o valor: ");
                scanf("%f", &valprocura);
                x2 = busca(negativos, &contN, valprocura);
                if (x2 == 1) {
                    printf("O valor foi encontrado no vetor. \n");
                }
                else if (x2 == 0){
                    printf("O valor nao foi encontrado no vetor. \n");
                }
                break;
            case 7:
                printf("Fim do programa.\n");
                break;
//             default:
                printf("Opcao invalida! escolha outra. \n");
                break;
        
        }
    } while(decisao != 7);
    return 0;
}

