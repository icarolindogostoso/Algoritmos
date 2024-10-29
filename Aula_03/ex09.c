#include <stdio.h>
#include <string.h>

int main() {
    char nome[6] = "texto";
    char sobrenome[6] = "abcde";
    strcat(nome, sobrenome);
    printf("A string nome é %s\n", nome);
    return 0;
}