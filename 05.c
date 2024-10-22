#include <stdio.h>

int main() {
    int numero;
    int soma_divisores = 0;
    scanf("%d", &numero);

    for (int i = 1; i <= numero / 2; i++) {
        if (numero % i == 0) {
            printf("%d\n", i);
            soma_divisores += i;
        }
    }

    if (soma_divisores == numero) {
        printf("O número é perfeito\n");
    } else {
        printf("O número não é perfeito\n");
    }

    return 0;
}