#include <stdio.h>

int main() {
    char nome[3] = "texto";

    for (int i = 0; nome[i] != '\0'; i++) {
        printf("%c\n", nome[i]);
    }

    return 0;
}