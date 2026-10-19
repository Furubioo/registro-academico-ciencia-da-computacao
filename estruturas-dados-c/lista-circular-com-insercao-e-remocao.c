#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *ant;
    int info;
    struct node *prox;
}Node;

typedef struct ldec{
    Node *inicio;
    int qtd;
    Node *fim;
}LDEC;

void initialize(LDEC *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

void exibirOpcao(){
    printf("\n1-inserir valor no inicio\n");
    printf("2- Inserir valor no final\n");
    printf("3- Exibir lista\n");
    printf("4- Remover primeiro\n");
    printf("5- Remover ultimo\n");
    printf("6- Remover valor\n");
    printf("7- Remover tudo\n");
    printf("0- Sair do programa");
    printf("\n\nInfome a opcao:");
}

Node* procurar(LDEC *l,int valor){
    Node *aux;
    aux = l->inicio;
    if(l->inicio == NULL){
        return NULL;
    }
    
    do{
        if(aux->info == valor){
            return aux;
        }
        else{
            aux = aux->prox;
        }
    }while(aux != l->inicio);
    return NULL;
}

void inserirInicio(LDEC *l,int valor){
    Node *novo;
    if(procurar(l,valor) == NULL){
        novo = (Node*)malloc(sizeof(Node));
        novo->info = valor;
        if(l->qtd == 0){
            l->inicio = novo;
            l->fim = novo;
            l->qtd = 1;
            l->inicio->ant = l->fim;
            l->fim->prox = l->inicio;
        }
        else{
          novo->prox = l->inicio;
          l->inicio->ant = novo;
          l->inicio = novo;

          l->inicio->ant = l->fim;
          l->fim->prox = l->inicio;
          (l->qtd)++;
        }
    }
    else{
        printf("Valor repetido!!\n");
    }
}

void inserirFinal(LDEC *l,int valor){
    Node *novo;
    if(procurar(l,valor) == NULL){
        novo = (Node*)malloc(sizeof(Node));
        novo->info = valor;

        if(l->qtd == 0){
            l->inicio = novo;
            l->fim = novo;
            l->qtd = 1;
            l->inicio->ant = l->fim;
            l->fim->prox = l->inicio;
        }
        else{
            l->fim->prox = novo;
            novo->ant = l->fim;
            l->fim = novo;

            l->inicio->ant = l->fim;
            l->fim->prox = l->inicio;
            (l->qtd)++;
        }
    }
    else{
        printf("Valor repetido!!\n");
    }
}

void removerInicio(LDEC *l){
    Node *aux;
    aux = l->inicio;

    if(l->qtd == 0){
        printf("Lista está vazia!!\n");
    }
    else if(l->qtd == 1){
        free(aux);
        l->inicio = NULL;
        l->fim = NULL;
        l->qtd = 0;
    }
    else{
        l->inicio = aux->prox;
        free(aux);
        l->inicio->ant = l->fim;
        l->fim->prox = l->inicio;
        (l->qtd)--;
    }
}

void removerFinal(LDEC *l){
    Node *aux;
    aux = l->fim;

    if(l->qtd == 0){
        printf("Lista vazia!!\n");
    }
    else if(l->qtd == 1){
        free(aux);
        l->inicio = NULL;
        l->fim = NULL;
        l->qtd = 0;
    }
    else{
        l->fim = aux->ant;
        free(aux);
        l->inicio->ant = l->fim;
        l->fim->prox = l->inicio;
        (l->qtd)--;
    }
}

void removerValor(LDEC *l,int valor){
    Node *aux;
    aux = procurar(l,valor);

    if(l->qtd == 0){
        printf("Lista vazia!!\n");
    }
    else if(aux != NULL){
        if(l->qtd == 1){
            free(aux);
            l->inicio = NULL;
            l->fim = NULL;
            l->qtd = 0;
        }
        else if(aux == l->inicio){
            l->inicio = aux->prox;
            free(aux);
            l->inicio->ant = l->fim;
            l->fim->prox = l->inicio;
            (l->qtd)--;
        }
        else if(aux == l->fim){
            l->fim = aux->ant;
            free(aux);
            l->inicio->ant = l->fim;
            l->fim->prox = l->inicio;
            (l->qtd)--;
        }
        else{
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux);
            (l->qtd)--;
        }
    }
    else{
        printf("Valor nao encontrado na lista!!\n");
    }
}

void exibir(LDEC l){
    Node *aux;
    aux = l.inicio;
    if(l.qtd == 0){
        printf("Lista vazia!!\n");
        return;
    }
    do{
        printf("%d ",aux->info);
        aux = aux->prox;

    }while(aux != l.inicio);
}

void removerTudo(LDEC *l){
    Node *aux,*aux1;
    aux = l->inicio;
    if(l->qtd == 0){
        return;
    }
    do{
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    }while(aux != l->inicio);
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int main(){
    LDEC lista;
    initialize(&lista);
    int op,num1,num2,num3;
    do{
        exibirOpcao();
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("informe o valor: ");
                scanf("%d",&num1);
                inserirInicio(&lista,num1);
                break;

            case 2:
                printf("Informe o valor: ");
                scanf("%d",&num2);
                inserirFinal(&lista,num2);
                break;

            case 3:
                exibir(lista);
                break;

            case 4:
                removerInicio(&lista);
                break;

            case 5:
                removerFinal(&lista);
                break;

            case 6:
                printf("Informe o valor que deseja remover: ");
                scanf("%d",&num3);
                removerValor(&lista,num3);
                break;

            case 7:
                removerTudo(&lista);
                break;

            case 0:
                printf("Bye bye!!!");
                break;
        }

    }while(op != 0);
    return 0;
}
