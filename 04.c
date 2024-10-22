#include <stdio.h>

int main(){
    int numero;
    int primo = 1;
    scant("%d", &numero);

    for (int i = 1; i < numero/2; i++){
        if (numero%i == 0){
            primo = 0;
            break;
        }
    }

    if (primo == 1){
        printf("eh primo\n");
    } else {
        printf ("nao eh primo\n");
    }

    return 0;
}