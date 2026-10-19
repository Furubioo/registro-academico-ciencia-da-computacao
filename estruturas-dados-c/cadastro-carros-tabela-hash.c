#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Tamanho da tabela: 61 (primo).
 * Assumindo um cadastro de ate ~40 carros, 61 e um primo >= 1.5*40,
 * o que garante fator de carga baixo e menos colisoes.
 */
#define N 61

typedef struct carro {
    char placa[8];
    char marca[15];
    char modelo[15];
    char cor[15];
} CARRO;

typedef struct noTabela {
    char placa[8];
    int posicao;
    struct noTabela* prox;
    struct noTabela* ant;
} No;

FILE* prepararArquivo(char nome[]);
void  fecharArquivo(FILE* arq);
void  liberarArquivo(FILE* arq);
int   buscar(No* tabelaHashing[], char placa[]);
void  cadastrar(FILE* arq, No* tabelaHashing[]);
void  consultar(FILE* arq, No* tabelaHashing[]);
void  alterar(FILE* arq, No* tabelaHashing[]);
void  exibirCadastro(FILE* arq);
void  criarIndice(FILE* arq, No* tabelaHashing[]);
void  inserirTabelaHash(No* tabelaHashing[], char placa[], int pos);
void  desalocarIndice(No* tabelaHashing[]);
int   hashing(char placa[]);
void  exibirOpcoes();
int   validarPlaca(char placa[]);
void  leituraSegura(char str[]);

/* ------------------------------------------------------------------ */
int main() {
    char nomeArq[] = "carros.dat";
    int op;
    FILE* cadastro;
    No* tabelaHashing[N];

    cadastro = prepararArquivo(nomeArq);
    if (cadastro == NULL)
        printf("Erro na abertura do arquivo. Programa encerrado.\n");
    else {
        criarIndice(cadastro, tabelaHashing);
        do {
            exibirOpcoes();
            char bufOp[4] = "   ";
            fgets(bufOp, sizeof(bufOp), stdin);
            leituraSegura(bufOp);
            op = atoi(bufOp);
            switch (op) {
                case 1: cadastrar(cadastro, tabelaHashing);  break;
                case 2: consultar(cadastro, tabelaHashing);  break;
                case 3: alterar(cadastro, tabelaHashing);    break;
                case 4: exibirCadastro(cadastro);            break;
                case 0:
                    liberarArquivo(cadastro);
                    desalocarIndice(tabelaHashing);
                    break;
                default: printf("Opcao invalida.\n");
            }
        } while (op != 0);
    }
    return 0;
}

/* ------------------------------------------------------------------ */
FILE* prepararArquivo(char nome[]) {
    FILE* arq = fopen(nome, "r+b");
    if (arq == NULL) {
        printf("Arquivo nao encontrado. Criando...\n");
        arq = fopen(nome, "w+b");
        if (arq == NULL)
            printf("Erro ao criar o arquivo.\n");
    }
    return arq;
}

/* ------------------------------------------------------------------ */
void fecharArquivo(FILE* arq) {
    if (fclose(arq) == 0)
        printf("Arquivo fechado com sucesso.\n");
    else
        printf("Falha ao fechar o arquivo.\n");
}

/* ------------------------------------------------------------------ */
/* Compacta o arquivo removendo registros com placa invalida           *
 * (placa invalida = registro deletado logicamente) e fecha o arquivo. */
void liberarArquivo(FILE* arq) {
    char nomeNovo[30] = "novoCarros.dat";
    FILE* arqNovo = fopen(nomeNovo, "w+b");
    if (arqNovo == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fecharArquivo(arq);
        return;
    }

    CARRO c;
    rewind(arq);
    while (fread(&c, sizeof(CARRO), 1, arq) == 1)
        if (validarPlaca(c.placa) == 1)
            fwrite(&c, sizeof(CARRO), 1, arqNovo);

    fclose(arqNovo);
    fclose(arq);
    remove("carros.dat");
    rename(nomeNovo, "carros.dat");
    printf("Arquivo compactado e fechado.\n");
}

/* ------------------------------------------------------------------ */
/* Lê uma linha com fgets e substitui o \n pelo \0.                    */
void leituraSegura(char str[]) {
    int i, tam; tam = strlen(str);
    for (i = 0; i < tam; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

/* ------------------------------------------------------------------ */
int hashing(char placa[]) {
    int i, soma = 0, tam = strlen(placa);
    for (i = 0; i < tam; i++)
        soma = soma + (placa[i] << (i % 8));
    return abs(soma) % N;
}

/* ------------------------------------------------------------------ */
/* Valida placa no formato Mercosul: LLLNLNN                           */
int validarPlaca(char placa[]) {
    if (strlen(placa) != 7) return -1;
    if (!isalpha(placa[0]) || !isalpha(placa[1]) || !isalpha(placa[2])) return -2;
    if (!isdigit(placa[3])) return -2;
    if (!isalpha(placa[4])) return -2;
    if (!isdigit(placa[5]) || !isdigit(placa[6])) return -2;
    return 1;
}

/* ------------------------------------------------------------------ */
void inserirTabelaHash(No* tabelaHashing[], char placa[], int pos) {
    int h = hashing(placa);
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->placa, placa);
    novo->posicao = pos;
    novo->ant  = NULL;
    novo->prox = tabelaHashing[h];
    if (tabelaHashing[h] != NULL)
        tabelaHashing[h]->ant = novo;
    tabelaHashing[h] = novo;
}

/* ------------------------------------------------------------------ */
int buscar(No* tabelaHashing[], char placa[]) {
    int h = hashing(placa);
    No* atual = tabelaHashing[h];
    while (atual != NULL) {
        if (strcmp(atual->placa, placa) == 0)
            return atual->posicao;
        atual = atual->prox;
    }
    return -1;
}

/* ------------------------------------------------------------------ */
void criarIndice(FILE* arq, No* tabelaHashing[]) {
    int i;
    for (i = 0; i < N; i++)
        tabelaHashing[i] = NULL;

    CARRO c;
    int pos = 0;
    rewind(arq);
    while (fread(&c, sizeof(CARRO), 1, arq) == 1) {
        if (validarPlaca(c.placa) == 1)
            inserirTabelaHash(tabelaHashing, c.placa, pos);
        pos++;
    }
}

/* ------------------------------------------------------------------ */
void desalocarIndice(No* tabelaHashing[]) {
    int i;
    for (i = 0; i < N; i++) {
        No* atual = tabelaHashing[i];
        while (atual != NULL) {
            No* prox = atual->prox;
            free(atual);
            atual = prox;
        }
        tabelaHashing[i] = NULL;
    }
}

/* ------------------------------------------------------------------ */
void exibirOpcoes() {
    printf("\n--- Menu ---\n");
    printf("1 - Cadastrar carro\n");
    printf("2 - Consultar carro\n");
    printf("3 - Alterar carro\n");
    printf("4 - Exibir todos os carros\n");
    printf("0 - Encerrar\n");
    printf("Opcao: ");
}

/* ------------------------------------------------------------------ */
void cadastrar(FILE* arq, No* tabelaHashing[]) {
    CARRO c;
    int val;
    int pos;

    printf("Placa: ");
    fgets(c.placa, sizeof(c.placa), stdin);
    leituraSegura(c.placa);

    val = validarPlaca(c.placa);
    if (val == -1) { printf("Placa invalida: quantidade incorreta de caracteres.\n"); return; }
    if (val == -2) { printf("Placa invalida: formato incorreto (esperado LLLNLNN).\n"); return; }

    if (buscar(tabelaHashing, c.placa) != -1) {
        printf("Carro ja cadastrado.\n");
        return;
    }

    printf("Marca: ");  
    fgets(c.marca,  sizeof(c.marca),  stdin); 
    leituraSegura(c.marca);
    printf("Modelo: "); fgets(c.modelo, sizeof(c.modelo), stdin); leituraSegura(c.modelo);
    printf("Cor: ");    fgets(c.cor,    sizeof(c.cor),    stdin); leituraSegura(c.cor);

    fseek(arq, 0, SEEK_END);
    pos = (int)(ftell(arq) / sizeof(CARRO));
    fwrite(&c, sizeof(CARRO), 1, arq);
    fflush(arq);

    inserirTabelaHash(tabelaHashing, c.placa, pos);
    printf("Carro cadastrado com sucesso.\n");
}

/* ------------------------------------------------------------------ */
void consultar(FILE* arq, No* tabelaHashing[]) {
    char placa[8] = "       ";
    int val;
    int pos;
    CARRO c;

    printf("Placa: ");
    fgets(placa, sizeof(placa), stdin);
    leituraSegura(placa);

    val = validarPlaca(placa);
    if (val == -1) { printf("Placa invalida: quantidade incorreta de caracteres.\n"); return; }
    if (val == -2) { printf("Placa invalida: formato incorreto.\n"); return; }

    pos = buscar(tabelaHashing, placa);
    if (pos == -1) { printf("Carro nao encontrado.\n"); return; }

    fseek(arq, pos * sizeof(CARRO), SEEK_SET);
    fread(&c, sizeof(CARRO), 1, arq);
    printf("\nPlaca: %s | Marca: %s | Modelo: %s | Cor: %s\n",
           c.placa, c.marca, c.modelo, c.cor);
}

/* ------------------------------------------------------------------ */
void alterar(FILE* arq, No* tabelaHashing[]) {
    char placa[8] = "       ";
    char campo[4] = "   ";
    int val;
    int pos;
    int escolha;
    CARRO c;

    printf("Placa: ");
    fgets(placa, sizeof(placa), stdin);
    leituraSegura(placa);

    val = validarPlaca(placa);
    if (val == -1) { printf("Placa invalida: quantidade incorreta de caracteres.\n"); return; }
    if (val == -2) { printf("Placa invalida: formato incorreto.\n"); return; }

    pos = buscar(tabelaHashing, placa);
    if (pos == -1) { printf("Carro nao encontrado.\n"); return; }

    fseek(arq, pos * sizeof(CARRO), SEEK_SET);
    fread(&c, sizeof(CARRO), 1, arq);
    printf("\nDados atuais:\nMarca: %s | Modelo: %s | Cor: %s\n",
           c.marca, c.modelo, c.cor);

    printf("\nO que deseja alterar?\n1-Marca  2-Modelo  3-Cor  0-Cancelar\nOpcao: ");
    fgets(campo, sizeof(campo), stdin);
    leituraSegura(campo);
    escolha = campo[0] - '0';
    switch (escolha) {
        case 1: printf("Nova marca: ");  fgets(c.marca,  sizeof(c.marca),  stdin); leituraSegura(c.marca);  break;
        case 2: printf("Novo modelo: "); fgets(c.modelo, sizeof(c.modelo), stdin); leituraSegura(c.modelo); break;
        case 3: printf("Nova cor: ");    fgets(c.cor,    sizeof(c.cor),    stdin); leituraSegura(c.cor);    break;
        case 0: printf("Cancelado.\n"); return;
        default: printf("Opcao invalida.\n"); return;
    }

    fseek(arq, pos * sizeof(CARRO), SEEK_SET);
    fwrite(&c, sizeof(CARRO), 1, arq);
    fflush(arq);
    printf("Dados alterados com sucesso.\n");
}

/* ------------------------------------------------------------------ */
void exibirCadastro(FILE* arq) {
    CARRO c;
    int encontrou = 0;
    rewind(arq);
    while (fread(&c, sizeof(CARRO), 1, arq) == 1) {
        if (validarPlaca(c.placa) == 1) {
            printf("Placa: %s | Marca: %s | Modelo: %s | Cor: %s\n",
                   c.placa, c.marca, c.modelo, c.cor);
            encontrou = 1;
        }
    }
    if (!encontrou)
        printf("Nenhum carro cadastrado.\n");
}