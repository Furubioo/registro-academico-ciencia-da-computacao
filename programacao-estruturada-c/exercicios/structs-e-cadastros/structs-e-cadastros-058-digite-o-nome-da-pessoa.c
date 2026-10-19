#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 5

typedef struct pessoa {

    char nome[51];
    char matricula[51];
    int escolaridade;
    int tempservico;
    float salario;

} Pessoa;

void leituraS(char vet[], int tamvet) {

    int i;

    for (i = 0; i < tamvet; i++) {
        if (vet[i] == '\n') {
            vet[i] = '\0';
        }
    }

}

void preencher(Pessoa vet[]) {

    int i;

    for (i = 0; i < TAM; i++) {
        printf("\nDigite o nome da pessoa %d: ", i + 1);
        fgets(vet[i].nome, 51, stdin);
        leituraS(vet[i].nome, strlen(vet[i].nome));  
        
        printf("Digite a matricula da pessoa %d: ", i + 1);
        fgets(vet[i].matricula, 51, stdin);
        leituraS(vet[i].matricula, strlen(vet[i].matricula));
        

        printf("Informe a escolaridade da pessoa %d: ", i + 1);
        scanf("%d", &vet[i].escolaridade);
        

        printf("Informe o tempo de servico da pessoa %d: ", i + 1);
        scanf("%d", &vet[i].tempservico);
        

        printf("Informe o salario da pessoa %d: ", i + 1);
        scanf("%f", &vet[i].salario);
        
        getchar();

    }

}

void aumento(Pessoa vet[]) {

    int i;

    for (i = 0; i < TAM; i++) {
        if (vet[i].escolaridade == 3 && vet[i].tempservico >= 5 && vet[i].salario < 1000) {
            vet[i].salario = vet[i].salario + (0.2 * vet[i].salario);
        }
    }



}


void exibir(Pessoa vet[]) {

    int i;

    for (i = 0; i < TAM; i++) {
        if (vet[i].escolaridade == 3 && vet[i].tempservico >= 5 && vet[i].salario < 1000) {
            printf("Nome: %s \n", vet[i].nome);
            printf("Matricula: %s \n", vet[i].matricula);
            printf("Salario atual: %.2f \n", vet[i].salario);
            aumento(vet);
            printf("Novo salario: %.2f \n", vet[i].salario);
            printf("\n");
        }
    }

}

int main() {

    Pessoa vetor[50];

    printf("Preenchimento das informacoes: \n\n");
    preencher(vetor);
    printf("Pessoas com aumento: \n\n");
    exibir(vetor);
    
    return 0;
}

// Questão 3

