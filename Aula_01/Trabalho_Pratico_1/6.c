#include <stdio.h>

int main(){
    double nota1, nota2;
    scanf("%lf %lf", &nota1, &nota2);
    double media = (nota1 * 6 + nota2 * 4)/10;
    printf("%.1lf",media);
    return 0;
}