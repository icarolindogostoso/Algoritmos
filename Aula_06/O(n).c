#include <stdio.h>

int soma (int a[], int n){
    int soma = 0; // 1 atribuicao

    for (int i = 0; i < n; i++){ // 1 atribuicao, (1 comparacao, 1 operacao, 1 atribuicao) * n
        soma = soma + a[i]; // (1 acesso a array, 1 operacao, 1 atribuicao) * n
    }
    return soma; // 1 retorno de valor
    // total = 3 + 6n
}