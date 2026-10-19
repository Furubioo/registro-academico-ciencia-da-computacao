#include <stdio.h>

int main() {

    char key, choice;
    int num, count;
    long int date;
    float yield;
    double price;

    char *pkey = &key;
    char *pchoice = &choice;
    int *pnum = &num;
    int *pcount = &count;
    long int *pdate = &date;
    float *pyield = &yield;
    double *pprice = &price;

    printf("Endereco da variavel key: %p\n", &pkey);
    printf("Endereco da variavel choice: %p\n", &pchoice);
    printf("Endereco da variavel num: %p\n", &pnum);
    printf("Endereco da variavel count: %p\n", &pcount);
    printf("Endereco da variavel : %p\n", &pdate);
    printf("Endereco da variavel : %p\n", &pyield);
    printf("Endereco da variavel : %p\n", &pprice);

    return 0;
}

