#include <stdio.h>
#include <stdlib.h>

int main() {

    int idade, qtdIdade, qtdPeso, qtdAltura, qtdO, qtdsoma1, qtdAzulR, qtdPessoas, percOlhoazul;
    float altura, media, peso, qtdC;
    char o, c;

        printf("Instrucoes para cores: \n \nOlhos: 'A'(azul), 'P'(preto), 'V'(verde), 'C'(castanho) \n \n");
        printf("Cabelos: 'P'(preto), 'C'(castanho), 'L'(loiro), 'R'(ruivo) \n \n");

        printf("Informe a quantidade de pessoas do grupo(minimo: 1 pessoa): ");
        scanf("%d", &qtdPessoas);

        while(qtdPessoas < 1) {
            printf("Valor invalido! \n");
            printf("Informe uma qtd correta: ");
            scanf("%d", &qtdPessoas);
        }

        printf("Informe a idade: ");
        scanf("%d", &idade);

        while(idade < 0 || idade > 120) {
            printf("Valor invalido! \n");
            printf("Informe novamente: ");
            scanf("%d", &idade);
        }

        printf("Quantas pessoas possuem essa idade? ");
        scanf("%d", &qtdIdade);
        
        while(qtdIdade > qtdPessoas) {
            printf("Quantidade invalida! \n");
            printf("Informe novamente: ");
            scanf("%d", &qtdIdade);
        }

        while(qtdIdade < 0) {
            printf("Quantidade invalida! \n");
            printf("Informe novamente: ");
            scanf("%d", &qtdIdade);
        }

        printf("Informe o peso: ");
        scanf("%f", &peso);

        while(peso < 3 || peso > 300) {
            printf("Valor invalido! \n");
            printf("Informe o peso: ");
            scanf("%f", &peso);
        }

        printf("Quantas pessoas possuem esse peso? ");
        scanf("%d", &qtdPeso);

        while (qtdIdade > qtdPessoas || qtdIdade < 0) {
            printf("Quantidade invalida! \n");
            printf("Informe novamente: ");
            scanf("%d", &qtdIdade);
        }
        

        printf("Informe a altura: ");
        scanf("%f", &altura);


        while(altura < 0 || altura < 0.5 || altura > 2.5) {
            printf("Valor invalido! \n");
            printf("Informe a altura: ");
            scanf("%f", &altura);
        }

        printf("Quantas pessoas possuem essa altura? ");
        scanf("%d", &qtdAltura);

        while (qtdAltura < 0 || qtdAltura > qtdPessoas) {
            printf("Quantidade invalida! \n");
            printf("Informe novamente: ");
            scanf("%d", &qtdAltura);
        }
        

        printf("Informe a cor dos olhos: ");
        scanf(" %c", &o);
        
        while(o != 'A' && o != 'P' && o != 'V' && o != 'C') {
            printf("Caractere invalido! \n");
            printf("Informe a cor dos olhos: ");
            scanf(" %c", &o);
        }

        printf("Quantas pessoas possuem essa cor de olhos? ");
        scanf("%d", &qtdO);

        while (qtdO < 0 || qtdO > qtdPessoas) {
            printf("Valor de quantidade invalido!\n");
            printf("Quantas pessoas possuem essa cor de olhos? ");
            scanf("%d", &qtdO);
        }
        

        printf("Informe a cor dos cabelos: ");
        scanf(" %c", &c);

        while(c != 'P' && c != 'C' && c != 'L' && c != 'R') {
            printf("Caractere invalido! \n");
            printf("Informe a cor dos cabelos: ");
            scanf(" %c", &c);
        }

        printf("Quantas pessoas possuem essa cor de cabelos? ");
        scanf("%f", &qtdC);

        while(qtdC < 0 || qtdC > qtdPessoas) {
            printf("Valor de quantidade invalido!\n");
            printf("Quantas pessoas possuem essa cor de cabelos? ");
            scanf("%f", &qtdC);
            printf("\n\n");
        }

        printf("\n");
        
        if (idade > 50 && peso < 60) {
            qtdsoma1 = qtdIdade + qtdPeso;
            printf("A quantidade de pessoas com idade superior a 50 anos e peso inferior a 60 eh: %d. \n\n", qtdsoma1);
        }
        else if(idade > 50) {
            printf("A quantidade de pessoas com idade superior a 50 anos eh %d \n\n", qtdIdade);
        }
        else if (peso < 60) {
            printf("A quantidade de pessoas com peso inferior a 60 eh: %d \n\n", qtdPeso);
        }
        else if (idade < 50 && peso > 60){
            printf("Nao ha quantidade de pessoas com idade superior a 50 anos e peso inferior a 60. \n\n");
        }
        if (altura < 1.50) {
            media = (qtdIdade * idade) / qtdPessoas;
            printf("A media das idades das pessoas com altura inferior a 1.50 eh %.2f. \n\n", media);
        }
        else {
            printf("Nao ha pessoas com altura inferior a 1.50. \n\n");
        }
        if (o == 'A') {
            percOlhoazul = (qtdO * 100.0) / qtdPessoas;
            printf("O percentual de pessoas com olhos azuis eh de %d%%. \n\n", percOlhoazul);
        }
        else {
            printf("Nao ha pessoas com olhos azuis nesse grupo de pessoas(%d). \n\n", qtdPessoas);
        }
        if (c == 'R' && o != 'A') {
            qtdAzulR = qtdO + qtdC;
            printf("A quantidade de pessoas ruivas e que nao possuem olhos azuis eh %d. \n\n", qtdAzulR);
        }     
        else {
            printf("Simultaneamente, nao ha quantidade de pessoas ruivas que nao possuam olhos azuis. \n\n");
        }

    return 0;
}

