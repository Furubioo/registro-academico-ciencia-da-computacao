#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
//Lista TAD
 
typedef struct no {
    int info;
    struct no *prox;
} No;
 
typedef struct lista {
    No *inicio;
    No *fim;
} Lista;
 
void initialize(Lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
}
 
No* busca(Lista l, int valor) {
 
    No *aux;
    aux = l.inicio;
 
    while (aux != NULL) {
        if (aux->info == valor) {
            return aux;
        }
        aux = aux->prox;
    }
 
    return NULL;
}
 
void inserirFinal(Lista *l, int valor) {
    No *aux;
 
    if (busca(*l, valor) == NULL) {
        aux = (No*) malloc(sizeof(No));
        aux->info = valor;
        aux->prox = NULL;
        if (l->inicio == NULL && l->fim == NULL) {
           l->inicio = aux;
           l->fim = aux;
        }
        else {
           l->fim->prox = aux;
           l->fim = aux;
        }
 
    }
    else {
        printf("Valor encontrado na lista! Insira outro.\n");
    }
 
}
 
int somatorio(Lista l) {
    No *aux;
    aux = l.inicio;
    int soma = 0;
 
    while (aux != NULL) {
        soma+= aux->info;
        aux = aux->prox;
    }
    return soma;
 
}
 
void destroy(Lista *l) {
    No *aux, *aux1;
    aux = l->inicio;
 
    while (aux != NULL) {
        aux1 = aux;
        free(aux1);
        aux = aux->prox;
    }
    l->inicio = NULL;
    l->fim = NULL;
}
 
void exibirOpcoes() {
    printf("\n1 - Inserir valor na lista\n");
    printf("2 - Exibir somatorio\n");
    printf("3 - Destruir lista\n");
    printf("0 - Encerrar programa\n");
    printf("\n\nInforme a opcao desejada: ");
}
 
int main() {
 
    Lista minhaLista;
    initialize(&minhaLista);
 
    int op, valor, retorno;
 
    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch(op) {
            case 1:
               printf("Digite o valor desejado: ");
               scanf("%d", &valor); 
               if (valor > 0) {
                   inserirFinal(&minhaLista, valor);
                   printf("Valor inserido!\n");
               }
               else {
                   printf("Insira apenas valores maiores que 0!\n");
               }
               break;
            case 2:
               retorno = somatorio(minhaLista);
               printf("Valor da soma dos elementos da lista: %d", retorno);
               if (retorno == 0) {
                    printf("Nao ha valores nessa lista!");
               }
               break;
            case 3:
               destroy(&minhaLista);
               printf("Lista destruida!");
               break;
            case 0: 
               printf("Fim do programa.");
               break;
            default:
               printf("Opcao invalida!");
        }
    } while (op != 0);
 
    return 0;
}