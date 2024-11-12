#include <stdio.h>

int main(){
    int a = 10, b = 20, c = 30;
    int *ponteiro;

    ponteiro = &b; // ponteiro vai guardar endereco de memoria de b

    *ponteiro = -5; // valor de b será alterado de 20 para -5

    ponteiro = &c; // agora ponteiro vai guardar endereco de memoria de c

    *ponteiro = 50; // valor de c será alterado de 30 para 50

    ponteiro = &a; // agora ponteiro vai guardar enredeco de memoria de a

    printf("a,b,c,*p = %d, %d, %d, %d\n", a, b, c, *ponteiro); // 10, -5, 50, 10

    return 0;
}