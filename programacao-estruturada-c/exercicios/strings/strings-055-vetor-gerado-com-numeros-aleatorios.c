#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verificarepetido(int vet[100], int n) {

    int i;
    int rep = 0;

    for (i = 0; i < 100; i++) {
        if (vet[i] == n) {
            rep = 1;
            break;
        }
    }

    return rep;
}

void preencherVetor(int vet[100]) {

    int i, num;

    srand(time(NULL));
    for (i = 0; i < 100; i++) {
        num = (rand() % 10000) + 1;
        if ((verificarepetido(vet, num)) == 0) {
            vet[i] = num;
        }
        else {
            while (verificarepetido(vet,num) == 1) {
                num = (rand() % 10000) + 1;
            }
        }
        vet[i] = num;

    }
}


void ordenarVetor(int vet[100]) {

    int i, fim = 98, pos = 0;
    int chave, troca;
    do{
        troca = 0;
        for (i = 0; i <= fim; i++) {
            if (vet[i] < vet[i+1]) {

                chave = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = chave;
                pos = i; 
                troca = 1;

            }
        }
        fim = pos - 1;
    }while (troca == 1);

}

int buscarValor(int vet[100], int n) {

    int i;
    int achou = -1;

    for (i = 0; i < 100; i++) {
        if (vet[i] == n) {
            achou = 1;
            break;
        }
        else if(vet[i] > n) {
            break;
        }
    }
    if (achou == 1) {
        return i;
    }
    else {
        return -1;
    }
    

}

void exibirVetor(int vet[100]) {

    int i;

    for (i = 0; i < 100; i++) {
        printf("%d \n", vet[i]);
    }

}

int main() {


    int vetor[100] = {0}, valor, a;

    printf("Vetor gerado com numeros aleatorios: \n");
    preencherVetor(vetor);
    printf("Vetor nao-ordenado: \n");
    exibirVetor(vetor);
    ordenarVetor(vetor);
    printf("\nVetor ordenado: \n");
    exibirVetor(vetor);
    printf("\nDigite o valor que deseja buscar no vetor: ");
    scanf("%d", &valor);
    a = buscarValor(vetor, valor);
    if (a >= 0) {
        printf("O valor foi encontrado na posicao %d \n\n", a);
    }
    else {
        printf("O valor nao foi encontrado no vetor. \n\n");
    }

    return 0;
}

//  Questão 2

