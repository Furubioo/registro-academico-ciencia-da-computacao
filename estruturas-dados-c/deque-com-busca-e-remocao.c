#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct dequeNode{
    int info;
    struct dequeNode *prox;
}DequeNode;

typedef struct deque{
    DequeNode *inicio;
    DequeNode *fim;
}Deque;

void Initialize(Deque *d){
    d->inicio = NULL;
    d->fim = NULL;
}

int IsEmpty(Deque d){
    if(d.inicio == NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int IsFull(Deque d){
    (void)d;
    return FALSE;
}


void Push(Deque *d,int valor){
    DequeNode *aux;
    aux = (DequeNode*)malloc(sizeof(DequeNode));
    aux->info = valor;
    aux->prox = NULL;
    
    if(d->inicio == NULL && d->fim == NULL){
        d->inicio = aux;
        d->fim = aux;
    }
    else{
        aux->prox = d->inicio;
        d->inicio = aux;
    }
}

int Pop(Deque *d){
    DequeNode *aux;
    int valor;
    aux = d->inicio;
    valor = aux->info;

    if(aux->prox == NULL){
        d->fim = NULL;
    }
    
    d->inicio = aux->prox;
    free(aux);
    return valor;
}

void Inject(Deque *d,int valor){
    DequeNode *aux;
    aux =(DequeNode*)malloc(sizeof(DequeNode));
    aux->info = valor;
    aux->prox = NULL;

    if(d->fim == NULL && d->inicio == NULL){
        d->inicio = aux;
        d->fim = aux;
    }
    else{
        d->fim->prox = aux;
        d->fim = aux;
    }
}

int Eject(Deque *d){
    DequeNode *aux,*aux1;
    int valor;
    aux = d->inicio;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    valor = aux->info;
    aux1 = d->inicio;

    while(aux1->prox != NULL && aux1->prox != d->fim){
        aux1 = aux1->prox;
    }
    d->fim = aux1;
    d->fim->prox = NULL;
    free(aux);

    return valor;
}

DequeNode* busca(Deque d,int valor){
    DequeNode* aux;
    aux = d.inicio;
    while(aux != NULL){
        if(aux->info == valor){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void removerValor(Deque *d,int valor){
    DequeNode *aux,*aux1,*result;
    result = busca(*d,valor);
    aux = d->inicio;

    if(result == NULL){
        printf("O valor nao foi encontrado.\n");
    }
    else{

        if(result == d->inicio && result == d->fim){
            free(result);
            d->inicio = NULL;
            d->fim = NULL;
        }

        else if(result == d->inicio){
            d->inicio = d->inicio->prox;
            free(result);
        }

        else if (result == d->fim){
            while(aux->prox != d->fim){
                aux = aux->prox;
            }
            free(d->fim);
            d->fim = aux;
            aux->prox = NULL;
        }

        else{
            while(aux->prox != result){
                aux = aux->prox;
            }
            aux1 = result;
            free(aux1);
            aux->prox = result->prox;
            
        }
    }
}

void exibir(Deque d){
    DequeNode* aux;
    aux = d.inicio;

    while(aux != NULL){
        printf("%d ",aux->info);
        aux = aux->prox;
    }
}


void Destroy(Deque *d){
    DequeNode *aux,*aux1;
    if(d->inicio == NULL){
        return;
    }
    aux = d->inicio;
    while(aux->prox != NULL){
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    }
    free(aux);
    d->inicio = NULL;
    d->fim = NULL;
}

void ExibirOpcoes() {

    printf("\nOpcoes: \n \n");
    printf("1 - Push \n");
    printf("2 - Pop \n");
    printf("3 - Inject \n");
    printf("4 - Eject \n");
    printf("5 - Remover valor \n");
    printf("6 - Exibir \n");
    printf("0 - Encerrar programa \n");
    printf("\nInforme a opcao desejada: ");

}

int main() {

    Deque minhaDeque;
    int op, num, retorno,valor;
    Initialize(&minhaDeque);

    do {
        ExibirOpcoes();
        scanf("%d", &op);

        switch(op) {
            case 1:
                if (IsFull(minhaDeque) == FALSE) {
                    printf("Informe o valor: ");
                    scanf("%d", &num);
                    Push(&minhaDeque, num);
                }
                else {
                    printf("\nDeque cheia! \n");
                }
                break;
            case 2:
                if (IsEmpty(minhaDeque) == FALSE) {
                    retorno = Pop(&minhaDeque);
                    printf("\nValor retirado: %d \n", retorno);
                }
                else {
                    printf("\nDeque vazia! \n");
                }
                break;
            case 3:
                if (IsFull(minhaDeque) == FALSE) {
                    printf("Informe o valor: ");
                    scanf("%d", &num);
                    Inject(&minhaDeque, num);
                }
                else {
                    printf("\nDeque cheia! \n");
                }
                break;
            case 4:
                if (IsEmpty(minhaDeque) == FALSE) {
                    retorno = Eject(&minhaDeque);
                    printf("\nValor retirado: %d \n", retorno);
                }
                else {
                    printf("\nDeque vazia!\n");
                }
                break;
            

            case 5:
                if(IsEmpty(minhaDeque) == FALSE){
                    printf("Digite o valor a ser removido: ");
                    scanf("%d",&valor);
                    removerValor(&minhaDeque,valor);
                    printf("Valor removido!! \n");
                }
                else{
                    printf("Deque vazia. \n");
                }    
                break;

            case 6:
                exibir(minhaDeque);
                break;
                
            case 0:
                Destroy(&minhaDeque);
                printf("\nBye bye \n\n");
                break;

            default:
                printf("\nOpcao invalida \n");
                break;
        }

    }   while(op != 0);

    return 0;
}

