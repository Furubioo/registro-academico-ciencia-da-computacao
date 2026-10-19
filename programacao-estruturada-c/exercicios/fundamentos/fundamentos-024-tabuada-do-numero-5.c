#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("***Tabuada do numero 5 \n\n");
    int i, a = 5, r;
    for (i = 1; i <=10; i++) {
        r = a * i;
        printf("%d x %d = %d \n", a, i, r);
        printf("\n");
    }
return 0;
}

