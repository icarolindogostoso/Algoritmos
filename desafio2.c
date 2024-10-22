#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    int menor = a;
    if (b < menor){
        menor = b;
    }

    int i = 2;
    int mdc;
    while (i < menor){
        if (a%i == 0 && b%i == 0){
            mdc = mdc * i;
            a = a / i;
            b = b / i;
        } else {
            i++;
        }
    }

    printf("%d", mdc);

    return 0;

}