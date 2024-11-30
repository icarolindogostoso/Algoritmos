#include <stdio.h>

void inserir (int array[], int n, int valor){
    
    int i = n - 1;

    for (i ; array[i] > valor && i >= 0; i--){
        array[i + 1] = array[i];
    }

    array[i + 1] = valor;

}

int main(){
    int array[5+1] = {1,2,3,5,6};
    int valor = 0;

    inserir(array, 5, valor);

    for (int i = 0; i < 6; i++){
        printf("%d ", array[i]);
    }

    return 0;
}