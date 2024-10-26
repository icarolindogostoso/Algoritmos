#include <stdio.h>

int SomaDivisores (int valor1) {
    int soma = 0;

    for (int i = 1; i <= valor1/2; i++){
        if (valor1 % i == 0){
            soma = soma + i;
        }
    }

    return soma;
}

int Conferir (int soma1, int soma2, int valor1, int valor2){
    int resultado1 = soma2 - valor1, resultado2 = soma1 - valor2;

    if (resultado1 < 0){
        resultado1 = -resultado1;
    } if (resultado2 < 0){
        resultado2 = -resultado2;
    }

    int saida = 0;

    if (resultado1 <= 2 && resultado2 <= 2){
        saida = 1;
    }

    return saida;

}

int main(){
    int valor1, valor2;

    scanf("%d %d", &valor1, &valor2);

    int soma1 = SomaDivisores(valor1);
    int soma2 = SomaDivisores(valor2);

    if (Conferir(soma1, soma2, valor1, valor2) == 1){
        printf("S");
    } else {
        printf("N");
    }

    return 0;
}