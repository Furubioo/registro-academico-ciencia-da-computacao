#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct dequeNode {

    int info;
    struct dequeNode *prox;

}   DequeNode;

typedef struct deque {

    DequeNode *inicio;
    DequeNode *fim;

}   Deque;

void Initialize(Deque *d) {

    d->inicio = NULL;
    d->fim = NULL;

}

int IsEmpty(Deque d) {

    if (d.inicio == NULL && d.fim == NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }

}

int IsFull(Deque d) {
    (void) d;
    return FALSE;
}

void Push(Deque *d, int v) {
    DequeNode *aux = (DequeNode*) malloc(sizeof(DequeNode));
    aux->info = v;
    aux->prox = d->inicio; 
    d->inicio = aux;       


    if (d->fim == NULL) {
        d->fim = aux;
    }
}

int Pop(Deque *d) {
    DequeNode *aux = d->inicio;
    int valor = aux->info;
    
    d->inicio = aux->prox; 
    
    if (d->inicio == NULL) {
        d->fim = NULL;
    }
    
    free(aux);
    return valor;
}

void Inject(Deque *d, int v) {
    DequeNode *aux = (DequeNode*) malloc(sizeof(DequeNode));
    aux->info = v;
    aux->prox = NULL; 

    if (d->fim == NULL) { 
        d->inicio = aux;
        d->fim = aux;
    } 
    else {
        d->fim->prox = aux; 
        d->fim = aux;       
    }
}

int Eject(Deque *d) {

    int valor = d->fim->info; 

    if (d->inicio == d->fim) {
        free(d->fim);
        d->inicio = d->fim = NULL;
        return valor;
    }

    DequeNode *aux = d->inicio;
    while (aux->prox != d->fim) {
        aux = aux->prox; 
    }

    free(d->fim);
    d->fim = aux;
    d->fim->prox = NULL;

    return valor;
}

void Destroy(Deque *d) {
    DequeNode *aux = d->inicio;
    DequeNode *temp;

    while (aux != NULL) {
        temp = aux;
        aux = aux->prox;
        free(temp);
    }
    
    d->inicio = NULL;
    d->fim = NULL;
}

void ExibirOpcoes() {

    printf("\nOpcoes: \n \n");
    printf("1 - Push \n");
    printf("2 - Pop \n");
    printf("3 - Inject \n");
    printf("4 - Eject \n");
    printf("0 - Encerrar programa \n");
    printf("\nInforme a opcao desejada: ");

}

int main() {

    Deque minhaDeque;
    int op, num, retorno;
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