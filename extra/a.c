#include <stdio.h>

int main() {
    int matriz [5][5] ={
        {0,-1,0,0,0},
        {0,0,0,0,-1},
        {0,0,-1,0,0},
        {0,0,0,0,0},
        {0,-1,0,0,-1}
    };
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (matriz[i][j] == 0){
                int contador = 0;

                for (int m = i-1; m <= i+1; m++){
                    for (int n = j-1; n <= j+1; n++){
                        if ((m < 0 || m > 4) || (n < 0 || n > 4)){
                            continue;
                        }
                        if (matriz[m][n] == -1){
                            contador++;
                        }
                    }
                }
                matriz[i][j] = contador;
            }
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%02d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}