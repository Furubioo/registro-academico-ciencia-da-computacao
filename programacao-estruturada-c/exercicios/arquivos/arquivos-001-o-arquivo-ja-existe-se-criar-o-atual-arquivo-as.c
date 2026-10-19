#include <stdio.h>
#include <string.h>

void leituraS(char vet[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        if (vet[i] == '\n') {
            vet[i] = '\0';
        }
    }

}

int main() {

    FILE *arquivo;
    char nomearq[31];
    char escolha[4];
    int status;

    printf("Digite o nome do arquivo que sera criado e o tipo(.dat;.docx...): ");
    fgets(nomearq, 31, stdin);
    leituraS(nomearq, strlen(nomearq));

    arquivo = fopen(nomearq, "rb");

    if (arquivo != NULL) {
        printf("O arquivo ja existe! Se criar o atual arquivo, as informacoes do anterior serao perdidas. \n");
        printf("Deseja cria-lo? ");
        fgets(escolha, 4, stdin);
        leituraS(escolha, 4);
        if (strcmp(escolha, "nao") == 0) {
            printf("O arquivo nao foi criado. \n\n");
            fclose(arquivo);
            return 0;
        }
    }

        arquivo = fopen(nomearq, "w+b");

        if (arquivo == NULL) {
            printf("Erro ao criar o arquivo '%s'! \n", nomearq);
        }
        else {
            printf("\nArquivo %s criado com sucesso. \n\n", nomearq);
        }

        status = fclose(arquivo);

        if (status == 0) {
            printf("Arquivo %s fechado com sucesso. \n\n", nomearq);
        }
        else {
            printf("Erro ao tentar fechar o arquivo %s. \n", nomearq);
        }

    return 0;

}

// Lista 2 de arquivos

// Questão 1

