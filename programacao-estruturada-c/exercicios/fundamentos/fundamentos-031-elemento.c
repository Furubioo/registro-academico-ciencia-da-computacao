#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, j, elementos[3][3];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Elemento [%d] [%d]: ", i, j);
            scanf("%d", &elementos[i][j]);
        }
    }

    printf("Matriz digitada: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d", elementos[i][j]);
        }
        printf("\n");
    }
    printf("Matriz transposta: \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d", elementos[j][i]);
        }
        printf("\n");
    }
return 0;
}

