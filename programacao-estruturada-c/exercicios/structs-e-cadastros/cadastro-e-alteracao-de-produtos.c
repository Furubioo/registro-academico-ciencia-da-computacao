#include <stdio.h>
#include <string.h>

#define CAPACIDADE 40

typedef struct {
    char codigo[12];
    char descricao[50];
    float preco;
    int estoque;
} Produto;

static void limpar_entrada(void) {
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

static void ler_linha(char destino[], size_t tamanho) {
    if (fgets(destino, (int)tamanho, stdin) != NULL) {
        destino[strcspn(destino, "\n")] = '\0';
    }
}

static int localizar(const Produto produtos[], int quantidade, const char codigo[]) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if (strcmp(produtos[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

static void listar(const Produto produtos[], int quantidade) {
    int i;
    puts("\nCODIGO | DESCRICAO | PRECO | ESTOQUE");
    for (i = 0; i < quantidade; i++) {
        printf("%-10s | %-20s | %6.2f | %d\n", produtos[i].codigo,
               produtos[i].descricao, produtos[i].preco, produtos[i].estoque);
    }
}

int main(void) {
    Produto produtos[CAPACIDADE];
    int quantidade = 0;
    int opcao;

    do {
        puts("\n1 - Cadastrar\n2 - Alterar\n3 - Listar\n0 - Sair");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) {
            limpar_entrada();
            opcao = -1;
            continue;
        }
        limpar_entrada();

        if (opcao == 1) {
            Produto *produto;
            if (quantidade == CAPACIDADE) {
                puts("Limite de produtos atingido.");
                continue;
            }
            produto = &produtos[quantidade];
            printf("Codigo: ");
            ler_linha(produto->codigo, sizeof produto->codigo);
            if (localizar(produtos, quantidade, produto->codigo) >= 0) {
                puts("Codigo ja cadastrado.");
                continue;
            }
            printf("Descricao: ");
            ler_linha(produto->descricao, sizeof produto->descricao);
            printf("Preco: ");
            if (scanf("%f", &produto->preco) != 1) {
                limpar_entrada();
                continue;
            }
            printf("Estoque: ");
            if (scanf("%d", &produto->estoque) != 1) {
                limpar_entrada();
                continue;
            }
            limpar_entrada();
            quantidade++;
        } else if (opcao == 2) {
            char codigo[12];
            int indice;
            printf("Codigo do produto: ");
            ler_linha(codigo, sizeof codigo);
            indice = localizar(produtos, quantidade, codigo);
            if (indice < 0) {
                puts("Produto nao encontrado.");
                continue;
            }
            printf("Novo preco: ");
            if (scanf("%f", &produtos[indice].preco) != 1) {
                limpar_entrada();
                continue;
            }
            printf("Novo estoque: ");
            if (scanf("%d", &produtos[indice].estoque) != 1) {
                limpar_entrada();
                continue;
            }
            limpar_entrada();
        } else if (opcao == 3) {
            listar(produtos, quantidade);
        } else if (opcao != 0) {
            puts("Opcao invalida.");
        }
    } while (opcao != 0);

    return 0;
}
