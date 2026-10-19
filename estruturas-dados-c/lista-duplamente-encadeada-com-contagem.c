#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    struct node* ante;
    int info;
    struct node* prox;
} Node;

typedef struct lde {
    Node* prim;
    Node* ult;
    int qtd;
} LDE;

void initialize (LDE* l) {
    l->prim = NULL;
    l->ult = NULL;
    l->qtd = 0;
}

void exibeOpcoes() {
    printf("\nOpcoes: \n");
    printf("1 - Inserir no inicio da lista \n");
    printf("2 - Inserir no final da lista \n");
    printf("3 - Exibir valores da lista ao contrario \n");
    printf("4 - Exibir do inicio ao fim \n");
    printf("5 - Remover o primeiro \n");
    printf("6 - Remover o ultimo \n");    
    printf("7 - Remover qualquer valor \n");
    printf("8 - Qtd. de vezes de um valor \n");
    printf("0 - Encerrar o programa \n");
    printf("\nInforme a opcao desejada: ");
}

void inserirInicio (LDE* l, int valor) {
    Node* novo;
    novo = (Node*) malloc (sizeof(Node));
    novo->info = valor;
    novo->ante = NULL;
    if (l->qtd == 0) {
        l->prim = novo;
        l->ult = novo;
        novo->prox = NULL;
    }
    else {
        novo->prox = l->prim;
        l->prim->ante = novo;
        l->prim = novo;
    }
    (l->qtd)++;
    printf("Valor inserido! \n");
}

void inserirFinal(LDE *l, int valor) {
    Node *aux;

    aux = (Node*) malloc (sizeof(Node));
    aux->info = valor;
    aux->prox = NULL;
    if (l->qtd == 0) {
        l->prim = aux;
        l->ult = aux;
        aux->ante = NULL;
    }
    else {
        aux->ante = l->ult;
        l->ult->prox = aux;
        l->ult = aux;
    }
    (l->qtd)++;
    printf("Valor inserido! \n");

}

void removerInicio(LDE *l) {
    Node *aux;

    if (l->qtd == 0) {
        printf("Lista vazia! \n");
    }
    else if (l->qtd == 1) {
        free(l->prim);
        l->prim = NULL;
        l->ult = NULL;
        l->qtd = 0;
        printf("Valor removido! \n");
    }
    else {
        aux = l->prim;
        l->prim = aux->prox;
        l->prim->ante = NULL;
        free(aux);
        (l->qtd)--;
        printf("Valor removido! \n");
    }

}

void removerUltimo (LDE* l) { 
    Node* aux;

    if (l->qtd == 0) {
        printf ("Lista vazia !\n");
    }
    else if (l->qtd == 1) {
        free(l->prim);
        l->prim = NULL;
        l->ult = NULL;
        l->qtd = 0;
        printf("Valor removido! \n");
    }
    else {
        aux = l->ult;
        l->ult = aux->ante;
        l->ult->prox = NULL;
        free(aux);
        (l->qtd)--;
        printf("Valor removido! \n");
    }
}

int QtdValor(LDE l, int valor) {
    Node *aux;
    int qtd = 0;
    aux = l.prim;

    while (aux != NULL) {
        if (aux->info == valor) {
            qtd++;
        }
        aux = aux->prox;
    }
    return qtd;
}

void removerValor(LDE *l, int valor) {
    Node *aux, *aux1;

    if (QtdValor(*l, valor) == 0) {
        printf("Valor nao encontrado na lista! \n");
    }
    else if (QtdValor(*l, valor) > 0) {
        aux = l->prim;
        while (aux != NULL) {
            if (aux->info == valor) {
                if (l->qtd == 1) {
                    aux1 = aux;
                    free(aux1);
                    l->prim = NULL;
                    l->ult = NULL;
                    l->qtd = 0;
                    aux = NULL;
                }
                else if (aux == l->prim && l->qtd > 1) {
                    l->prim = l->prim->prox;
                    aux1 = aux;
                    aux = l->prim;
                    free(aux1);
                    l->prim->ante = NULL;
                    (l->qtd)--;
                }   
                else if (aux == l->ult && l->qtd > 1) {
                    l->ult = l->ult->ante;
                    aux1 = aux;
                    aux = l->ult;
                    free(aux1);
                    l->ult->prox = NULL;
                    (l->qtd)--;
                }
                else {
                    aux->ante->prox = aux->prox;
                    aux->prox->ante = aux->ante;
                    aux1 = aux;
                    aux = aux->ante;
                    free(aux1);
                    (l->qtd)--;
                }
            }
            else {
                aux = aux->prox;
            }
        }
        printf("Valor removido! \n");
    }
}

void exibirInicioAoFim(LDE l) {
    Node *aux;
    aux = l.prim;
    if (l.qtd == 0) {
        printf("Lista vazia!");
        return;
    }
    else {
        while (aux != NULL) {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
    printf("\n");
}

void listarAoContrario (LDE l) {
    Node *aux;
    aux = l.ult;
    if(l.qtd == 0){
        printf("Lista vazia!");
        return;
    }
    else{
        while(aux != NULL){
            printf("%d ",aux->info);
            aux = aux->ante;
        }
    }
    printf("\n");
}

int main () {
    LDE lista;
    initialize(&lista);
    int op, num, num1, num2, num3, retorno;
    do {
        exibeOpcoes();
        scanf ("%d",&op);
        switch (op) {
            case 1: 
                printf ("Informe o numero: ");
                scanf ("%d",&num);
                inserirInicio (&lista, num);
                break;
            case 2: 
                printf("Informe o numero: ");
                scanf("%d", &num1);
                inserirFinal(&lista, num1);
                break;
            case 3: 
                listarAoContrario(lista);
                break;
            case 4:
                exibirInicioAoFim(lista);
                break;
            case 5:
                removerInicio(&lista);
                break;
            case 6:
                removerUltimo(&lista);
                break;
            case 7:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &num2);
                removerValor(&lista, num2);
                break;
            case 8:
                printf("Digite o valor: ");
                scanf("%d", &num3);
                retorno = QtdValor(lista, num3);
                printf("Qtd. de vezes: %d\n", retorno);
                break;
            case 0: 
                printf ("FIM \n");
                break;
            default: 
                printf ("Opcao invalida \n");
        }
    } while (op != 0);

    return 0;
}