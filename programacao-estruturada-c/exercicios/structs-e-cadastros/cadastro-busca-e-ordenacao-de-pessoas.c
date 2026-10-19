#include <stdio.h>
#include <string.h>

#define TOTAL_PESSOAS 3

typedef struct {
    char nome[40];
    char sexo;
    int idade;
} Pessoa;

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

static void ordenar_por_nome(Pessoa pessoas[], size_t tamanho) {
    size_t i;
    size_t j;

    for (i = 0; i + 1 < tamanho; i++) {
        for (j = 0; j + 1 < tamanho - i; j++) {
            if (strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0) {
                Pessoa auxiliar = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = auxiliar;
            }
        }
    }
}

int main(void) {
    Pessoa pessoas[TOTAL_PESSOAS];
    char busca[40];
    int i;
    int encontrado = 0;

    for (i = 0; i < TOTAL_PESSOAS; i++) {
        printf("Nome da pessoa %d: ", i + 1);
        ler_linha(pessoas[i].nome, sizeof pessoas[i].nome);
        printf("Sexo (M/F): ");
        if (scanf(" %c", &pessoas[i].sexo) != 1) {
            return 1;
        }
        printf("Idade: ");
        if (scanf("%d", &pessoas[i].idade) != 1) {
            return 1;
        }
        limpar_entrada();
    }

    ordenar_por_nome(pessoas, TOTAL_PESSOAS);
    puts("\nCadastro ordenado por nome:");
    for (i = 0; i < TOTAL_PESSOAS; i++) {
        printf("%s | %c | %d anos\n", pessoas[i].nome, pessoas[i].sexo,
               pessoas[i].idade);
    }

    printf("\nNome para busca: ");
    ler_linha(busca, sizeof busca);
    for (i = 0; i < TOTAL_PESSOAS; i++) {
        if (strcmp(pessoas[i].nome, busca) == 0) {
            printf("Encontrado: %s, %c, %d anos\n", pessoas[i].nome,
                   pessoas[i].sexo, pessoas[i].idade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        puts("Pessoa nao encontrada.");
    }

    return 0;
}
