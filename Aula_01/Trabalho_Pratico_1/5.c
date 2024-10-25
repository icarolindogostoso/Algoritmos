#include <stdio.h>
#include <math.h>

int main(){
    int x1, y1;
    printf("Escreva os eixos do ponto A: ");
    scanf("%d %d", &x1, &y1);

    int x2,y2;
    printf("Escreva os eidos do ponto B: ");
    scanf("%d %d", &x2, &y2);

    int operacao1 = x2-x1;
    int operacao2 = y2-y1;

    double distancia = sqrt(operacao1*operacao1 + operacao2*operacao2);
    printf("Distancia: %lf",distancia);
    return 0;
}