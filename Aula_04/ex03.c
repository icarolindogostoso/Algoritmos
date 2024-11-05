
#include <stdio.h>

int main() {
    char nomes[3][10] = {
        "Maria",
        "João",
        "Ana"
    };

    for (int i = 0; i < 3; i++) {
        printf("%s\n", nomes[i]);
    }

    return 0;
}