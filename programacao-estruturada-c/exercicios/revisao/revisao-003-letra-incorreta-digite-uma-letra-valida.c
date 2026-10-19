#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 3
#define TAM1 10

void leituraS(char nome[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
        }
    }

    
}

void preenchergab(char gab[]) {

    int i;

    for (i = 0; i < TAM1; i++) {
        printf("Digite o gabarito para a questao %d: ", i + 1);
        scanf("%c", &gab[i]);
        getchar();
        gab[i] = tolower(gab[i]);
        while (gab[i] > 'e') {
            printf("Letra incorreta! Digite uma letra valida: ");
            scanf("%c", &gab[i]);
            getchar();
        }
    }

}

void preenchermatvet(char resp[TAM][TAM1], char nomes[TAM][81]) {

    int i, j;

    for (i = 0; i < TAM; i++) {
        printf("\nDigite o nome do aluno %d: ", i + 1);
        fgets(nomes[i], 81, stdin);
        leituraS(nomes[i], strlen(nomes[i]));
        for (j = 0; j < TAM1; j++) {
            printf("Informe a resposta de %s para a questao %d: ", nomes[i], j + 1);
            scanf("%c", &resp[i][j]);
            getchar();
            resp[i][j] = tolower(resp[i][j]);

            while (resp[i][j] > 'e') {
                printf("Letra incorreta! Digite uma letra valida: ");
                scanf("%c", &resp[i][j]);
                getchar();
            }

        }
    }

}

void calculo(char resp[TAM][TAM1], char gab[], int acertos[]) {

    int i,j;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM1; j++) {
            if (resp[i][j] == gab[j]) {
                acertos[i]++;
            }
        }
    }

}

void exibir(char nomes[TAM][81], int ac[]) {

    int i;

    for (i = 0; i < TAM; i++) {
        if (ac[i] >= 7) {
            printf("O aluno %s obteve a nota %d e esta aprovado. \n\n", nomes[i], ac[i]);
        }
        else {
            printf("O aluno %s obteve a nota %d e esta reprovado. \n\n", nomes[i], ac[i]);

        }
    }
}

int main() {


    char gabarito[TAM1], respostas[TAM][TAM1], nomes[TAM][81];
    int acertos[TAM] = {0};

    preenchergab(gabarito);
    preenchermatvet(respostas, nomes);
    calculo(respostas, gabarito, acertos);
    exibir(nomes, acertos);

    return 0;
}


// Prova 2º gq 1 chamada

// Questão 1

