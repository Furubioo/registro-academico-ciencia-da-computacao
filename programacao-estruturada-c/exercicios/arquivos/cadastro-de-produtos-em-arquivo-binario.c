#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char descricao[50];
    int quantidade;
    float preco;
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

static int localizar(FILE *arquivo, int codigo, Produto *produto) {
    rewind(arquivo);
    while (fread(produto, sizeof *produto, 1, arquivo) == 1) {
        if (produto->codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

static void cadastrar(FILE *arquivo) {
    Produto produto;

    printf("Codigo: ");
    if (scanf("%d", &produto.codigo) != 1) {
        limpar_entrada();
        return;
    }
    limpar_entrada();
    if (localizar(arquivo, produto.codigo, &(Produto){0})) {
        puts("Ja existe um produto com esse codigo.");
        return;
    }

    printf("Descricao: ");
    ler_linha(produto.descricao, sizeof produto.descricao);
    printf("Quantidade em estoque: ");
    if (scanf("%d", &produto.quantidade) != 1) {
        limpar_entrada();
        return;
    }
    printf("Preco: ");
    if (scanf("%f", &produto.preco) != 1) {
        limpar_entrada();
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    fwrite(&produto, sizeof produto, 1, arquivo);
    fflush(arquivo);
    puts("Produto cadastrado.");
}

static void listar(FILE *arquivo) {
    Produto produto;

    rewind(arquivo);
    puts("\nCODIGO | DESCRICAO | ESTOQUE | PRECO");
    while (fread(&produto, sizeof produto, 1, arquivo) == 1) {
        printf("%6d | %-20s | %7d | %.2f\n", produto.codigo,
               produto.descricao, produto.quantidade, produto.preco);
    }
}

static void alterar(FILE *arquivo) {
    Produto produto;
    int codigo;

    printf("Codigo do produto: ");
    if (scanf("%d", &codigo) != 1) {
        limpar_entrada();
        return;
    }
    if (!localizar(arquivo, codigo, &produto)) {
        puts("Produto nao encontrado.");
        return;
    }

    printf("Nova quantidade: ");
    if (scanf("%d", &produto.quantidade) != 1) {
        limpar_entrada();
        return;
    }
    printf("Novo preco: ");
    if (scanf("%f", &produto.preco) != 1) {
        limpar_entrada();
        return;
    }

    fseek(arquivo, -(long)sizeof produto, SEEK_CUR);
    fwrite(&produto, sizeof produto, 1, arquivo);
    fflush(arquivo);
    puts("Produto atualizado.");
}

int main(void) {
    FILE *arquivo = fopen("produtos.dat", "a+b");
    int opcao;

    if (arquivo == NULL) {
        puts("Nao foi possivel abrir o arquivo de produtos.");
        return 1;
    }

    do {
        puts("\n1 - Cadastrar\n2 - Listar\n3 - Alterar estoque e preco\n0 - Sair");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) {
            limpar_entrada();
            opcao = -1;
            continue;
        }
        switch (opcao) {
            case 1: cadastrar(arquivo); break;
            case 2: listar(arquivo); break;
            case 3: alterar(arquivo); break;
            case 0: break;
            default: puts("Opcao invalida.");
        }
    } while (opcao != 0);

    fclose(arquivo);
    return 0;
}
