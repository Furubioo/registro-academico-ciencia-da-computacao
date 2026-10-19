#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct no {
    int info;
    struct no *prox;

} No;

typedef struct queueInt {
    No *inicio;
    No *fim;

} QueueInt;

void Initialize(QueueInt *f) {

    f->inicio = NULL;
    f->fim = NULL;

}

int IsEmpty(QueueInt f) {

    if (f.inicio == NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }

}

int IsFull(QueueInt f) {

    (void) f;
    return FALSE;

}

void Enqueue(QueueInt *f, int v) {

    No *aux;

    aux = (No*) malloc(sizeof(No));
    aux->info = v;
    aux->prox = NULL;

    if (f->inicio == NULL) {

        f->inicio = aux;
        f->fim = aux;

    }
    else {

        f->fim->prox = aux;
        f->fim = aux;

    }

}

int Dequeue(QueueInt *f) {

    No *aux;
    int valor;

    aux = f->inicio;
    valor = aux->info;
    f->inicio = aux->prox;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(aux);

    return valor;

}

int Head(QueueInt f) {

    return f.inicio->info;

}

void ExibirOpcoes() {

    printf("1 - Enfileirar \n");
    printf("2 - Desenfileirar \n");
    printf("3 - Ver o inicio da fila \n");
    printf("0 - Encerrar o programa \n");
    printf("\nDigite o que deseja: ");

}

int main() {

    QueueInt minhaFila;
    int op, n, v, i;

    Initialize(&minhaFila);

    do {
        ExibirOpcoes();
        scanf("%d", &op);

        switch(op) {

            case 1:
                if (IsFull(minhaFila) == FALSE) {
                    printf("\nDigite o valor: ");
                    scanf("%d", &n);
                    Enqueue(&minhaFila, n);
                }
                else {
                    printf("\nFila cheia!\n");
                }
                break;

            case 2:
                if (IsEmpty(minhaFila) == TRUE) {
                    printf("\nFila vazia! \n");
                }
                else {
                    v = Dequeue(&minhaFila);
                    printf("\nValor desenfileirado: %d \n", v);
                }
                break;

            case 3:
                if (IsEmpty(minhaFila) == FALSE) {
                    i = Head(minhaFila);
                    printf("\nInicio da fila: %d \n", i);
                }
                else {
                    printf("\nFila vazia!\n");
                }
                break;

            default:
                break;
        }

    } while(op != 0);

    return 0;
}