#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int s = 0 ;
    for ( int i =0; i < n-1; i++){
        for ( int j= i +1; j < n; j++){
            for ( int k=1; k < j ; k++){
                s = s + 1;
            }
        }
    }
    printf("%d", s);

    return 0;
}