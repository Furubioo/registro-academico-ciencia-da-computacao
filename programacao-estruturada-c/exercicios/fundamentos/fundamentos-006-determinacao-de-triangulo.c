#include <stdio.h>
#include <stdlib.h>

int main() {

    float seg1, seg2, seg3;

    printf("Determinacao de triangulo\n\n");

    printf("Informe, em cm, o primeiro segmento: ");
    scanf("%f", &seg1);
    printf("Informe, em cm, o segundo segmento: ");
    scanf("%f", &seg2);
    printf("Informe, em cm, o terceiro segmento: ");
    scanf("%f", &seg3);

    if (seg1 < seg2 + seg3 || seg2 < seg1 + seg3 || seg3 < seg2 + seg1) {
        if ((seg1 == seg2 && seg3 != seg1 && seg3 != seg2) || (seg1 == seg3 && seg2 != seg3 && seg3 != seg1) || (seg2 == seg3 && seg1 != seg2 && seg1 != seg3)) {
            printf("Esse triangulo eh valido e eh isosceles. \n");
        }
        else if(seg1 == seg2 && seg2 == seg3 && seg1 == seg3) {
            printf("Esse triangulo eh valido e eh equilatero. \n");
        }
        else if(seg1 != seg2 && seg2 != seg3 && seg3 != seg1) {
            printf("Esse triangulo eh valido e eh escaleno. \n");
        }
    }
    else {
        printf("Esse triangulo nao eh valido.");
    }

    return 0;
}

