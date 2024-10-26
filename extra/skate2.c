#include <stdio.h>

int Score (int a, int b, int c){

    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        return a;
    } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
        return b;
    } else {
        return c;
    }
}

int main(){
    int valor1,valor2,valor3,valor4,valor5,valor6,valor7,valor8,valor9,valor10,valor11,valor12,valor13,valor14,valor15,valor16,valor17,valor18;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&valor1,&valor2,&valor3,&valor4,&valor5,&valor6,&valor7,&valor8,&valor9,&valor10,&valor11,&valor12,&valor13,&valor14,&valor15,&valor16,&valor17,&valor18);

    int score1 = Score(valor1, valor2, valor3);
    int score2 = Score(valor4, valor5, valor6);
    int score3 = Score(valor7, valor8, valor9);

    int score4 = Score(valor10, valor11, valor12);
    int score5 = Score(valor13, valor14, valor15);
    int score6 = Score(valor16, valor17, valor18);

    int scoreA = Score(score1, score2, score3);
    int scoreB = Score(score4, score5, score6);

    if (scoreA > scoreB){
        printf("A");
    } else if (scoreA < scoreB){
        printf("B");
    } else {
        printf("Empate");
    }

    return 0;
}