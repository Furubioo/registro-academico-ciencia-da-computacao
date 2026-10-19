#include <stdio.h>
#define tam 50
 
void exibirOpcoes();
void insercao(int vet[], int *cont, int valor);
void exibir(int vet[], int cont);
int busca(int vet[], int *cont, int num);
 
int main() {
 
    int vetA[tam], vetB[tam];
    int num, op;
    int contA = 0, contB = 0, b1, b2, busca1, busca2;
 
    do{
       exibirOpcoes(); 
       scanf("%d", &op);
       switch(op) {
            case 1: 
                printf("Informe o valor: ");
                scanf("%d", &num);
            if (num % 2 == 0) {
                insercao(vetA, &contA, num);
            }
            else {
                insercao(vetB, &contB, num);
            }
            break;
            case 2: 
                exibir(vetA, contA);
                break;
            case 3:
                exibir(vetB, contB);
                break;
            case 4:
                printf("Informe o valor: ");
                scanf("%d", &busca1);
                b1 = busca(vetA, &contA, busca1);
                printf("Valores encontrados: %d", b1);
                break;
            case 5:
                printf("Informe o valor: ");
                scanf("%d", &busca2);
                b2 = busca(vetB, &contB, busca2);
                printf("Valores encontrados: %d", b2);
                break;

            case 0:
                printf("Fim do programa.\n");
                break;
            default:
                printf("Opcao invalida \n");
       }
    }
    while(op !=0);
 
    return 0;
}
 
void insercao(int vet[], int *cont, int valor) {
 
    if (*cont == tam) {
        printf("Vetor cheio!\n");
    }
    else {
        vet[*cont] = valor;
        (*cont)++;
        printf("Insercao efetuada!\n");
    }
 
}
 
void exibirOpcoes() {
    printf("\nOpcoes: \n\n");
    printf("1 - Inserir novo valor \n");
    printf("2 - Exibir numeros pares \n");
    printf("3 - Exibir numeros impares \n");
    printf("4 - Buscar valor em A(pares) \n");
    printf("5 - Buscar valor em B(impares) \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opcao desejada: ");
}
 
void exibir(int vet[], int cont) {
    int i;
    if (cont == 0) {
        printf("Vetor vazio!\n");
    }
    else {
        for (i = 0; i < cont; i++) {
        printf("%d   ", vet[i]);
        }
        printf("\n");
    }
}   

int busca(int vet[], int *cont, int num) {

    int i;
    int valor = 0;

    for (i = 0; i < *cont; i++) {
        if (num == vet[i]) {
            valor++;
        } 
    }
    printf("\n");

    return valor;

}

