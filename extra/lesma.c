#include <stdio.h>

int acharLevel (int lista[], int tamanho){
    int level = 0;
    for (int i = 0; i < tamanho; i++){
        if (lista[i] < 10 && level < 2){
            level = 1;
        } if ((lista[i] >= 10 || lista[i] < 20) && level < 3){
            level = 2;
        } if (lista[i] >= 20){
            level = 3;
        }
    }

    return level;
}

int main(){
    int tamanho;
    scanf("%d", &tamanho);

    int lista[tamanho];
    for (int i = 0; i < tamanho; i++){
        scanf("%d", &lista[i]);
    }

    int level = acharLevel(lista, tamanho);

    printf("Level %d", level);

    return 0;
}