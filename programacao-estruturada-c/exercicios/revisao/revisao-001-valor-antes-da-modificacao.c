#include <stdio.h>

int main() {

    int y;
    int *p;
    
    p = &y;

    
    y = 5;
    printf("Valor antes da modificacao: %d\n.", y);
    
    *p = 20;
    printf("Valor depois da modificacao: %d\n.", *p);

}

