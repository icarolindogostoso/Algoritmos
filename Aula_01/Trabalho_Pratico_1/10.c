#include <stdio.h>

int main(){
    int racao, gato1, gato2;
    scanf("%d %d %d", &racao, &gato1, &gato2);
    
    int custo = gato1*5 + gato2*5;
    int resto = racao*1000 - custo;

    printf("Resto da racao apos cinco dias: %d gramas", resto);
    return 0;
}