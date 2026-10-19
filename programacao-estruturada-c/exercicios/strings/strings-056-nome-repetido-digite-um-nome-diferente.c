#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 5

void leituraS(char vet[][101]) {

    int i, j, tam;

    for (i = 0; i < TAM; i++) {
        tam = strlen(vet[i]);
        for (j = 0; j < tam; j++) {
            if (vet[i][j] == '\n') {
                vet[i][j] = '\0';
            }
        }
    }
      
}


void preencherVetor(char vet[][101]) {

    int i, j, k, l;
    int contL = 0;
    int contE = 0;

    for (i = 0; i < TAM; i++) {
        contE = 0;
        contL = 0;
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(vet[i], 101, stdin);
        leituraS(vet);

            for (l = 0; l < (int) strlen(vet[i]); l++) {
                if (isspace(vet[i][l])) {
                    contE++;
                }
            }

            for (k = 0; k < (int) strlen(vet[i]); k++) {
                if (isalpha(vet[i][k])) {
                    contL++;
                }
            }

            for (j = 0; j < i; j++) {
                if (strcmp(vet[i], vet[j]) == 0) {
                    printf("Nome repetido! Digite um nome diferente: ");
                    fgets(vet[i], 101, stdin);
                    leituraS(vet);
                }
                
            }

        if (contE + contL != (int) strlen(vet[i]) || contE == 0) {
            printf("Nome invalido! Digite um nome valido: ");
            fgets(vet[i], 101, stdin);
            leituraS(vet);

        }
    }
}


void ordenacao(char vet[][101]) {

    int i, fim = TAM-2; 
    int pos = 0, troca = 0;
    char chave[101];

    do {
        troca = 0;
        for (i = 0; i <= fim; i++) {            
            if (strcmp(vet[i], vet[i+1]) > 0) {

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

int busca(char vet[][101], char vet1[101]) {

    int i, j, busca = -1;

    for (j = 0; j < (int) strlen(vet1); j++) {
        if (vet1[j] == '\n') {
            vet1[j] = '\0';
        }
    }

    for (i = 0; i < TAM; i++) {
        if (strcmp(vet[i], vet1) == 0) {
            busca = 1;
            break;
        }
        

    }
    if (busca == 1) {
        return i;
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

    char vfrase[TAM][101], nomebusca[101];
    int retorno;

    printf("Lista de nomes: \n\n");
    preencherVetor(vfrase);
    printf("\nLista de nomes ordenada: \n\n");
    ordenacao(vfrase);
    exibir(vfrase);
    printf("\nDigite o nome que deseja buscar: ");
    fgets(nomebusca, 101, stdin);
    retorno = busca(vfrase, nomebusca);
    if (retorno >= 0) {
        printf("\nO nome foi encontrado na posicao %d do vetor. \n\n", retorno);
    }
    else {
        printf("\nO nome nao foi encontrado no vetor. \n\n");
    }

    return 0;
}

// Lista 2 - Ordenação e busca

