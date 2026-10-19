#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    char nome1[15];
    char nome2[15];

    printf("Digite a primeira palavra: ");
    scanf("%s", nome1);
    printf("Digite a segunda palavra: ");
    scanf("%s", nome2);

    if (strcmp(nome1, nome2) == 0) {
        printf("Sao iguais \n\n");
    }
    else {
        printf("Sao diferentes \n\n");
    }
return 0;
}



