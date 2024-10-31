#include <stdio.h>

int main(){
    double array[5];
    
    for (int i = 0; i < 5; i++){
        scanf("%lf", &array[i]);
    }

    double soma = 0;
    for (int i = 0; i < 5; i++){
        soma = soma + array[i];
    }

    printf("%.2lf", soma / 5);

    return 0;
}