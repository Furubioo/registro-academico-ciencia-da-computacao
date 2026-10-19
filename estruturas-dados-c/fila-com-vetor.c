#include <stdio.h> 
#include <stdlib.h> 

 
#define TAM 10 
#define TRUE 1 
#define FALSE 0 

 

typedef struct queueInt { 

    int valores[TAM]; 
    int inicio, fim; 

} QueueInt; 

 
void Initialize(QueueInt *f) { 

    int i; 

    f->inicio = 0; 
    f->fim = -1; 

    for (i = 0; i < TAM; i++) { 
        f->valores[i] = 0; 
    } 

} 

 
int IsEmpty(QueueInt f) { 

    if (f.fim < f.inicio) { 
        return TRUE; 
    } 
    return FALSE; 

} 


int IsFull(QueueInt f) { 

    if (f.fim == TAM - 1) { 
        return TRUE; 
    } 

    return FALSE; 

} 

 
void Enqueue(QueueInt *f, int v) { 

    (f->fim)++; 
    f->valores[f->fim] = v; 

} 

 
int Dequeue(QueueInt *f) { 

    int i, valor; 

    valor = f->valores[f->inicio]; 

    for (i = 0; i < f->fim; i++) { 
        f->valores[i] = f->valores[i+1]; 
    } 

    f->valores[f->fim] = 0; 
    f->fim--; 

    return valor; 

} 

 
int Head(QueueInt f) { 

    return f.valores[f.inicio]; 

} 


void ExibirOpcoes() { 

 

    printf("\n1 - Enfileirar \n"); 

    printf("2 - Desenfileirar \n"); 

    printf("3 - Ver o valor do inicio \n"); 

    printf("0 - Encerrar programa \n"); 

    printf("\nDigite o que deseja: "); 

} 

 

int main() { 

 

    QueueInt minhaFila; 

    int op, val, n; 

    Initialize(&minhaFila); 

    do { 

        ExibirOpcoes(); 

        scanf("%d", &op); 

        switch(op) { 

            case 1: 

                printf("Digite o valor: "); 

                scanf("%d", &val); 
                if (IsFull(minhaFila) == FALSE) {
                    Enqueue(&minhaFila, val);
                }
                else{
                    printf("\nFila cheia!\n");
                }
                break; 

            case 2: 
                if (IsEmpty(minhaFila) == TRUE) {
                    printf("Fila vazia!!\n");
                } 
                else {
                    n = Dequeue(&minhaFila);
                    printf("Valor removido: %d\n", n);
                }
                break; 

 

            case 3: 

                if (IsEmpty(minhaFila) == TRUE) {
                    printf("nFila vazia!!\n");
                }
                else {
                    printf("Valor do inicio da fila: %d", Head(minhaFila));
                }
                break; 

            default: 
                break; 

        } 

    } while(op != 0); 

    return 0; 

} 

 

  