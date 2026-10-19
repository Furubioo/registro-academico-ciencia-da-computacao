#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 5

void leituraS(char vet[101], int n) {

    int i;

    for (i = 0; i < n; i++) {
        if (vet[i] == '\n') {
            vet[i] = '\0';
        }
    }

}

void preencher(char vet[][101]) {

    int i, j, k, l;
    int contL = 0, contE = 0;


    for (i = 0; i < TAM; i++) {
        contL = 0;
        contE = 0;
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(vet[i], 101, stdin);
        leituraS(vet[i], strlen(vet[i]));

        for (j = 0; j < i; j++) {
            if (strcmp(vet[i], vet[j]) == 0) {
                printf("Nome repetido! Digite outro: ");
                fgets(vet[i], 101, stdin);
                leituraS(vet[i], strlen(vet[i]));
            }
        }

        for (k = 0; k < (int) strlen(vet[i]); k++) {
            if (isalpha(vet[i][k])) {
                contL++;
            }
            if (isspace(vet[i][k])) {
                contE++;
            }
        }

        while ((contL + contE != (int) strlen(vet[i])) || contE == 0) {
            printf("Nome invalido! Digite um nome correto: ");
            fgets(vet[i], 101, stdin);
            leituraS(vet[i], strlen(vet[i]));
            for (l = 0; l < (int) strlen(vet[i]); l++) {
                if (isalpha(vet[i][l])) {
                    contL++;
                }
                if (isspace(vet[i][l])) {
                    contE++;
                }
            }
        }

    }

}

void ordenacao(char vet[][101]) {

    int i, fim = TAM-2, pos = 0, troca;
    char chave[101];

    do {
        troca = 0;
        for (i = 0; i <= fim; i++) {
            if (strcmp(vet[i], vet[i+1]) < 0) {

                strcpy(chave, vet[i]);
                strcpy(vet[i], vet[i+1]);
                strcpy(vet[i+1], chave);
                pos = i;
                troca = 1;
            }
        } 
        fim = pos - 1;

    } while (troca == 1);

}

int busca(char vet[][101], char nome[101]) {

    int inicio = 0, meio, fim = TAM-1, achou = 0;

    do {
        meio = (inicio + fim) / 2;
        if (strcmp(nome, vet[meio]) == 0) {
            achou = 1;
            break;
        }
        else if (strcmp(nome, vet[meio]) > 0) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    } while(inicio <= fim);

    if (achou == 1) {
        return meio;
    }
    else {
        return -1;
    }

}

void exibir(char vet[][101]) {

    int i;

    for (i = 0; i < TAM; i++) {
        printf("%s \n", vet[i]);
    }

}


int main() {

    char Nome[20][101], nomeBusca[101];
    int valor;

    printf("Preenchimento dos nomes: \n\n");
    preencher(Nome);
    ordenacao(Nome);
    printf("\nVetor ordenado(decrescente): \n\n");
    exibir(Nome);
    printf("\nInforme o nome que deseja buscar: ");
    fgets(nomeBusca, 101, stdin);
    leituraS(nomeBusca, strlen(nomeBusca));
    valor = busca(Nome, nomeBusca);
    if (valor >= 0) {
        printf("\nO nome foi achado na posicao %d do vetor. \n\n", valor);
    }
    else {
        printf("\nO nome nao foi encontrado no vetor. \n\n");
    }

    return 0;
}

// Lista 1 de Struct

// Questão 1

