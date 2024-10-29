#include <stdio.h>

int main() {
    char nome[6] = "texto";
    char *p = strstr(nome, "ex");
    if (p != NULL) {
        printf("A substring 'ex' foi encontrada na posição %ld\n", p - nome);
    } else {
        printf("A substring 'ex' não foi encontrada\n");
    }
    return 0;
}