#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct no {
    int info;
    struct no *prox;
} No;

typedef struct lista {
    No *inicio;
    No *fim;
    int qtd;
} Lista;

void initialize(Lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

void inserirFinal(Lista *l, int v) {

    No *aux;

    aux = (No*) malloc(sizeof(No));
    aux->info = v;
    aux->prox = NULL;
    if (l->qtd == 0) {
        l->inicio = aux;
        l->fim = aux;
    }
    else {
        l->fim->prox = aux;
        l->fim = aux;
    }
    (l->qtd)++;

}

void preencherLista(Lista *l) {

    int valor;

    do {
        printf("Obs.: 0 Encerra o preenchimento\n");
        printf("Digite um valor: ");
        scanf("%d", &valor);

        if (valor == 0) {
            return;
        }

        inserirFinal(l, valor);
        printf("Valor inserido!\n\n");

    } while (valor != 0);

}

No* busca(Lista l, int v) {

    No *aux;

    aux = l.inicio;

    while (aux != NULL) {
        if (aux->info == v) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}


void inserirFinalSemRepetidos(Lista *l, int v) {

    if (busca(*l, v) == NULL) {
        inserirFinal(l,v);
    }

}


void uniao(Lista l1, Lista l2, Lista *l3) {

    No *aux;

    aux = l1.inicio;
    while (aux != NULL) {
        inserirFinalSemRepetidos(l3, aux->info);
        aux = aux->prox;
    }

    aux = l2.inicio;
    while (aux != NULL) {
        inserirFinalSemRepetidos(l3, aux->info);
        aux = aux->prox;
    }

}

void interseccao(Lista l1, Lista l2, Lista *li) {

    No *aux, *aux1;

    aux = l1.inicio;
    aux1 = l2.inicio;

    while (aux != NULL) {
        aux1 = l2.inicio;
        while (aux1 != NULL) {
            if (aux->info == aux1->info) {
                inserirFinalSemRepetidos(li, aux->info);
            }
            aux1 = aux1->prox;
        }
        aux = aux->prox;
    }
}

void diferenca(Lista l1, Lista l2, Lista *ld) {

    No *aux, *aux1;

    aux = l1.inicio;
    aux1 = l2.inicio;
    int cont = 0;

    while (aux != NULL) {
        aux1 = l2.inicio;
        while (aux1 != NULL) {
            if (aux->info == aux1->info) {
                cont++;
            }
            aux1 = aux1->prox;
        }
        if (cont == 0) {
            inserirFinalSemRepetidos(ld, aux->info);
        }
        cont = 0;
        aux = aux->prox;
    }
}

void exibirLista(Lista l) {

    No *aux;
    aux = l.inicio;

    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }

}

int main() {

    Lista lista1, lista2, listaUniao, listaInterseccao, listaDiferenca;

    initialize(&lista1);
    initialize(&lista2);
    initialize(&listaUniao);
    initialize(&listaInterseccao);
    initialize(&listaDiferenca);

    printf("Preenchendo lista 1: \n\n");
    preencherLista(&lista1);
    printf("\nPreenchendo lista 2: \n\n");
    preencherLista(&lista2);

    printf("\n\nLista 1: \n");
    exibirLista(lista1);

    printf("\n\nLista 2: \n");
    exibirLista(lista2);

    uniao(lista1, lista2, &listaUniao);
    printf("\n\nLista de uniao: \n");
    exibirLista(listaUniao);

    interseccao(lista1, lista2, &listaInterseccao);
    printf("\n\nLista de interseccao: \n");
    exibirLista(listaInterseccao);

    diferenca(lista1, lista2, &listaDiferenca);
    printf("\n\nLista de diferenca: \n");
    exibirLista(listaDiferenca);
    printf("\n\n");







    return 0;
}
