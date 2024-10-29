#include <stdio.h>
#include <string.h>

int main() {
    char nome[6] = "texto";
    char destino[6];
    strcpy(destino, nome);
    printf("A string destino é %s\n", destino);
    return 0;
}