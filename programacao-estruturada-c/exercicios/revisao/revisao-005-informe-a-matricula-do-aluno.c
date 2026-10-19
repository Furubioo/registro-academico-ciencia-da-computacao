#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 3

typedef struct aluno {

    char matricula[15];
    char nome[51];
    float media;
    int faltas;

} Aluno;

void leituraS(char nome[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
        }
    }

}

void preencher(Aluno vet[]) {

    int i;

    for (i = 0; i < TAM; i++) {
        printf("\nInforme a matricula do aluno %d: ", i + 1);
        fgets(vet[i].matricula, 15, stdin);
        leituraS(vet[i].matricula, strlen(vet[i].matricula));
        
        printf("Informe o nome do aluno %d: ", i + 1);
        fgets(vet[i].nome, 51, stdin);
        leituraS(vet[i].nome, strlen(vet[i].nome));

        printf("Informe a media do aluno %d: ", i + 1);
        scanf("%f", &vet[i].media);

        printf("Informe as faltas do aluno %d: ", i + 1);
        scanf("%d", &vet[i].faltas);
        
        getchar();
        
    }

}

void criar(Aluno todos[], Aluno rep[], Aluno apr[], Aluno rec[], int *contrep, int *contapr, int *contrec) {

    int i;

    for (i = 0; i < TAM; i++) {
        if (todos[i].media < 3) {
            rep[*contrep] = todos[i];
            (*contrep)++;
        }
        if (todos[i].media >= 7) {
            apr[*contapr] = todos[i];
            (*contapr)++;
        }
        if (todos[i].media >= 3 && todos[i].media < 7) {
            rec[*contrec] = todos[i];
            (*contrec)++;
        }
    }
}

void exibir(Aluno vet[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        printf("\nMatricula do aluno: %s \n", vet[i].matricula);
        printf("Nome do aluno: %s \n", vet[i].nome);
        printf("Media do aluno: %.2f \n", vet[i].media);
        printf("Faltas do aluno: %d \n \n", vet[i].faltas);
    }

}

int main() {

    Aluno alunos[TAM], reprovados[TAM], aprovados[TAM], recuperacao[TAM];
    int cont1 = 0, cont2 = 0, cont3 = 0;

    preencher(alunos);

    criar(alunos, reprovados, aprovados, recuperacao, &cont1, &cont2, &cont3);

    printf("\nTodos os alunos: \n\n");
    exibir(alunos, TAM);
    printf("\nAlunos reprovados: \n\n");
    exibir(reprovados, cont1);
    printf("\nAlunos aprovados: \n\n");
    exibir(aprovados, cont2);
    printf("\nAlunos em recuperacao: \n\n");
    exibir(recuperacao, cont3);



    return 0;
}


