#include <stdio.h>
#include <stdlib.h>

int main() {
    int lado1;
    int lado2;
    int lado3;

    printf("Digite, em centimetros, o primeiro lado do triangulo: \n");
    scanf("%d", &lado1);
    printf("Digite, em centimetros, o segundo lado do triangulo: \n");
    scanf("%d", &lado2);
    printf("Digite, em centrimetros, o terceiro lado do triangulo: \n");
    scanf("%d", &lado3);

    if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3){
        printf("O seu triangulo eh equilatero \n\n");
    }
    else if(lado1 == lado2 || lado1 == lado3 || lado2 == lado3){
        printf("O seu triangulo eh isosceles \n\n");
    }
    else if(lado1 != lado2 && lado2 != lado3 && lado3 != lado1){
        printf("O seu triangulo eh escaleno \n\n");
    }
return 0;
}

