#include <stdio.h>

int main(){
    double salario, percentual;
    printf("Escreva o salario de um funcionario: ");
    scanf("%lf",&salario);
    printf("Escreva um percentual de aumento: ");
    scanf("%lf",&percentual);

    double aumento = salario * (1 + 1*percentual/100);
    
    printf("Aumento: %lf", aumento);
    return 0;
}