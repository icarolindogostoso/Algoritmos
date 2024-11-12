#include <stdio.h>

int main(){
    int a = 20, b = 20;
    int *pa, *pb; // declara pa e pb como ponteiros

    pa = &a; // pa está apontando para o endereco de memoria de a
    pb = &b; // pb está apontando para o endereco de memoria de b

    *pa = *pb * 2; // o valor que pa está apontando (a) vai virar o valor que o pb está apontando (b) * 2

    printf("%d, %d\n", a, b); // 40, 20

    return 0;
}