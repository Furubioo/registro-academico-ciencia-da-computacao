#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *ant;
    int info;
    struct node *prox;
}   Node;

typedef struct lde {
    Node *inicio;
    Node *fim;
    int qtd;
}   LDE;

void initialize(LDE *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

void exibirOpcoes() {
    printf("\nOpcoes:\n");
    printf("\n1 - Inserir um novo numero no inicio da lista\n");
    printf("2 - Inserir um novo numero no final da lista\n");
    printf("3 - Exibir todos os numeros da lista do primeiro ate o ultimo \n");
    printf("4 - Procurar por um valor na lista\n");
    printf("5 - Remover um valor especifico na lista\n");
    printf("6 - Fazer uma copia lista\n");
    printf("7 - Fazer uma copia invertida da lista\n");
    printf("8 - Esvaziar a lista\n");
    printf("0 - Sair do programa\n");
}

Node* buscar(LDE l, int v) {
    Node *aux;
    aux = l.inicio;
    while (aux != NULL) {
        if (aux->info == v) {
            return aux;
        } 
        aux = aux->prox;
    }

    return NULL;
} 

void inserirInicio(LDE *l, int v) {
    Node *aux;

    if (buscar(*l, v) == NULL) {
        aux = (Node*) malloc(sizeof(Node));
        aux->info = v;
        aux->ant = NULL;
        if (l->qtd == 0) {
            l->inicio = aux;
            l->fim = aux;
            aux->prox = NULL;
        }
        else {
            aux->prox = l->inicio;
            l->inicio->ant = aux;
            l->inicio = aux;
        }
        (l->qtd)++;
    }
    else {
        printf("Valor presente na lista! Digite outro. \n");
    }
}

void inserirFinal(LDE *l, int v) {
    Node *aux;

    if (buscar(*l, v) == NULL) {
        aux = (Node*) malloc(sizeof(Node));
        aux->info = v;
        aux->prox = NULL;
        if (l->qtd == 0) {
            l->inicio = aux;
            l->fim = aux;
            aux->ant = NULL;
        }
        else {
            l->fim->prox = aux;
            aux->ant = l->fim;
            l->fim = aux;
        }
        (l->qtd)++;
    }
    else {
        printf("Valor presente na lista! Digite outro. \n");
    }
}

void exibirValores(LDE l) {
    Node *aux;
    aux = l.inicio;

    if (l.qtd == 0) {
        printf("Lista vazia! \n");
        return;
    }

    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void removerValor(LDE *l, int v) {
    Node *aux;

    aux = buscar(*l, v);
    if (aux == NULL) {
        printf("Valor nao encontrado!\n");
        return;
    }
    else {
        if (l->qtd == 1) {
            l->inicio = NULL;
            l->fim = NULL;
            l->qtd = 0;
            free(aux);
            printf("Valor removido!\n");
        }
        else if (aux == l->inicio && l->qtd > 1) {
            l->inicio = l->inicio->prox;
            l->inicio->ant = NULL;
            free(aux);
            (l->qtd)--;
            printf("Valor removido!\n");
        }
        else if (aux == l->fim && l->qtd > 1) {
            l->fim = l->fim->ant;
            l->fim->prox = NULL;
            free(aux);
            (l->qtd)--;
            printf("Valor removido!\n");
        }
        else {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            free(aux);
            (l->qtd)--;
            printf("Valor removido!\n");
        }
    }
 
}

void copiaIdentica(LDE *l1, LDE *l2) {
    Node *aux;
    aux = l1->inicio;

    if (l1->qtd == 0) {
        printf("Lista a ser copiada vazia! \n");
        return;
    }
    while (aux != NULL) {
        inserirFinal(l2, aux->info);
        aux = aux->prox;
    }
}

void copiaInvertida(LDE *l1, LDE *l2) {
    Node *aux;
    aux = l1->fim;

    if (l1->qtd == 0) {
        printf("Lista a ser copiada vazia! \n");
        return;
    }
    while (aux != NULL) {
        inserirFinal(l2, aux->info);
        aux = aux->ant;
    }
}

void esvaziarLista(LDE *l) {
    Node *aux, *aux1;
    aux = l->inicio;

    if (l->qtd == 0) {
        printf("Lista vazia! \n");
        return;
    }

    while (aux != NULL) {
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    }
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;

}

int main() {

    LDE lista, listaCopia, listaInvertida;
    int op, op1, op2, num, num1, num2, num3;
    Node *retorno;
    initialize(&lista);
    initialize(&listaCopia);
    initialize(&listaInvertida);

    do {
        exibirOpcoes();
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &num);
                inserirInicio(&lista, num);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &num1);
                inserirFinal(&lista, num1);
                break;
            case 3:
                printf("\n1 - Ver lista padrao \n");
                printf("2 - Ver copia identica \n");
                printf("3 - Ver lista invertida \n");
                printf("\nDigite qual lista deseja ver: ");
                scanf("%d", &op1);
                switch (op1) {
                    case 1:
                        exibirValores(lista);
                        break;
                    case 2:
                        exibirValores(listaCopia);
                        break;
                    case 3:
                        exibirValores(listaInvertida);
                        break;
                    default:
                        printf("Opcao invalida!");
                }
                break;
            case 4:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &num2);
                retorno = buscar(lista, num2);
                if (retorno == NULL) {
                    printf("Valor nao encontrado na lista!\n");
                }   
                else {
                    printf("Valor encontrado na lista!\n");
                }
                break;
            case 5:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &num3);
                removerValor(&lista, num3);
                break;
            case 6:
                copiaIdentica(&lista, &listaCopia);
                printf("Copia realizada! \n");
                break;
            case 7:
                copiaInvertida(&lista, &listaInvertida);
                printf("Lista invertida realizada!\n");
                break;
            case 8:
                printf("\n1 - Esvaziar lista padrao \n");
                printf("2 - Esvaziar lista copia\n");
                printf("3 - Esvaziar lista invertida\n");
                printf("\nDigite qual lista esvaziar: ");
                scanf("%d", &op2);
                switch(op2) {
                    case 1:
                        esvaziarLista(&lista);
                        printf("Lista esvaziada!\n");
                        break;
                    case 2:
                        esvaziarLista(&listaCopia);
                        printf("Lista esvaziada!\n");
                        break;
                    case 3:
                        esvaziarLista(&listaInvertida);
                        printf("Lista esvaziada!\n");
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
                break;
            case 0:
                printf("FIM\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }   while (op != 0);

    return 0;
}
