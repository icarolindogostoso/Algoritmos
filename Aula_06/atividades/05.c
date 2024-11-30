#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int s = 0;
    for ( int i =1; i < n-1; i ++){
        for ( int j =1; j < 2*n; j ++){
            s = s + 1 ;
        }
    }
    printf("%d",s);
    return 0;
}
