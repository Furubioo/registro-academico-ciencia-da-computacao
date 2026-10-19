#include <stdio.h>
#include <string.h>
#include <ctype.h>


typedef struct produto {
    
    char codigo[10];
    char descricao[50];
    float preco;
    int estoque;

} Produto;

void leituraS(char nome[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
        }
    }
}


void preencher(Produto *prod) {

    printf("Informe o codigo do produto: ");
    fgets(prod->codigo, 10, stdin);
    leituraS(prod->codigo, strlen(prod->codigo)); 
    
    
    printf("Informe a descricao do produto: ");
    fgets(prod->descricao, 50, stdin);
    leituraS(prod->descricao, strlen(prod->descricao)); 
    

    printf("Informe o preco do produto: ");
    scanf("%f", &prod->preco); 
    

    printf("Informe o estoque do produto: ");
    scanf("%d", &prod->estoque); 
    
    getchar();

}

FILE* verificaArquivo(char nome[]) {

    FILE *aux;
    aux = fopen(nome, "r+b");

    if (aux == NULL) {
        aux = fopen(nome, "w+b");
    }

    return aux;

}

void gravarregistro(FILE *arq, Produto prod) {

    int status;

    status = fwrite(&prod, sizeof(Produto), 1, arq);

    if (status == 1) {
        printf("Registro gravado com sucesso. \n");
    }
    else {
        printf("Erro na gravacao do registro. \n");
    }

}

int main() {

    FILE *arq;
    char nomeArq[] = "produtos.dat";
    int status;
    char resp;
    Produto aux;
    arq = verificaArquivo(nomeArq);

    if (arq == NULL) {
        printf("Erro ao tentar criar ou abrir o arquivo");
    }
    else {
        fseek(arq, 0, SEEK_END);
        do {
            preencher(&aux);
            gravarregistro(arq, aux);

            printf("Deseja grava os dados de outro produto? Digite s ou n: ");
            scanf("%c", &resp);
            getchar();
            resp = tolower(resp);

        } while (resp != 'n');

        status = fclose(arq);
        if (status == 0) {
            printf("Arquivo fechado com sucesso! \n");
        }
        else {
            printf("Erro ao fechar o arquivo! \n");
        }
    }

    return 0;
}

// Questão 2

