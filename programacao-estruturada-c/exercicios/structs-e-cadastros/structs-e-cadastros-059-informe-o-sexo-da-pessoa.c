#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 3

typedef struct pessoa {

    char nome[51];
    float salario;
    int idade;
    char sexo;
    int filhos;



}   Pessoa;

typedef struct salario {

    float maiorM;
    float maiorF;


}   salario;



void leituraS(char vet[], int tam) {

    int i;
    (void) tam;

    for (i = 0; i < (int) strlen(vet); i++) {
        if (vet[i] == '\n') {
            vet[i] = '\0';
        }
    }

}

void preencher(Pessoa vet[], int tam) {

    int i;
    (void) tam;

    for (i = 0; i < TAM; i ++) {

        printf("\nInforme o sexo da pessoa %d: ", i + 1);
        scanf("%c", &vet[i].sexo);
        getchar();

        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(vet[i].nome, 51, stdin);
        leituraS(vet[i].nome, strlen(vet[i].nome));

        printf("Informe o idade da pessoa %d: ", i + 1);
        scanf("%d", &vet[i].idade);

        printf("Digite o salario da pessoa %d: ", i + 1);
        scanf("%f", &vet[i].salario);
        getchar();
        printf("Digite a quantidade de filhos da pessoa %d: ", i + 1);
        scanf("%d", &vet[i].filhos);

        getchar();

    }

}

float mediaH(Pessoa vet[], int tam) {

    int i, cont = 0; 
    float soma = 0, media;


    for (i = 0; i < tam; i++) {

        if (vet[i].salario == 0 && tolower(vet[i].sexo) == 'm') {
            soma += vet[i].idade;
            cont++;
        }
    }
    media = soma / cont;
    if (media >= 1) {
        return media;
    }
    else {
        return 0;
    }

}

salario maiorS(Pessoa vet[], int tam) {

    int i;
    float maiorM = vet[0].salario, maiorF = vet[0].salario;

    salario valorMouF;

    valorMouF.maiorM = maiorM;
    valorMouF.maiorF = maiorF;

    for (i = 0; i < tam; i++) {
        
        if (tolower(vet[i].sexo) == 'm') {
            if (vet[i].salario > maiorM) {
                valorMouF.maiorM = vet[i].salario;
            }
        }
        if (tolower(vet[i].sexo) == 'f') {
            if (vet[i].salario > maiorF) {
                valorMouF.maiorF = vet[i].salario;
            }
        }
    }

    return valorMouF;

}

float percentual(Pessoa vet[], int tam) {

    int i;

    float perc;

    int cont = 0, cont1 = 0;

    for (i = 0; i < tam; i++) {
        if (tolower(vet[i].sexo) == 'f') {
            cont++;
        }

        if (tolower(vet[i].sexo) == 'f' && vet[i].idade >= 18 && vet[i].idade <= 25 && vet[i].filhos > 0) {
            cont1++;
        
        }

    }
    perc = ((float) cont1 / cont) * 100;

    return perc;


}

int main() {

    Pessoa vet[TAM];

    float valor;

    salario M, F;

    float valor1;



    preencher(vet, TAM);
    valor = mediaH(vet, TAM);
    printf("\nIdade media dos homens desempregados: %.2f \n", valor);
    M = maiorS(vet, TAM);
    printf("Maior salario entre os homens: %.2f \n", M.maiorM);
    F = maiorS(vet, TAM);
    printf("Maior salario entre as mulheres: %.2f \n \n", F.maiorF);
    valor1 = percentual(vet, TAM);
    printf("O percentual de mulheres com idade entre 18 e 25 anos e que possuam mais de 2 filhos eh: %.2f%% ", valor1);


    return 0;
}

// Lista 3 de struct

