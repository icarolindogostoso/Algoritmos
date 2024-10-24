#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Jogar os dados:");
    int rodando = 1;
    int jogardados;
    while (rodando == 1){
        printf("Voce deseja lancar os dados? (sim = 1, nao = 0)\n");
        scanf("%d", &jogardados);
        if (jogardados == 1){
            int numero1 = rand() % 6 + 1, numero2 = rand() % 6 + 1;
            printf("Valor do dado 1: %d\n", numero1);
            printf("Valor do dado 2: %d\n", numero2);
            printf("Soma dos dados: %d\n", numero1 + numero2);
        } else if (jogardados == 0){
            printf("Fechando...");
            break;
        } else{
            printf("Comando invalido");
            printf("\n");
        }
    }
    return 0;
}