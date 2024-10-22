#include <stdio.h>

int main(){
    int numero_1, numero_2;
    scanf("%d %d", &numero_1, &numero_2);

    while (numero_2 != 0){
        int valor = numero_1 % numero_2;
        numero_1 = numero_2;
        numero_2 = valor;
    }

    printf("%d", numero_1);

    return 0;
}