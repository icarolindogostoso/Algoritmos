#include <stdio.h>

int main(){
    int n=0, m=0;
    float A=0, B=0, C=0, D=0, E=0, h=0;

    scanf("%d %d",&n,&m);
    h=(n*m);

    char planeta [n][m];
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            scanf(" %c", &planeta[i][j]);

            if(planeta[i][j]=='*'){
                A++;
            }

            else if(planeta[i][j]=='~'){
                B++;
            }

            else if(planeta[i][j]=='X'){
                C++;
            }

            else if(planeta[i][j]=='^'){
                D++;
            }

            else if(planeta[i][j]=='.'){
                E++;
            }
        }

    }

    if(C>1){
        printf("Planeta hostil");
    }

    else if((A/h<=0.2) && B/h<=0.5){
        printf("Planeta habitavel");
    }
    
    else if(B/h>=0.85){
        printf("Planeta aquatico");
    }

    else if(D>=0.6){
        printf("Planeta desertico");
    }

    else if(A/h>=0.65){
        printf("Planeta selvagem");
    }

    else{
    printf("Planeta inospito");
    }
}