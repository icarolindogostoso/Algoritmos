#include <stdio.h>

int main(){
    int numero;
    scanf("%d", &numero);

    if (numero%3 == 0 && numero%5 == 0){
        printf("é divisivel\n");
    } else {
        printf("nao é\n");
    }

    return 0;
}