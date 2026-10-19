#include <stdio.h>
#include <stdlib.h>

int main() {
    float nota;
    printf("Digite a sua nota: ");
    scanf("%f", &nota);
    if(nota >=9 && nota <=10) {
        printf("O conceito para a sua nota eh A");
    }
    else if(nota >=7 && nota <=8.9){
        printf("O conceito para a sua nota eh B");
    }
    else if(nota >=5 && nota <=6.9) {
        printf("O conceito para a sua nota eh C");
    }
    else if(nota >=3 && nota <=4.9) {
        printf("O conceito para a sua nota eh D");
    }
    else if(nota >=0 && nota <=2.9){
        printf("O conceito para a sua nota eh F");
    }
return 0;
}

