#include <stdio.h>

int buscaIndice (int a[], int n, int x){
    int esquerda = 0; // 1 atribuicao
    int direita = n - 1; // 1 operacao, 1 atribuicao

    while (esquerda <= direita){ // 1 comparacao * log(n)
        int meio = (esquerda + direita) / 2; // (1 operacao, 1 operacao, 1 atribuicao) * log(n)

        if (a[meio] == x){ // (1 acesso a array, 1 comparacao) * log(n)
            return meio; // 1 retorno * log(n)
        } else if (a[meio] < x){ // (1 acesso a array, 1 comparacao) * log(n)
            esquerda = meio + 1; // (1 operacao, 1 atribuicao) * log(n)
        } else {
            direita = meio - 1; // (1 operacao, 1 atribuicao) * log(n)
        }
    }

    return -1; // 1 retorno

    // total = 4 + 14 log n
}