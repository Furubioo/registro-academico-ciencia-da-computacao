#include <stdio.h>

int busca(int *vet, int n, int valor) {

    int i, existe = 0;

    for (i = 0; i < n; i++) {
        if (valor == vet[i]) {
            existe = 1;
        }
    }

    return existe;

}


int main() {

    int i, vetor[10], cont = 0;
    int x, vbusca;

    for (i = 0; i < 10; i++) {
        printf("Digite o valor [%d]: ", i);
        scanf("%d", &vetor[i]);
        cont++;
    }

    printf("Qual valor deseja procurar no vetor? ");
    scanf("%d", &vbusca);

    x = busca(vetor, cont, vbusca);

    if (x == 1) {
        printf("\nO valor foi encontrado no vetor.\n");
    }
    else {
        printf("\nO valor nao foi encontrado no vetor. \n");
    }

    return 0;
}

