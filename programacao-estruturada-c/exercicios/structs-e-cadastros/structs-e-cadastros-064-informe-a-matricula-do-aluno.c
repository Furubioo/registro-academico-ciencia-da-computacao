#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 3


typedef struct cadastro {

    char matricula[15];
    char nome[51];
    float media;
    int faltas;


} Cadastro;

void leituraS(char nome[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
        }
    }

}

void preencher(Cadastro vet[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        printf("\nInforme a matricula do aluno %d: ", i + 1);
        fgets(vet[i].matricula, 15, stdin);
        leituraS(vet[i].matricula, strlen(vet[i].matricula));

        printf("Informe o nome do aluno %d: ", i + 1);
        fgets(vet[i].nome, 51, stdin);
        leituraS(vet[i].nome, strlen(vet[i].nome));

        printf("Informe a media do aluno %d: ", i + 1);
        scanf("%f", &vet[i].media);

        printf("Informe a qtd de faltas do aluno %d: ", i + 1);
        scanf("%d", &vet[i].faltas);

        getchar();
    }

}

void verifica(Cadastro alunos[], Cadastro rep[], Cadastro apr[], Cadastro rec[], int *c1, int *c2, int *c3) {

    int i;

    for (i = 0; i < TAM; i++) {
        if (alunos[i].media < 3) {
            rep[*c1] = alunos[i];
            (*c1)++;
        }
        if (alunos[i].media >= 7) {
            apr[*c2] = alunos[i];
            (*c2)++;
        }
        if (alunos[i].media < 7 && alunos[i].media >= 3) {
            rec[*c3] = alunos[i];
            (*c3)++;
        }

    }

}

void exibir(Cadastro vet[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        printf("\nMatricula do aluno(a): %s \n", vet[i].matricula);
        printf("Nome do aluno(a): %s \n", vet[i].nome);
        printf("Media do aluno(a): %.2f \n", vet[i].media);
        printf("Faltas do aluno(a): %d \n", vet[i].faltas);
    }

}

int main() {

    int cont1 = 0, cont2 = 0, cont3 = 0;

    Cadastro alunos[TAM], reprovados[TAM], aprovados[TAM], recup[TAM];

    printf("Preenchimento das informacoes dos alunos: \n\n");

    preencher(alunos, TAM);
    verifica(alunos, reprovados, aprovados, recup, &cont1, &cont2, &cont3);
    
    printf("\nAluno(s) aprovado(s): \n");
    exibir(aprovados, cont2);
    
    printf("\nAluno(s) em recuperacao: \n");
    exibir(recup, cont3);

    printf("\nAluno(s) reprovado(s): \n");
    exibir(reprovados, cont1);



    return 0;

}























































