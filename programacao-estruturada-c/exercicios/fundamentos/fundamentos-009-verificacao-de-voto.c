#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, votante = 0, nvotante = 0, total, percvotantes, percnvotantes, idade , pessoa = 0;

    printf("**Verificacao de voto** \n\n");

    for (i = 0; i < 100; i++) {
        
        printf("Digite a sua idade[usuario %d]: ", pessoa);
        scanf("%d", &idade);

        if (idade < 0 || idade > 120) {
            printf("Idade invalida! \n");
            printf("Digite a sua idade: ");
            scanf("%d", &idade);
        }

        if (idade >= 18 && idade <= 90) {
            printf("Esta pessoa tem %d anos e pode votar. \n", idade);
            votante++;
        }
        else {
            printf("Esta pessoa tem %d anos e nao pode votar. \n", idade);
            nvotante++;
        }
        pessoa++;
    }    
        total = votante + nvotante;
        printf("Total de pessoas: %d \n", total);

        percvotantes = (votante * 100.0) / total;
        printf("Percentual de votantes: %d%% \n", percvotantes);

        percnvotantes = (nvotante * 100.0) / total;
        printf("Percentual de nao votantes: %d%% \n", percnvotantes);

    return 0;
}

