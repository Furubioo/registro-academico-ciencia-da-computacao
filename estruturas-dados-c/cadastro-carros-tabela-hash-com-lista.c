#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
void fecharArquivo(FILE* arq);
void liberarArquivo(FILE *arq);
int buscar(No* tabelaHashing[], char placa[]);
void cadastrar(FILE* arq, No* tabelaHashing[]);
void consultar(FILE* arq, No* tabelaHashing[]);
void alterar(FILE* arq, No* tabelaHashing[]);
void exibirCadastro(FILE* arq);
void criarIndice(FILE* arq, No* tabelaHashing[]);
void inserirTabelaHash(No* tabelaHashing[], char placa[], int pos);
int hashing(char placa[]);
void exibirOpcoes();
void desalocarIndice(No* tabelaHashing[]);
int validacaoDaPlaca(char placa[]);
void leituraSegura(char str[]);
 
int main() {
	char nomeArq[] = "carros.dat";
	int op;
	FILE* cadastro;
	No* tabelaHashing[N];
	cadastro = prepararArquivo(nomeArq);
	if (cadastro == NULL)
		printf("Erro na abertura do arquivo. Programa encerrado \n");
	else {
		criarIndice(cadastro, tabelaHashing);
		do {
			exibirOpcoes();
			scanf("%d",&op);
			while (getchar() != '\n');
			switch (op) {
			case 1: cadastrar(cadastro, tabelaHashing);
		                              break;
			case 2: consultar(cadastro, tabelaHashing);
			             break;
			case 3: alterar(cadastro, tabelaHashing);
			             break;
			case 4: exibirCadastro(cadastro);
			             break;
			case 0: liberarArquivo(cadastro);
			             desalocarIndice(tabelaHashing);
			             break;
			default: printf("Opcao invalida \n");
			}
		} while (op != 0);
	}
	return 0;
}

void leituraSegura(char str[]) {
    int i, tam; tam = strlen(str);
    for (i = 0; i < tam; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}
 
FILE* prepararArquivo(char nome[]) {
 
	FILE *arq;
	arq = fopen(nome,"r+b");
	if (arq == NULL) {
		printf("Arquivo nao encontrado. Criando arquivo...\n");
		arq = fopen(nome, "w+b");
		if (arq == NULL) {
			printf("Erro ao tentar abrir/criar o arquivo.\n");
		}
	}
    return arq;

	 /* Tenta abrir o arquivo para leitura e gravação.
      * Caso não consiga abrir o arquivo, tenta criá-lo para leitura e gravação.
      */ 
}
 
void fecharArquivo(FILE *arq) {
	int result;
 
	result = fclose(arq);
	if (result == 0) {
		printf("Arquivo fechado com sucesso!\n");
	}
	else {
		printf("Falha ao fechar o arquivo.\n");
	}
 
}
 
void liberarArquivo(FILE* arq) {
    CARRO c;
    FILE *arqNovo;
	char nomeNovo[30] = "novoCarros.dat";

    arqNovo = fopen(nomeNovo, "w+b");
    if (arqNovo == NULL) {
        printf("Erro ao criar arquivo.\n");
        fecharArquivo(arq);
        return;
    }
    fseek(arq, 0, SEEK_SET);
    while (fread(&c, sizeof(CARRO), 1, arq) == 1) {
        if (validacaoDaPlaca(c.placa) == 1) {
            fwrite(&c, sizeof(CARRO), 1, arqNovo);
        }
    }
    fclose(arqNovo);
    fclose(arq);
    remove("carros.dat");
    rename(nomeNovo, "carros.dat");
    printf("Processo de liberacao de arquivo finalizado.\n");
 
	/* Apagar, fisicamente, os registros que foram deletados logicamente e fechar o arquivo.
	*      1.1 - Criar um arquivo novo (vazio).
	*      1.2 - Copiar todos os registros de STATUS igual a 1 do arquivo de carros para o arquivo novo.
	*      1.3 - Fechar os dois arquivos.
	*      1.4 - Remover o arquivo de carros ("carros.dat").
	*      1.5 - Renomear o arquivo novo com o nome "carros.dat".
	*/
}
 
void criarIndice(FILE* arq, No* tabelaHashing[]) {
    int i;
    CARRO c;

    for (i = 0; i < N; i++) {
        tabelaHashing[i] = NULL;
    }
    int posicao = 0;
    fseek(arq, 0, SEEK_SET);
    while (fread(&c, sizeof(CARRO), 1, arq) == 1) {
        if (validacaoDaPlaca(c.placa) == 1) {
            inserirTabelaHash(tabelaHashing, c.placa, posicao);
            posicao++;
        }
    }

	/* Preencher a tabela de hashing com as chaves dos registros que estão armazenados no arquivo
	       1.1 - Ler o arquivo registro a registro até o final.
	       1.2 - Para cada registro lido, aplicar a função de hashing à chave (ou seja, a placa).
	       1.3 - O resultado da função indica a posição na tabela onde a chave será inserida.
	       1.4 - Criar nó, preencher com a chave e a posição dela no arquivo e inserir na tabela, 
	                na lista encadeada correspondente, de forma que a lista permaneça ordenada 
                                 por ordem crescente de placa.
	*/
}
 
void desalocarIndice(No* tabelaHashing[]) {
	int i;
    No *atual, *prox;
    for (i = 0; i < N; i++) {
        atual = tabelaHashing[i];
        while (atual != NULL) {
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
        tabelaHashing[i] = NULL;
    }
    
    /* Desalocar os nós que compõem as listas da tabela de hashing.
	*/
}
 
void exibirOpcoes() {
	printf("\nOpcoes \n");
	printf("1 - Cadastrar um carro \n");
	printf("2 - Consultar carro \n");
	printf("3 - Alterar dados do carro \n");
	printf("4 - Exibir carros cadastrados \n");
	printf("0 - Encerrar programa \n");
	printf("Informe a opcao: ");
}
 
int buscar(No* tabelaHashing[], char placa[]) {
	int h;
    No *atual;
    h = hashing(placa);
    atual = tabelaHashing[h];
    
    while (atual != NULL) {
        if (strcmp(atual->placa, placa) == 0) {
            return atual->posicao;
        }
        atual = atual->prox;
    }
    return -1;
    
    /* Procurar na tabela de hashing a placa desejada e retornar a posição da placa no arquivo.
	   1 - Aplicar a função de hashing na chave (ou seja, na placa).
	   2 - Procurar a chave na lista indicada pelo resultado da função (usar busca sequencial melhorada).
	   3 - Caso encontre, retornar a posição da chave no arquivo.
	   4 - Caso não encontre, retornar -1 
                 */
}
 
void inserirTabelaHash(No* tabelaHashing[], char placa[], int pos) {
	int h;
    No *novo;
    h = hashing(placa);
    novo = (No*) malloc(sizeof(No));
    strcpy(novo->placa, placa);
    novo->posicao = pos;
    novo->ant = NULL;
    novo->prox = tabelaHashing[h];
    if (tabelaHashing[h] != NULL) {
        tabelaHashing[h]->ant = novo;
    }
    tabelaHashing[h] = novo;
    
    /* Inserir na tabela hashing, na lista encadeada indicada pela função de hashing, 
	* uma chave e sua posição no arquivo.
	* 1 - Aplicar a função de hashing à chave (ou seja, a placa).
	* 2 - O resultado da função indica a posição na tabela onde a chave será inserida.
	* 3 - Criar nó, preencher com a chave e a posição dela no arquivo e inserir na tabela, 
	* na lista encadeada correspondente, de forma que a lista permaneça ordenada 
                 * por ordem crescente de placa.
	*/
}
 
int hashing(char placa[]) {
    int i, soma = 0, tam = strlen(placa);
    for (i = 0; i < tam; i++) {
        soma = soma + (placa[i] << (i % 8));
    }
    return abs(soma) % N;

	/* A função “hashing” recebe com parâmetro a chave (ou seja, a placa) e 
	* retorna o valor calculado segundo o método da permutação para chaves alfanuméricas 
	* (visto em sala).
	*/
}
 
void cadastrar(FILE* arq, No* tabelaHashing[]) {
    CARRO c, tmp;
    int val;
    int pos;

   char placaBuf[32];
    printf("Placa: ");
    fgets(placaBuf, sizeof(placaBuf), stdin);
    leituraSegura(placaBuf);
    strncpy(c.placa, placaBuf, 7);
    c.placa[7] = '\0';

    val = validacaoDaPlaca(c.placa);
    if (val == -1) {
        printf("Placa invalida: quantidade incorreta de caracteres.\n");
        return;
    }
    else if (val == -2) {
        printf("Placa invalida: formato incorreto (esperado LLLNLNN)\n");
        return;
    }

    if (buscar(tabelaHashing, c.placa) != -1) {
        printf("Carro ja cadastrado.\n");
        return;
    }

    printf("Marca: ");
    fflush(stdout);
    fgets(c.marca, sizeof(c.marca), stdin);
    leituraSegura(c.marca);

    printf("Modelo: ");
    fflush(stdout);
    fgets(c.modelo, sizeof(c.modelo), stdin);
    leituraSegura(c.modelo);

    printf("Cor: ");
    fflush(stdout);
    fgets(c.cor, sizeof(c.cor), stdin);
    leituraSegura(c.cor);

    pos = 0;
    fseek(arq, 0, SEEK_SET);
    while (fread(&tmp, sizeof(CARRO), 1, arq) == 1) {
        pos++;
    }
    fwrite(&c, sizeof(CARRO), 1, arq);
    fflush(arq);

    inserirTabelaHash(tabelaHashing, c.placa, pos);
    printf("Carro cadastrado com sucesso.");

	/* Cadastrar o registro do carro no arquivo e inserir a chave (placa) na tabela de hashing.
	* 1 - Solicita a placa do carro a ser cadastrado.
	* 2 - Procura pela placa na tabela de hashing.
	* 3 - Caso encontre, informa que o carro já está no cadastro.
	* 4 - Caso não encontre, solicita os demais dados do carro, o insere no final do arquivo.
	* 5 - Insere a chave, juntamente com sua posição no arquivo, na tabela de hashing.
	*     Utilize para isso o procedimento "inserirTabelaHash".
	*/
}
 
void consultar(FILE* arq, No* tabelaHashing[]) {
    int valor;
    int posicao;
    char placa[8];
    char placaBuf[32];

    printf("Placa: ");
    fflush(stdout);
    fgets(placaBuf, sizeof(placaBuf), stdin);
    leituraSegura(placaBuf);
    strncpy(placa, placaBuf, 7);
    placa[7] = '\0';
    CARRO c;
    valor = validacaoDaPlaca(placa);
    if (valor == -1) {
        printf("Placa invalida: quantidade incorreta de caracteres.\n");
        return;
    }
    else if (valor == -2) {
        printf("Placa invalida: formato incorreto.\n");
        return;
    }

    posicao = buscar(tabelaHashing, placa);
    if (posicao == -1) {
        printf("Carro nao encontrado.\n");
        return;
    }

    fseek(arq, posicao * sizeof(CARRO), SEEK_SET);
    fread(&c, sizeof(CARRO), 1, arq);
    printf("\nPlaca: %s\n", c.placa);
    printf("Marca: %s\n", c.marca);
    printf("Modelo: %s\n", c.modelo);
    printf("Cor: %s\n", c.cor);



	/* Consultar o registro do carro no arquivo
                  * 1 - Solicita a placa do carro a ser consultado.
                  * 2 - Procura pela placa na tabela de hashing.
                  * 3 - Caso não encontre, informa que o carro não está no cadastro.
                  * 4 - Caso encontre, vai ao arquivo, na posição indicada, 
	 *     lê o registro do carro e exibe seus dados.
                  */
}
 
void alterar(FILE* arq, No* tabelaHashing[]) {
    char placa[8] = "       ";
    char campo[4] = "   ";
    int val;
    int pos;
    int escolha;
    CARRO c;

   char placaBuf[32];
    printf("Placa: ");
    fflush(stdout);
    fgets(placaBuf, sizeof(placaBuf), stdin);
    leituraSegura(placaBuf);
    strncpy(placa, placaBuf, 7);
    placa[7] = '\0';

    val = validacaoDaPlaca(placa);
    if (val == -1) {
        printf("Placa invalida: quantidade incorreta de caracteres.\n"); 
        return; 
    }
    if (val == -2) {
        printf("Placa invalida: formato incorreto.\n");
        return; 
    }

    pos = buscar(tabelaHashing, placa);
    if (pos == -1) {
        printf("Carro nao encontrado.\n");
        return; 
    }

    fseek(arq, pos * sizeof(CARRO), SEEK_SET);
    fread(&c, sizeof(CARRO), 1, arq);
    printf("\nDados atuais: \n");
    printf("1 - Marca: %s\n", c.marca);
    printf("2 - Modelo: %s\n", c.modelo);
    printf("3 - Cor: %s\n", c.cor);

    printf("\nO que deseja alterar?\n");
    printf("1 - Marca \n");
    printf("2 - Modelo\n");
    printf("3 - Cor\n");
    printf("0 - Cancelar\n");
    printf("\nOpcao: ");
    fgets(campo, sizeof(campo), stdin);
    leituraSegura(campo);
    escolha = campo[0] - '0';
    switch (escolha) {
        case 1: 
            printf("Nova marca: ");  
            fflush(stdout);
            fgets(c.marca,  sizeof(c.marca),  stdin); 
            leituraSegura(c.marca);  
            break;
        case 2: 
            printf("Novo modelo: "); 
            fflush(stdout);
            fgets(c.modelo, sizeof(c.modelo), stdin); 
            leituraSegura(c.modelo); 
            break;
        case 3: 
            printf("Nova cor: ");    
            fflush(stdout);
            fgets(c.cor,    sizeof(c.cor),    stdin); 
            leituraSegura(c.cor);    
            break;
        case 0: 
            printf("Cancelado.\n"); 
            return;
        default: 
            printf("Opcao invalida.\n"); 
            return;
    }

    fseek(arq, pos * sizeof(CARRO), SEEK_SET);
    fwrite(&c, sizeof(CARRO), 1, arq);
    fflush(arq);
    printf("Dados alterados com sucesso.\n");

	/* Alterar o registro do carro no arquivo.
	 * 1 - Solicita a placa do carro a ser alterado.
	 * 2 - Procura pela placa na tabela de hashing.
	 * 3 - Caso não encontre, informa que o carro não está no cadastro.
	 * 4 - Caso encontre, vai ao arquivo, na posição indicada, lê o registro do carro e 
                         exibe seus dados.
	 * 5 - Pergunta ao usuário quais dados deseja alterar. Efetiva a alteração dos dados no arquivo.
	*/
}

int validacaoDaPlaca(char placa[]) {

    if (strlen(placa) != 7){
        return -1;
    } 
    if (!isalpha(placa[0]) || !isalpha(placa[1]) || !isalpha(placa[2])) {
        return -2;
    } 
    if (!isdigit(placa[3])) {
        return -2;
    }
    if (!isalpha(placa[4])) {
        return -2;
    } 
    if (!isdigit(placa[5]) || !isdigit(placa[6])) {
        return -2;
    }
    return 1;
}
 
void exibirCadastro(FILE* arq) {
    CARRO c;
    int encontrou = 0;
    fseek(arq, 0, SEEK_SET);
    rewind(arq);
    while (fread(&c, sizeof(CARRO), 1, arq) == 1) {
        if (validacaoDaPlaca(c.placa) == 1) {
            printf("Placa: %s \n", c.placa);
            printf("Marca: %s\n", c.marca);
            printf("Modelo: %s\n", c.modelo);
            printf("Cor: %s\n", c.cor);
            encontrou = 1;
        }
    }
    if (!encontrou)
        printf("Nenhum carro cadastrado.\n");

	/* Exibe todos os registros de carros ATIVOS constantes no arquivo. */
}