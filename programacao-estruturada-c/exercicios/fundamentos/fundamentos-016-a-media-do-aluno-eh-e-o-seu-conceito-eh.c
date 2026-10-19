#include <stdio.h>
#include <stdlib.h>

float funcao1(float media) {

    char conceito;

    if (media >= 0 && media < 5) {
        conceito = 'D';
        printf("%c. ", conceito);
        printf("\n\n");
    }
    else if (media >= 5 && media < 7) {
        conceito = 'C';
        printf("%c. ", conceito);
        printf("\n\n");
    }
    else if (media >= 7 && media < 9) {
        conceito = 'B';
        printf("%c. ", conceito);
        printf("\n\n");
    }
    else if (media >= 9 && media <= 10) {
        conceito = 'A';
        printf("%c. ", conceito);
        printf("\n\n");
    }

    return conceito;

}

void proc1(float N1, float N2) {

    float media;

    media = (N1 + N2) / 2;
    
    printf("A media do aluno eh %.2f e o seu conceito eh ", media);
    funcao1(media);
}

int main() {

    float n1, n2, i;
    int alunos;

    printf("Informe quantos alunos farao a verificacao: ");
    scanf("%d", &alunos);

    while (alunos < 1) {
        printf("Informe uma quantidade de alunos valida: ");
        scanf("%d", &alunos);
    }

    for(i = 1; i <= alunos; i++) {

        printf("Aluno [%.0f]\n\n", i);

        printf("Digite a nota da sua primeira avaliacao: ");
        scanf("%f", &n1);
        printf("Digite a nota da sua segunda avaliacao: ");
        scanf("%f", &n2);

        while (n1 < 0 || n1 > 10) {
            printf("Valor para nota invalido! \nInforme novamente.\n\n");
            printf("Digite a nota da sua primeira avaliacao: ");
            scanf("%f", &n1);
        }

        while(n2 < 0 || n2 > 10) {
            printf("Valor para nota invalido! \nInforme novamente.\n\n");
            printf("Digite a nota da sua segunda avaliacao: ");
            scanf("%f", &n2);
        }

        proc1(n1,n2);

    }
    return 0;
}

