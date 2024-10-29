#include <stdio.h>

int main() {
    int tamanho = 5;
    int numeros[tamanho];
    
    for (int i = 1; i <= 10; i++){
        if (i > tamanho){
            tamanho++;
        }
        numeros[i-1] = i*10;
    }

    for (int i = 0; i < 15; i++) {
        printf("%d\n", &numeros[i]);
    }

    return 0;
}