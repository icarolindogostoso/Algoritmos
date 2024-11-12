// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int a = 10;
    int *ponteiro = &a;
    int valor = *ponteiro;
    
    printf("%d %d %d\n", a, *ponteiro, valor);
    
    printf("%d %d %d\n", ponteiro, *ponteiro, &ponteiro);
    
    *ponteiro = 20;
    
    printf("%d %d %d\n", *ponteiro, a, valor);
    
    ponteiro = &valor;
    
    printf("%d %d %d\n", *ponteiro, a, valor);
    
    int *ponteiro2 = ponteiro;
    
    printf("%d %d %d\n", ponteiro2, *ponteiro2, &ponteiro2);
    printf("%d %d %d\n", ponteiro, *ponteiro, &ponteiro);
    
    // ponteiro = 30;
    
    // printf("%d %d %d", *ponteiro, a, valor);
    
    int numeros[5] = {10,20,30,40,50};
    int *ponteirodoido = &numeros[0];
    
    for (int i = 0; i < 5; i++){
        printf("%d ", *(ponteirodoido + i));
    }
    
    printf("\n");
    
    for (int i = 0; i < 5; i++){
        printf("%d ", ponteirodoido + i);
    }
    
    printf("\n");

    return 0;
}