#include <stdio.h>


int div (int a, int b){
    if (b > a){
        return 0;
    }
    return 1 + div (a-b, b);
}

int mod (int a, int b){
    if (b > a){
        return a;
    }
    return mod(a-b, b);
}

int main(){
    int divisation = div (7, 8);
    int resto = mod (7, 8);
    printf("%d %d\n", divisation, resto);
    return 0;
}