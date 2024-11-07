#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int matriz [5][5] ={
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    for (int i = 0; i < 11; i++){
        int x = rand() %5;
        int y = rand() %5;
        matriz[x][y] = -1;
    }

    int aux [5][5] = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    while (1==1){

        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                printf("%d ", aux[i][j]);
            }
            printf("\n");
        }

        int i, j;
        printf("Informe o valor das posicoes [i,j]: ");
        scanf("%d %d", &i, &j);

        int qtd = 0;
        if (matriz[i][j] == 0){
            for (int m = i-1; m <= i+1; m++){
                for (int n = j-1; n <= j+1; n++){
                    if ((m < 0 || m > 4) || (n < 0 || n > 4)){
                        continue;
                    }
                    if (matriz[m][n] == -1){
                        qtd++;
                    }
                }
            }
            aux[i][j] = qtd;
        }
        if (matriz[i][j] == -1){
            printf("Voce perdeu!!!\n");
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 5; j++){
                    printf("%d ", matriz[i][j]);
                }
                printf("\n");
            }
            break;
        }

        
    }

    return 0;
}