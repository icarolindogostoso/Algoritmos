#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int numero = rand() % 100 + 1, contador = 1, chute;
    printf("Eu escolhi um numero de 0 ate 100!!!!\n");
    printf("O seu objetivo vai ser saber qual foi o numero que eu escolhi!!\n");
    printf("Boa sorte!\n");

    while (numero != chute){
        printf("Teste numero %d: ", contador);
        scanf("%d", &chute);

        if (chute>numero){
            printf("O numero que escolhi e menor que esse\n");
        } if (chute<numero){
            printf("O numero que escolhi e maior que esse\n");
        }
        contador++;
    }
    printf("Droga! Voce me derrotou!!");
    return 0;
}