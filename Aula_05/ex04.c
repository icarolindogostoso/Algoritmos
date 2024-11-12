#include <stdio.h>

int main(){
    int i = 3, j = 5;
    int *p, *q;

    p = &i;
    q = &j;

    if (p == &i){ // verdadeiro pois p guarda o endereco de memoria de i
        printf("true\n");
    } else {
        printf("false\n");
    }

    if (p == *p){ // false por p guardar um endereco de memoria, nao um valor
        printf("true\n");
    } else {
        printf("false\n");
    }

    if (q == j){ // falso por q guardar um endereco de memoria, nao um valor
        printf("true\n");
    } else {
        printf("false\n");
    }

    if (*q == &j){ // falso pelo valor que o p aponta nao ser um endereco de memoria
        printf("true\n");
    } else {
        printf("false\n");
    }

    if (*q == j){ // verdadeiro pelo valor que q aponta é justamente o de j
        printf("true\n");
    } else {
        printf("false\n");
    }

    printf("%d", *p - *q); // 3 - 5 = -2

    return 0;
}