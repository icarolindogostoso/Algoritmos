#include <stdio.h>

int main(){
    int numero;
    printf("Digite um numero inteiro de 3 digitos: ");
    scanf("%d",&numero);

    int numero1 = numero %10;
    int numero2 = (numero / 10) %10;
    int numero3 = (numero / 10) /10;
    int resultado = numero1*100+numero2*10+numero3;

    printf("%d",resultado);
    return 0;
}