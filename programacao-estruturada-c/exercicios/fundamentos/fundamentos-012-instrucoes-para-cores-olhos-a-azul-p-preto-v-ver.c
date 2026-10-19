#include <stdio.h>
#include <stdlib.h>

int main() {

    int idade, qtdIdade = 0, idadeM50 = 0, pesom60 = 0, ruivosemolhoazul = 0, i, idadeM50epesom60 = 0;
    float altura = 0, idades = 0, media, peso, olhoazul = 0, alturamenor = 0, percentual, qtdPessoas;
    char o, c;

        printf("Instrucoes para cores: \n \nOlhos: 'A'(azul), 'P'(preto), 'V'(verde), 'C'(castanho) \n \n");
        printf("Cabelos: 'P'(preto), 'C'(castanho), 'L'(loiro), 'R'(ruivo) \n \n");

        printf("Informe a quantidade de pessoas do grupo(minimo: 1 pessoa): ");
        scanf("%f", &qtdPessoas);

        while(qtdPessoas < 1) {
            printf("Valor invalido! \n");
            printf("Informe uma qtd correta: ");
            scanf("%f", &qtdPessoas);
        }

        for(i = 1; i <= qtdPessoas;i++) {
            printf("\nPessoa [%d]\n\n", i);

            printf("Informe a idade: ");
            scanf("%d", &idade);
            if (idade > 50) {
                idadeM50 +=1;
            }
            qtdIdade += idade;

            while(idade < 1 || idade > 120) {
                printf("Valor invalido! \n\n");
                printf("Informe novamente: ");
                scanf("%d", &idade);
            }

            printf("Informe o peso: ");
            scanf("%f", &peso);

            while(peso < 3 || peso > 300) {
                printf("Valor invalido! \n");
                printf("Informe novamente: ");
                scanf("%f", &peso);
            }

            if (peso < 60) {
                pesom60 += 1;
            }

            if (idadeM50 == pesom60) {
                idadeM50epesom60 += 1;
            }

            printf("Informe a altura: ");
            scanf("%f", &altura);


            while(altura < 0 || altura < 0.5 || altura > 2.5) {
                printf("Valor invalido! \n");
                printf("Informe a altura: ");
                scanf("%f", &altura);
            }

            if (altura < 1.50) {
                idades += idade;
                alturamenor += 1;
            }

            printf("Informe a cor dos olhos: ");
            scanf(" %c", &o);
        
            while(o != 'A' && o != 'P' && o != 'V' && o != 'C') {
                printf("Caractere invalido! \n");
                printf("Informe a cor dos olhos: ");
                scanf(" %c", &o);
            }
            if (o == 'A') {
                olhoazul +=1;
            }

            printf("Informe a cor dos cabelos: ");
            scanf(" %c", &c);

            while(c != 'P' && c != 'C' && c != 'L' && c != 'R') {
                printf("Caractere invalido! \n");
                printf("Informe a cor dos cabelos: ");
                scanf(" %c", &c);
            }

            if (o != 'A' && c =='R') {
                ruivosemolhoazul += 1;
            }
            printf("\n");
        }

        printf("\n");
        
        printf("A quantidade de pessoas com idade superior a 50 anos e peso inferior a 60 quilos eh: %d \n\n", idadeM50epesom60);
        media = idades / alturamenor;
        printf("A media das idades com altura inferior a 1.50 eh: %.2f\n\n", media);
        percentual = ((100.0) * olhoazul) / (qtdPessoas);
        printf("O percentual de pessoas com olhos azuis entre todas as pessoas citadas eh de %.2f%%\n\n", percentual);
        printf("A quantidade de pessoas ruivas e que nao possuem olhos azuis eh: %d\n\n", ruivosemolhoazul);

    return 0;
}

