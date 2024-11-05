
#include <stdio.h>

int contar_strings(char nomes[][50], int tamanho) {
    int contador = 0;

    for (int i = 0; i < tamanho; i++) {
        if (nomes[i][0] != '\0') {
            contador++;
        }
    }

    return contador;
}

int main() {
    char nomes[3][50] = {
        "Maria",
        "João",
        "Ana"
    };
    int valor1 = sizeof(nomes);
    int valor2 = sizeof(nomes[0]);
    int tamanho = valor1 / valor2;
    printf("%d %d %d\n", tamanho, valor1, valor2);
    int resultado = contar_strings(nomes, tamanho);
    printf("Quantidade de strings: %d\n", resultado);

    return 0;
}