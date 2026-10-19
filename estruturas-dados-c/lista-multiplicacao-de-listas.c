#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *ant;
    int info;
    struct node *prox;
}Node;

typedef struct lista{
    Node *inicio;
    int qtd;
    Node *fim;
}Lista;

void initialize(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

void inserirFinal(Lista *l,int valor){
    Node *novo;
    novo = (Node*)malloc(sizeof(Node));
    novo->info = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if(l->inicio == NULL && l->fim == NULL){
        l->inicio = novo;
        l->fim = novo;
        l->qtd = 1;
    }
    else{
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
        (l->qtd)++;
    }
}

void multiplicar(Lista *l,Lista *l1,Lista *l2){
    Node *aux1,*aux2;
    int result;
    aux1 = l1->inicio;
    aux2 = l2->inicio;

        while(aux1 != NULL && aux2 != NULL){
            result = aux1->info * aux2->info;
            inserirFinal(l,result);

            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
       
        while(aux1 != NULL){
            inserirFinal(l,aux1->info);
            aux1 = aux1->prox;
        }
        while(aux2 != NULL){
            inserirFinal(l,aux2->info);
            aux2 = aux2->prox;
        }
}

void exibir(Lista l){
    Node *aux;
    aux = l.inicio;
    while(aux != NULL){
        printf("%d ",aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void preencher(Lista *l,int qtd){
    int i,valor;
    for(i = 0; i < qtd; i++){
        printf("Informe o valor %d: ",i + 1);
        scanf("%d",&valor);
        inserirFinal(l,valor);
    }
}

int main(){
    Lista l1,l2,resultado;
    int qtd;

    initialize(&l1);
    initialize(&l2);
    initialize(&resultado);

    printf("Quantos elementos cada lista vai ter? ");
    scanf("%d",&qtd);

    printf("Preencha a lista 1:\n");
    preencher(&l1,qtd);

    printf("Preencha a lista 2:\n");
    preencher(&l2,qtd);

    multiplicar(&resultado,&l1,&l2);

    printf("Lista 1: ");
    exibir(l1);
    printf("Lista 2: ");
    exibir(l2);
    printf("Resultado da multiplicacao: ");
    exibir(resultado);

    return 0;
}