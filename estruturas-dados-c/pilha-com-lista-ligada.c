#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TRUE 1
#define FALSE 0

typedef struct stackint {

    int valores[TAM];
    int topo;


}   StackInt;

void initialize(StackInt *p) {

    int i;

    for (i = 0; i < TAM;i++) {
        p->valores[i] = 0;
    }
    p->topo = -1;

}

void push(StackInt *p, int n) {

    (p->topo)++;
    p->valores[p->topo] = n; 

}

int pop(StackInt *p) {

    int aux;

    aux = p->valores[p->topo];
    (p->topo)--;
    
    return aux;

}

int top(StackInt p) {

    return p.valores[p.topo];

}

int IsEmpty(StackInt p) {

    if (p.topo == -1) {
        return TRUE;
    }
    else {
        return FALSE;
    }

}

int IsFull(StackInt p) {

    if (p.topo == TAM-1) {
        return TRUE;
    }
    else {
        return FALSE;
    }


}

void exibirOpcoes() {

    printf("1 - Empilhar \n");
    printf("2 - Desempilhar \n");
    printf("3 - Ver o que esta no topo \n");
    printf("0 - Encerrar o programa \n");
    printf("\nInforme o que deseja: ");

}

int main() {

    StackInt pilha;

    int op, n1, n2;

    initialize(&pilha);
    do {
        exibirOpcoes();
        scanf("%d", &op);

        switch(op) {
            case 1:
                if (IsFull(pilha) == FALSE) { 
                    printf("Informe o numero: ");
                    scanf("%d", &n1);
                    push(&pilha,n1);
                }
                break;
                
            case 2:
                if (IsEmpty(pilha) == FALSE) {
                    pop(&pilha);
                }
                break;

            case 3:
                n2 = top(pilha);
                printf("\nNumero no topo: %d \n", n2);
                break;
        }  

    }   while(op != 0);


    return 0;
}