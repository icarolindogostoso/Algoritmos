#include <stdio.h>

void swap (int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int a = 10, b = 20;
    int *pa = &a, *pb = &b;
    printf("%d %d\n", *pa, *pb);
    swap(pa, pb);
    printf("%d %d\n", *pa, *pb);

    return 0;
}