#include <stdio.h>

int funcao (int array[], int tamanho){
    for (int i = 1; i <= 10; i++){
        if (i > tamanho){
            tamanho++;
        }
        array[i-1] = i*10;
    }
    return tamanho;
}

int main(){
    int tamanho = 5;
    int array[tamanho];

    tamanho = funcao(array, tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}