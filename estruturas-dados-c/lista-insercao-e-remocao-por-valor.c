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
    printf ("\nOpcoes \n\n");
    printf ("1 - Inserir \n");
    printf ("2 - Exibir valores da lista \n"); 
    printf ("3 - Remover valor \n");
    printf ("4 - Esvaziar lista \n");
    printf ("0 - Encerrar o programa \n");
    printf ("\nInforme a opcao desejada: ");
}

Node* criarNode (int valor) { // cria e preencher um nó e retorna seu endereço
    Node* novo;
    novo = (Node*) malloc (sizeof(Node));
    novo->info = valor;
    novo->ante = NULL;
    novo->prox = NULL;
    return novo;
}

void inserir (LDE* l, int valor) {
    Node* novo, *atual, *anterior;

    if (l->qtd == 0) { // inserção em uma lista vazia
        novo = criarNode(valor);
        l->prim = novo;
        l->ult = novo;
        l->qtd++;
    }
    else if (valor == l->prim->info) {
        printf ("Valor repetido. Inserção não efetuada. \n");
    }
    else if (valor < l->prim->info) { // inserir antes do primeiro
        novo = criarNode(valor);
        novo->prox = l->prim;
        l->prim->ante = novo;
        l->prim = novo;
        l->qtd++;
    }
    else if (valor == l->ult->info) {
        printf ("Valor repetido. Inserção não efetuada. \n");
    }
    else if (valor > l->ult->info) { // inserir após o último
        novo = criarNode(valor);
        l->ult->prox = novo;
        novo->ante = l->ult;
        l->ult = novo;
        l->qtd++;
    }
    else { // inserir no "meio" da lista
        atual = l->prim;
        while (atual != NULL) {
            if (atual->info == valor) {
                printf ("Valor repetido. Inserção não efetuada. \n");
                return; // sai do procedimento de inserção
            }
            else if (atual->info > valor) { // Achou o ponto de inserção: imediatamente antes do ATUAL
                anterior = atual->ante;
                novo = criarNode(valor);
                anterior->prox = novo;
                novo->prox = atual;
                atual->ante = novo;
                novo->ante = anterior;
                l->qtd++;
                return;
            }
            else {
                atual = atual->prox;
            }
        }
    }
}

void listar (LDE* l) {
    Node*aux;
    aux = l->prim;
    if(l->qtd == 0){
        printf("Lista vazia!");
        return;
    }
    else{
        while(aux != NULL){
            printf("%d ",aux->info);
            aux = aux->prox;
        }
    }
    printf("\n");
}

void removerValor(LDE *l, int v) {
    Node *aux;
    aux = l->prim;
    int cont = 0;

    if (l->qtd == 0) {
        printf("Lista vazia!\n");
        return;
    }
    while (aux != NULL) {
        if (l->qtd == 1 && aux->info == v) {
            free(aux);
            l->prim = NULL;
            l->ult = NULL;
            l->qtd = 0;
            printf("Valor removido!\n");
            cont++;
        }
        else if (l->qtd > 1 && aux->info == v) {
            if (aux == l->prim) {
                l->prim = aux->prox;
                l->prim->ante = NULL;
                free(aux);
                printf("Valor removido!\n");
            }
            else if (aux == l->ult) {
                l->ult = l->ult->ante;
                l->ult->prox = NULL;
                free(aux);
                printf("Valor removido!\n");
            }
            else {
                aux->ante->prox = aux->prox;
                aux->prox->ante = aux->ante;
                free(aux);
                printf("Valor removido!\n");
            }
            cont++;
            (l->qtd)--;
        }
        aux = aux->prox;
    }
    if (cont == 0) {
        printf("O valor nao foi encontrado!\n");
    }
}

void esvaziar(LDE *l) {
    Node *aux, *aux1;
    aux = l->prim;

    while (aux != NULL) {
        aux1 = aux;
        aux = aux->prox;
        free(aux1);
    }
    l->prim = NULL;
    l->ult = NULL;
    l->qtd = 0;
}

int main () {
    LDE lista;
    initialize(&lista);
    int op, num, num1;
    do {
        exibeOpcoes();
        scanf ("%d",&op);
        switch (op) {
            case 1: 
                printf ("Informe o numero: ");
                scanf ("%d",&num);
                inserir (&lista,num);
                break;
            case 2: 
                listar (&lista);
                break;
            case 3:
                printf("Digite o valor que deseja remover: ");
                scanf("%d", &num1);
                removerValor(&lista, num1);
                break;
            case 4:
                esvaziar(&lista);
                printf("Lista esvaziada.\n");
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