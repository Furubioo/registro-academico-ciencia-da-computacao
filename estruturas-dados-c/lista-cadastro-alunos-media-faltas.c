#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
    char nome[100];
    float media;
    int faltas;
} Aluno;

typedef struct node {
    struct node *ante;
    Aluno info;
    struct node *prox;
} Node;

typedef struct lde {
    Node *prim;
    Node *ult;
    int qtd;
} LDE;

void initialize(LDE *l) {
    l->prim = NULL;
    l->ult = NULL;
    l->qtd = 0;
}

Node* busca(LDE *l, char nome[]) {
    Node *aux;
    aux = l->prim;
    if(l->qtd == 0){
        return NULL;
    }
    while(aux != NULL){
        if(strcmp(aux->info.nome, nome) == 0){
            return aux;
        }
        else if(strcmp(aux->info.nome, nome) > 0) {
            return NULL;
        }
        else{
            aux = aux->prox;
        }
    }
    return NULL;
}

Node* criarNode(Aluno a) {
    Node *novo;
    novo = (Node*) malloc(sizeof(Node));
    novo->info = a;
    novo->prox = NULL;
    novo->ante = NULL;
    return novo;
}

void inserir(LDE *l, Aluno a) {
    Node *aux;
    if (l->qtd == 0) {
        aux = criarNode(a);
        l->prim = aux;
        l->ult = aux;
        (l->qtd)++;
        printf("Aluno(a) inserido na lista!\n");
    }
    else {
        if (strcmp(l->prim->info.nome, a.nome) > 0) {
            aux = criarNode(a);
            aux->prox = l->prim;
            aux->ante = NULL;
            l->prim->ante = aux;
            l->prim = aux;
            (l->qtd)++;
            printf("Aluno(a) inserido na lista!\n");
        }
        else if (strcmp(l->prim->info.nome, a.nome) == 0) {
            printf("O nome ja esta na lista!\n");
        }
        else if (strcmp(l->ult->info.nome, a.nome) < 0) {
            aux = criarNode(a);
            aux->ante = l->ult;
            l->ult->prox = aux;
            aux->prox = NULL;
            l->ult = aux;
            (l->qtd)++;
            printf("Aluno(a) inserido na lista!\n");
        }
        else if (strcmp(l->ult->info.nome, a.nome) == 0) {
            printf("O nome ja esta na lista!\n");
        }
        else {
            aux = l->prim;
            while(aux != NULL){
                if(strcmp(aux->info.nome, a.nome) == 0){
                    printf("O nome ja esta na lista!\n");
                    return;
                }
                else if(strcmp(aux->info.nome, a.nome) > 0){
                    Node *aux1;
                    aux1 = criarNode(a);
                    aux1->ante = aux->ante;
                    aux1->prox = aux;
                    aux->ante->prox = aux1;
                    aux->ante = aux1;
                    (l->qtd)++;
                    printf("Aluno(a) inserido na lista!\n");
                }
                aux = aux->prox;
            }
        }
    }
}

void exibirDados(LDE l) {
    Node *aux;
    aux = l.prim;

    if (l.qtd == 0) {
        printf("Lista vazia!\n");
        return;
    }

    while (aux != NULL) {
        printf("Nome: %s\n", aux->info.nome);
        printf("Media: %f\n", aux->info.media);
        printf("Faltas: %d\n", aux->info.faltas);
        aux = aux->prox;
    }
    printf("\n");
}

void exibirDadosEspec(LDE l, char nome[]) {
    Node *retorno;

    retorno = busca(&l, nome);

    if (retorno == NULL) {
        printf("Aluno nao encontrado!\n");
    }
    else {
        printf("\nDados de %s: \n", retorno->info.nome);
        printf("Media: %f\n", retorno->info.media);
        printf("Faltas: %d\n\n", retorno->info.faltas);
    }

}

void alterarMedia(LDE *l, char nome[]) {
    Node *retorno;

    retorno = busca(l, nome);

    if (retorno == NULL) {
        printf("Aluno nao encontrado!\n");
    }
    else {
        printf("Digite a nova media para o aluno: ");
        scanf("%f", &retorno->info.media);
        printf("Media alterada!\n");
    }

}

void alterarFaltas(LDE *l, char nome[]) {
    Node *retorno;

    retorno = busca(l, nome);

    if (retorno == NULL) {
        printf("Aluno nao encontrado!\n");
    }
    else {
        printf("Digite a nova qtd de faltas para o aluno: ");
        scanf("%d", &retorno->info.faltas);
        printf("Faltas alteradas!\n");
    }
}

void removerAluno(LDE *l, char nome[]) {
    Node *aux;

    aux = busca(l, nome);

    if(aux == NULL) {
        printf("Aluno nao encontrado na lista!\n");
    }
    else {
        if (l->qtd == 1) {
            l->prim = NULL;
            l->ult = NULL;
            l->qtd = 0;
            free(aux);
            printf("Aluno removido da lista!\n");
        }
        else if (aux == l->prim) {
            l->prim = aux->prox;
            l->prim->ante = NULL;
            free(aux);
            (l->qtd)--;
            printf("Aluno removido da lista!\n");
        }
        else if (aux == l->ult) {
            l->ult = aux->ante;
            l->ult->prox = NULL;
            free(aux);
            (l->qtd)--;
            printf("Aluno removido da lista!\n");
        }
        else {
            aux->ante->prox = aux->prox;
            aux->prox->ante = aux->ante;
            free(aux);
            (l->qtd)--;
            printf("Aluno removido da lista!\n");
        }
    }
}

void esvaziarLista(LDE *l) {
    Node *aux, *aux1;
    aux = l->prim;

    while (aux != NULL) {
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    }
    l->prim = NULL;
    l->ult = NULL;
    l->qtd = 0;
}

void leituraSegura(char nome[]) {
    int i, tam = strlen(nome);

    for (i = 0; i < tam; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
        }
    }
}

void exibirOpcoes() {
    printf("\nOpcoes:\n\n");
    printf("1 - Inserir dados de um aluno\n");
    printf("2 - Exibir dados de todos os alunos\n");
    printf("3 - Exibir dados de apenas um aluno\n");
    printf("4 - Alterar media de um aluno\n");
    printf("5 - Alterar a qtd de faltas de um aluno\n");
    printf("6 - Remover um aluno da lista\n");
    printf("7 - Esvaziar lista\n");
    printf("0 - Encerrar programa");
    printf("\n\nInforme a opcao desejada: ");
}

int main() {

    LDE lista;
    int op;
    Aluno a;
    char nome[100];

    initialize(&lista);

    do {
        exibirOpcoes();
        scanf("%d", &op);
        getchar();
        switch(op) {
            case 1:
                printf("Informe o nome: ");
                fgets(a.nome, 100, stdin);
                leituraSegura(a.nome);
                printf("Informe a media: ");
                scanf("%f", &a.media);
                printf("Informe as faltas: ");
                scanf("%d", &a.faltas);
                inserir(&lista, a);
                break;
            case 2:
                printf("\nDados dos alunos: \n\n");
                exibirDados(lista);
                break;
            case 3: 
                printf("Informe o nome do aluno: ");
                fgets(nome, 100, stdin);
                leituraSegura(nome);
                exibirDadosEspec(lista, nome);
                break;
            case 4:
                printf("Informe o nome do aluno: ");
                fgets(nome, 100, stdin);
                leituraSegura(nome);
                alterarMedia(&lista, nome);
                break;
            case 5:
                printf("Informe o nome do aluno: ");
                fgets(nome, 100, stdin);
                leituraSegura(nome);
                alterarFaltas(&lista, nome);
                break;
            case 6:
                printf("Informe o nome do aluno: ");
                fgets(nome, 100, stdin);
                leituraSegura(nome);
                removerAluno(&lista, nome);
                break;
            case 7:
                esvaziarLista(&lista);
                printf("Lista esvaziada.\n");
                break;
            case 0:
                printf("FIM\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(op != 0);
    
    return 0;
}




