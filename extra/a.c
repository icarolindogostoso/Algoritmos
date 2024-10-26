#include <stdio.h>

int main(){
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    int meuArray[5] = {a,b,c,d,e};

    int n = 5;
    int meuNovoArray[n];
    for (int i = 0; i < n; i++){
        meuNovoArray[i] = i+1;
    }

    for (int i = 0; i < n; i++){
        printf("%d ", meuNovoArray[i]);
    }
    printf("\n");

    a = meuNovoArray[0];
    b = meuNovoArray[1];
    c = meuNovoArray[2];
    d = meuNovoArray[3];
    e = meuNovoArray[4];

    int novoTamanho = 5;
    int array[novoTamanho];

    for (int i = 0; i < novoTamanho; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    int nome[5] = {1,2,3,4,5};

    for (int i = 0; i < 6; i++){
        printf("%d ", nome[i]);
    }
    printf("\n");

    char string[5];
    scanf("%s", string); // batatadoce e queijo
    printf("%s", string); // batatadoce

    return 0;
}