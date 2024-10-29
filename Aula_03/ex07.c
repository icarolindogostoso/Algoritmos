#include <stdio.h>
#include <string.h>

int main() {
    char nome[6] = "texto";
    int tamanho = strlen(nome);
    printf("O tamanho da string é %d\n", tamanho);
    return 0;
}