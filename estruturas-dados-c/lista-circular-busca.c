#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node {
    int info;
    struct node *prox;
    struct node *ant;
} Node;

typedef struct ldec {
    Node *inicio;
    Node *fim;
    int qtd;
} LDEC;

void initialize(LDEC *l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

Node* busca(LDEC l, int v) {
    Node *aux;
    aux = l.inicio;

    if (l.qtd == 0) {
        return NULL;
    }

    do {    
        if (aux->info == v) {
            return aux;
        }
        aux = aux->prox;

    } while(aux != l.inicio);

    return NULL;
}

void inserirFinal(LDEC *l, int v) {
    Node *aux, *retorno;
    retorno = busca(*l, v);

    if (retorno == NULL) {
        aux = (Node*) malloc(sizeof(Node));
        aux->info = v;
        if (l->qtd == 0) {
            l->inicio = aux;
            l->fim = aux;
            (l->qtd)++;
            l->inicio->ant = l->fim;
            l->fim->prox = l->inicio;
        }
        else {
            aux->ant = l->fim;
            l->fim->prox = aux;
            l->fim = aux;
            (l->qtd)++;
            l->inicio->ant = l->fim;
            l->fim->prox = l->inicio;
        }
    }
    else {
        printf("Valor presente na lista!\n");
    }
}

void exibir(LDEC l) {
    Node *aux;
    aux = l.inicio;
    
    if (l.qtd == 0) {
        printf("Lista vazia!\n");
        return;
    }

    do {
        printf("%d ", aux->info);
        aux = aux->prox;
    } while(aux != l.inicio);
}

void removerTodos(LDEC *l) {
    Node *aux, *aux1;
    aux = l->inicio;
    do {    
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    } while (aux != l->inicio);
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

void exibirOpcoes() {
    printf("\n\nOpcoes:\n");
    printf("1 - Inserir valor no final da lista\n");
    printf("2 - Exibir todos os valores da lista\n");
    printf("3 - Desalocar lista\n");
    printf("4 - Comparar listas\n");
    printf("5 - Concatenar listas\n");
    printf("6 - Realizar copia inversa\n");
    printf("\nInforme a opcao desejada: ");
}

int compararListas(LDEC l1, LDEC l2) {
    Node *aux, *aux1;
    aux = l1.inicio;
    aux1 = l2.inicio;
    int cont = 0;

    do {
        if (aux->info == aux1->info) {
            cont++;
        }
        aux = aux->prox;
        aux1 = aux1->prox;

    } while(aux != l1.inicio);

    if (l1.qtd == l2.qtd && cont == l1.qtd) {
        return TRUE;
    }
    else {
        return FALSE;
    }

}

void concatenarListas(LDEC *l1, LDEC *l2) {
    Node *aux, *aux1;
    aux = l2->inicio;

    if (l1->qtd == 0 || l2->qtd == 0) {
        printf("Uma das listas esta vazia!\n");
    }
    else {
        l1->inicio->ant = l2->fim;
        l2->fim->prox = l1->inicio;
        l2->inicio->ant = l1->fim;
        l1->fim->prox = l2->inicio;
        l1->fim = l2->fim;
        l1->qtd = l1->qtd +l2->qtd;

        do {
            aux1 = aux;
            aux = aux->prox;
            free(aux1);
        } while(aux != l2->inicio);
        l2->inicio = NULL;
        l2->fim = NULL;
        l2->qtd = 0;
        printf("Listas concatenadas!\n");
    }
}

void criarCopiaInversa(LDEC *lo, LDEC *lci) {
    Node *aux;
    aux = lo->fim;

    if (lo->qtd == 0) {
        printf("Impossivel efetuar copia!\n");
    }

    do {
        inserirFinal(lci, aux->info);
        aux = aux->ant;
    } while(aux != lo->fim);

}

int main() {
    LDEC lista1, lista2, listaCopia;
    int op, op1, op2, op3, op4, num, retorno;
    initialize(&lista1);
    initialize(&lista2);
    initialize(&listaCopia);
    do {
        exibirOpcoes();
        scanf("%d", &op);
        
        switch(op) {
            case 1:
                printf("\n1 - Lista 1\n");
                printf("2 - Lista 2\n");
                printf("0 - Sair\n");
                printf("Digite qual lista deseja preencher: ");
                scanf("%d", &op1);
                switch(op1) {
                    case 1:
                        printf("Informe o valor(lista 1): ");
                        scanf("%d", &num);
                        inserirFinal(&lista1, num);
                        break;
                    case 2:
                        printf("Informe o valor(lista 2): ");
                        scanf("%d", &num);
                        inserirFinal(&lista2, num);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
                break;
            case 2:
                printf("\n1 - Lista 1\n");
                printf("2 - Lista 2\n");
                printf("3 - Lista de copia inversa\n");
                printf("0 - Sair\n");
                printf("Digite qual lista deseja ver: ");
                scanf("%d", &op2);
                switch(op2) {
                    case 1:
                        exibir(lista1);
                        break;
                    case 2:
                        exibir(lista2);
                        break;
                    case 3:
                        exibir(listaCopia);
                    case 0:
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }               
                break;
            case 3:
                printf("\n1 - Lista 1\n");
                printf("2 - Lista 2\n");
                printf("0 - Sair\n");
                printf("Digite qual lista deseja esvaziar: ");
                scanf("%d", &op3);
                switch(op3) {
                    case 1:
                        removerTodos(&lista1);
                        printf("Lista esvaziada!\n");
                        break;
                    case 2:
                        removerTodos(&lista2);
                        printf("Lista esvaziada!\n");
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
                break;
            case 4:
                retorno = compararListas(lista1, lista2);
                if(retorno == TRUE) {
                    printf("As listas sao iguais!\n");
                }
                else {
                    printf("As listas sao diferentes.\n");
                }
                break;
            case 5:
                concatenarListas(&lista1, &lista2);
                break;

            case 6:
                printf("\n1 - Lista 1\n");
                printf("2 - Lista 2\n");
                printf("0 - Sair\n");
                printf("Digite qual lista deseja realizar a copia inversa: ");
                scanf("%d", &op4);
                switch(op4) {
                    case 1:
                        criarCopiaInversa(&lista1, &listaCopia);
                        printf("Copia inversa criada!\n");
                        break;
                    case 2:
                        criarCopiaInversa(&lista2, &listaCopia);
                        printf("Copia inversa criada!\n");
                        break;
                    case 0:
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

    } while (op != 0);

    return 0;
}

