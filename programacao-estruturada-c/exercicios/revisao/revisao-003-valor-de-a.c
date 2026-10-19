#include <stdio.h>

int main() {

    int a = 15;
    int *p1, *p2;
    p1 = &a;
    p2 = p1;

    printf("Valor de A: %d \n", *p2);

    return 0;
}

