#include <stdio.h>

int main(){
    double numero1, numero2, numero3, numero4;
    scanf("%lf %lf %lf %lf",&numero1,&numero2,&numero3,&numero4);
    
    double soma = numero1 + numero2 + numero3 + numero4;
    double media = soma/4;

    printf("%lf",media);
    return 0;
}