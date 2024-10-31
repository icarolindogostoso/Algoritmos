#include <stdio.h>

int main(){
    int array[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", &array[i]);
    }

    int soma = 0;
    for (int i = 0; i < 10; i++){
        soma = soma + array[i];
    }

    printf("%d", soma);

    return 0;
}