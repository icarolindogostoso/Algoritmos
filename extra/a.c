#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        if (i % 11 == 0 || i % 13 == 0 || i % 17 == 0){
            printf("%d ", i);
        }
    }
    return 0;
}