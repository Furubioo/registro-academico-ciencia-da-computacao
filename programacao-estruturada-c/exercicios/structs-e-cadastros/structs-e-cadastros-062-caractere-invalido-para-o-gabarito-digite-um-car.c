#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 3
#define TAM1 10

void preenchergab(char gab[], int tam) {


    int i;

    for (i = 0; i < tam; i++) {
        printf("Digite o gabarito da questao %d: ", i + 1);
        scanf("%c", &gab[i]);
        getchar();

        if (gab[i] > 'e') {
            printf("Caractere invalido para o gabarito! Digite um caractere correto: ");
            scanf("%c", &gab[i]);
            getchar();

        }
    }
    
}

void leituraS(char nome[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
        }
    }


}

void preencherRespEnomes(char resp[TAM][TAM1], char nome[TAM][81]) {

    int i,j;

    for (i = 0; i < TAM; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(nome[i], 81, stdin);
        leituraS(nome[i], strlen(nome[i]));
        for (j = 0; j < TAM1; j++) {  
            printf("Informe a resposta de %s para a questao %d: ", nome[i], j + 1);
            scanf("%c", &resp[i][j]);
            getchar();
            if (resp[i][j] > 'e') {
                printf("Caractere invalido para o gabarito! Digite um caractere correto: ");
                scanf("%c", &resp[i][j]);
                getchar();
            }
        }
        
    }

}

void acertos(char resp[TAM][TAM1], char gab[], int qA[]) {

    int i, j;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM1; j++) {
            if (tolower(resp[i][j]) == tolower(gab[j])) {
                qA[i]++;
            }
        }
    }



}

void exibir(char nome[TAM][81], int qA[]) {

    int i;

    for (i = 0; i < TAM; i++) {
        if (qA[i] >= 7) {
            printf("\nO(a) aluno(a) %s obteve nota %d e esta aprovado(a). \n\n", nome[i], qA[i]);
        }
        else {
            printf("\nO(a) aluno(a) %s obteve nota %d e esta reprovado(a). \n\n", nome[i], qA[i]);
        }
        
    }
}


int main() {

    char gabarito[TAM1], respostas[TAM][TAM1], nomes[TAM][81];
    int qA[TAM] = {0};

    preenchergab(gabarito, TAM1);
    preencherRespEnomes(respostas, nomes);
    acertos(respostas, gabarito, qA);
    exibir(nomes, qA);



    return 0;
}

// 2º simulado 2º gq
// 1ª Questão

