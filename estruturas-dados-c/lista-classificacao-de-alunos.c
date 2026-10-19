#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[101];
    int matricula;
    float media;
    int qtdFaltas;
} Aluno;

typedef struct node {
    Aluno info;
    struct node *prox;
    struct node *ant;
} Node;

typedef struct ldec {
    Node *inicio;
    Node *fim;
    int qtd;
} LDEC;

void initialize(LDEC *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

void inserirFinal(LDEC *l, Aluno a) {
    Node *aux;

    aux = (Node*) malloc(sizeof(Node));
    aux->info = a;
    if (l->qtd == 0) {
        l->inicio = aux;
        l->fim = aux;
        l->inicio->ant = l->fim;
        l->fim->prox = l->inicio;
        (l->qtd)++;
    }
    else {
        aux->ant = l->fim;
        l->fim->prox = aux;
        l->fim = aux;
        l->inicio->ant = l->fim;
        l->fim->prox = l->inicio;
        (l->qtd)++;
    }
    
}

void classificar(LDEC l1, LDEC *l2, LDEC *l3, LDEC *l4) {
    Node *aux;
    aux = l1.inicio;

    if (l1.qtd == 0) {
        printf("Impossivel classificar!\n");
        return;
    }

    do {
        if (aux->info.media >= 7 && aux->info.qtdFaltas <= 18) {
            inserirFinal(l2, aux->info);
        }
        else if (aux->info.media < 7 && aux->info.qtdFaltas <= 18) {
            inserirFinal(l3, aux->info);
        }
        else if (aux->info.qtdFaltas > 18) {
            inserirFinal(l4, aux->info);
        }
        aux = aux->prox;
    } while(aux != l1.inicio);

}

void leituraSegura(char nome[]) {
    int i, tam = strlen(nome);

    for (i = 0 ; i < tam; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
        }
    }
}

void exibirAluno(LDEC l) {
    Node *aux;
    aux = l.inicio;

    if (l.qtd == 0) {
        printf("Lista vazia!\n");
        return;
    }

    do {
        printf("\nNome: %s\n", aux->info.nome);
        printf("Matricula: %d\n", aux->info.matricula);
        printf("Media: %.2f\n", aux->info.media);
        printf("Qtd de faltas: %d\n\n", aux->info.qtdFaltas);
        aux = aux->prox;
    } while (aux != l.inicio);

}

void exibirOpcoes() {
    printf("\n\nOpcoes: \n");
    printf("1 - Preencher turma\n");
    printf("2 - Ver alunos aprovados\n");
    printf("3 - Ver alunos reprovados por media\n");
    printf("4 - Ver alunos reprovados por falta\n");
    printf("5 - Classificar alunos\n");
}

int main() {

    LDEC lista, aprovados, 
    reprovadosMedia, reprovadosFalta;

    Aluno a;
    int op;

    initialize(&lista);
    initialize(&aprovados);
    initialize(&reprovadosMedia);
    initialize(&reprovadosFalta);

    do {
        exibirOpcoes();
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);
        getchar();
        switch(op) {
            case 1:
                printf("Digite o nome do aluno: ");
                fgets(a.nome, 101, stdin);
                leituraSegura(a.nome);
                printf("Digite a matricula do aluno: ");
                scanf("%d", &a.matricula);
                printf("Digite a media do aluno: ");
                scanf("%f", &a.media);
                printf("Digite a qtd de faltas do aluno: ");
                scanf("%d", &a.qtdFaltas);
                getchar();
                inserirFinal(&lista, a);
                break;
            case 2:
                exibirAluno(aprovados);
                break;
            case 3:
                exibirAluno(reprovadosMedia);
                break;
            case 4:
                exibirAluno(reprovadosFalta);
                break;
            case 5:
                classificar(lista, &aprovados, &reprovadosMedia, &reprovadosFalta);
                printf("Alunos classificados!\n");
                break;
            case 0:
                printf("FIM");
                break;
            default:
                printf("Opcao invalida");
        }
    } while(op != 0);
    return 0;
}

