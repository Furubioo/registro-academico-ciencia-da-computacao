#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct node {
    int info;
    struct node *prox;
}   Node;

typedef struct lista {
    Node *inicio;
    Node *fim;
}   Lista;

void Initialize(Lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

Node* Buscar(Lista l, int v) {

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

void InserirInicio(Lista *l, int v) {
    if (Buscar(*l, v) == NULL) {
        Node *aux;

        aux = (Node*) malloc(sizeof(Node));
        aux->info = v;
        aux->prox = NULL;
        if (l->inicio == NULL && l->fim == NULL) {
            l->inicio = aux;
            l->fim = aux;                        
        }
        else {
            aux->prox = l->inicio;
            l->inicio = aux;
        }
    }
    else {
        printf("\nO valor foi localizado na lista! \n");
    }

}

void ExibirValores(Lista l) {

    Node *aux;

    aux = l.inicio;

    printf("\n");
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

void RemoverInicio(Lista *l) {

    Node *aux;

    aux = l->inicio;
    if (aux->prox == NULL) {
        l->fim = NULL;
    }
    l->inicio = aux->prox;
    free(aux);
    
}

void InserirFinal(Lista *l, int v) {

    if (Buscar(*l, v) == NULL) {
        Node *aux;

        aux = (Node*) malloc(sizeof(Node));
        aux->info = v;
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
        printf("\nO valor foi localizado na lista! \n");
    }

}

void RemoverFinal(Lista *l) {

    Node *aux;

    aux = l->inicio;
    if (aux->prox == NULL) {
        l->inicio = NULL;
        l->fim = NULL;
    }

    while (aux->prox != NULL) {
        if (aux->prox == l->fim) {
            l->fim = aux;
        }
        aux = aux->prox;
    }
    l->fim->prox = NULL;
    free(aux);

}


void RemoverValor(Lista *l, int v) {

    Node *aux, *aux1;

    aux = l->inicio;
    aux1 = l->inicio;

    if (l->inicio == NULL && l->fim == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    if (l->inicio == l->fim && aux->info == v) {
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);
        printf("Valor removido!\n");
        return;
    }

    while (aux != NULL) {
        if (aux->info == v) {
            aux1->prox = aux->prox;
            if (aux == l->inicio) {
                l->inicio = aux->prox;
            }
            else if (aux == l->fim) {
                l->fim = aux1;
            }
            free(aux);
            printf("Valor removido!\n");
            return;
        }
        aux1 = aux;
        aux = aux->prox;
    }
}

void Destroy(Lista *l) {

    Node *aux, *aux1;

    aux = l->inicio;
    aux1 = aux;

    while (aux != NULL) {
        aux = aux->prox;
        free(aux1);
        aux1 = aux;
    }
    l->inicio = NULL;
    l->fim = NULL;

}



void exibirOpcoes () {
    printf ("\n\nOpcoes: \n\n");
    printf ("1 - Inserir no inicio \n");
    printf ("2 - Inserir no final \n");
    printf ("3 - Remover o primeiro \n");
    printf ("4 - Remover o ultimo \n"); 
    printf ("5 - Exibir todos os valores \n");
    printf ("6 - Remover um valor especifico \n");   
    printf ("7 - Procurar um valor especifico \n");    
    printf ("0 - Encerrar programa \n");
    printf ("\nInforme a opcao desejada: ");
}

int main () {
    Lista minhaLista;
    int op, num;
    Initialize (&minhaLista);
    do {
        exibirOpcoes();
        scanf ("%d",&op);
        switch (op) {
            case 1: printf ("Informe o valor a ser inserido: ");
                    scanf ("%d",&num);
                    InserirInicio (&minhaLista,num);   
                    break;
            case 2: printf ("Informe o valor a ser inserido: ");
                    scanf ("%d",&num);
                    InserirFinal (&minhaLista,num);                        
                    break;
            case 3: RemoverInicio(&minhaLista);                       
                    break;
            case 4: RemoverFinal (&minhaLista);
                    break;
            case 5: ExibirValores (minhaLista);
                    break;  
            case 6: printf ("Informe o valor a ser removido: ");
                    scanf ("%d",&num);
                    RemoverValor (&minhaLista,num);                        
                    break;    
            case 7: printf ("Informe o valor a ser procurado: ");
                    scanf ("%d",&num);
                    Node* aux = Buscar (minhaLista,num);        
                    if (aux == NULL) {
                        printf ("\nValor não encontrado \n");
                    }                
                    else {
                        printf ("\nValor encontrado! \n");  
                    }                  
                    break;                                   
            case 0: Destroy (&minhaLista);
                    printf ("\nBye bye \n");
                    break;
            default: printf ("\nOpcao invalida \n");
        }
    } while (op != 0);
    return 0;
}





