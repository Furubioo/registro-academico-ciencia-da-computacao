#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *ante;
    int info;
    struct node *prox;
}   Node;

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

Node* busca(LDE l, int v) {
    Node *aux;
    aux = l.prim;

    if (l.qtd == 0) {
        return NULL;
    }

    do {    
        if (aux->info == v) {
            return aux;
        }
        aux = aux->prox;

    } while(aux != l.prim);

    return NULL;
}

void inserirInicio(LDE *l, int v) {
    Node *aux, *retorno;
    retorno = busca(*l, v);

    if (retorno == NULL) {
        aux = (Node*) malloc(sizeof(Node));
        aux->info = v;
        if (l->qtd == 0) {
            l->prim = aux;
            l->ult = aux;
            (l->qtd)++;
            l->prim->ante = l->ult;
            l->ult->prox = l->prim;
        }
        else {
            aux->prox = l->prim;
            l->prim->ante = aux;
            l->prim = aux;
            (l->qtd)++;
            l->prim->ante = l->ult;
            l->ult->prox = l->prim;
        }
    }
    else {
        printf("Valor presente na lista!\n");
    }

}

void inserirFinal(LDE *l, int v) {
    Node *aux, *retorno;
    retorno = busca(*l, v);

    if (retorno == NULL) {
        aux = (Node*) malloc(sizeof(Node));
        aux->info = v;
        if (l->qtd == 0) {
            l->prim = aux;
            l->ult = aux;
            (l->qtd)++;
            l->prim->ante = l->ult;
            l->ult->prox = l->prim;
        }
        else {
            aux->ante = l->ult;
            l->ult->prox = aux;
            l->ult = aux;
            (l->qtd)++;
            l->prim->ante = l->ult;
            l->ult->prox = l->prim;
        }
    }
    else {
        printf("Valor presente na lista!\n");
    }
}

void removerInicio(LDE *l) {
    Node *aux;
    aux = l->prim;

    if (l->qtd == 0) {
        printf("Lista vazia!\n");
    }
    else if (l->qtd == 1) {
        l->prim = NULL;
        l->ult = NULL;
        l->qtd = 0;
        free(aux);
    }
    else {
        l->prim = aux->prox;
        l->prim->ante = l->ult;
        l->ult->prox = l->prim;
        free(aux);
        (l->qtd)--;
    }

}

void removerFinal(LDE *l) {
    Node *aux;
    aux = l->ult;

    if (l->qtd == 0) {
        printf("Lista vazia!\n");
    }
    else if (l->qtd == 1) {
        l->prim = NULL;
        l->ult = NULL;
        l->qtd = 0;
        free(aux);
    }
    else {
        l->ult = aux->ante;
        l->ult->prox = l->prim;
        l->prim->ante = l->ult;
        free(aux);
        (l->qtd)--;
    }

}

void removerValor(LDE *l, int v) {
    Node *aux;
    aux = busca(*l, v);

    if (l->qtd == 0) {
        printf("Lista vazia!\n");
    }
    else if (aux != NULL) {
        if (l->qtd == 1) {
            l->prim = NULL;
            l->ult = NULL;
            l->qtd = 0;
            free(aux);
        }
        else if (aux == l->prim) {
            l->prim = aux->prox;
            l->ult->prox = l->prim;
            l->prim->ante = l->ult;
            free(aux);
            (l->qtd)--;
        }
        else if (aux == l->ult) {
            l->ult = aux->ante;
            l->prim->ante = l->ult;
            l->ult->prox = l->prim;
            free(aux);
            (l->qtd)--;
        }
        else {
            aux->ante->prox = aux->prox;
            aux->prox->ante = aux->ante;
            free(aux);
            (l->qtd)--;
        }
        
    }
    else {
        printf("Valor nao encontrado!\n");
    }
}


void exibir(LDE l) {
    Node *aux;
    aux = l.prim;
    
    if (l.qtd == 0) {
        printf("Lista vazia!\n");
        return;
    }

    do {
        printf("%d ", aux->info);
        aux = aux->prox;
    } while(aux != l.prim);
}

void removerTodos(LDE *l) {
    Node *aux, *aux1;
    aux = l->prim;
    do {    
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    } while (aux != l->prim);
    l->prim = NULL;
    l->ult = NULL;
    l->qtd = 0;
}

void exibirOpcoes() {
    printf("\n\nOpcoes:\n");
    printf("1 - Inserir valor no inicio da lista\n");
    printf("2 - Inserir valor no final da lista\n");
    printf("3 - Remover valor no inicio da lista\n");
    printf("4 - Remover valor no final da lista\n");
    printf("5 - Remover determinado valor da lista\n");
    printf("6 - Exibir todos os valores da lista\n");
    printf("7 - Desalocar lista\n");
    printf("\nInforme a opcao desejada: ");
}

int main() {
    LDE lista;
    int op, num;
    initialize(&lista);

    do {
        exibirOpcoes();
        scanf("%d", &op);
        
        switch(op) {
            case 1:
                printf("Informe o valor: ");
                scanf("%d", &num);
                inserirInicio(&lista, num);
                break;
            case 2:
                printf("Informe o valor: ");
                scanf("%d", &num);
                inserirFinal(&lista, num);
                break;
            case 3:
                removerInicio(&lista);
                break;
            case 4:
                removerFinal(&lista);
                break;
            case 5:
                printf("Digite o valor: ");
                scanf("%d", &num);
                removerValor(&lista, num);
                break;
            case 6:
                exibir(lista);
                break;
            case 7:
                removerTodos(&lista);
                printf("Lista esvaziada!\n");
                break;
            case 0:
                printf("FIM\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 0);

    return 0;
}




