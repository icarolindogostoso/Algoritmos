#include <stdio.h>

int main() {
    char nome[6] = "texto";
    char *p = strchr(nome, 't');
    if (p != NULL) {
        printf("O caractere 't' foi encontrado na posição %ld\n", p - nome);
    } else {
        printf("O caractere 't' não foi encontrado\n");
    }
    return 0;
}