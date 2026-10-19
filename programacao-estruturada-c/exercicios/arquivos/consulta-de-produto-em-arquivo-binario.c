#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
    float preco;
} Produto;

int main(void) {
    FILE *arquivo = fopen("produtos.dat", "rb");
    Produto produto;
    int codigo;
    int encontrado = 0;

    if (arquivo == NULL) {
        puts("Arquivo de produtos nao encontrado.");
        return 1;
    }

    printf("Codigo do produto: ");
    if (scanf("%d", &codigo) != 1) {
        fclose(arquivo);
        return 1;
    }

    while (fread(&produto, sizeof produto, 1, arquivo) == 1) {
        if (produto.codigo == codigo) {
            printf("%d | %s | estoque: %d | preco: %.2f\n",
                   produto.codigo, produto.descricao, produto.quantidade,
                   produto.preco);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        puts("Produto nao encontrado.");
    }

    fclose(arquivo);
    return 0;
}
