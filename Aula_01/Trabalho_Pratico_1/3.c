#include <stdio.h>
long multiplicacao(int a, int b){
    long s = a*b;
    return s;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%ld\n",multiplicacao(a,b));
    return 0;
}