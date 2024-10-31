#include <stdio.h>

int main(){
    int array[15];

    for (int i = 0; i < 15; i++){
        scanf("%d", &array[i]);
    }

    int maior = array[0];
    int menor = array[0];

    for (int i = 1; i < 15; i++){
        if (array[i] > maior){
            maior = array[i];
        } if (array[i] < menor){
            menor = array[i];
        }
    }

    printf("Maior = %d, Menor = %d", maior, menor);
    
    return 0;
}