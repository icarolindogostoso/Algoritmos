#include <stdio.h>

void dividirArray (int arrayGeral[], int arrayA[], int arrayB[]){
    for (int i = 0; i < 18; i++){
        if (i < 18/2){
            arrayA[i] = arrayGeral[i];
        } else{
            arrayB[i - 18 / 2] = arrayGeral[i];
        }
    }
}

void Scores (int arrayNovo[], int array[]){
    for (int j = 0; j < 3; j++){
        int a = array[j*3 + 0];
        int b = array[j*3 + 1];
        int c = array[j*3 + 2];

        if ((a >= b && a <= c) || (a <= b && a >= c)) {
            arrayNovo[j] = a;
        } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
            arrayNovo[j] = b;
        } else {
            arrayNovo[j] = c;
        }
    }
}

int ScoreFinal (int arrayNovo[]){
    int a = arrayNovo[0];
    int b = arrayNovo[1];
    int c = arrayNovo[2];

    if ((a >= b && a <= c) || (a <= b && a >= c)) {
        return a;
    } else if ((b >= a && b <= c) || (b <= a && b >= c)) {
        return b;
    } else {
        return c;
    }
}

int main(){
    int arrayGeral[18];
    int arrayA[9], arrayB[9];
    int arrayNovoA[3], arrayNovoB[3];

    for (int i = 0; i < 18; i++){
        scanf("%d", &arrayGeral[i]);
    }

    dividirArray(arrayGeral, arrayA, arrayB);

    Scores(arrayNovoA, arrayA);
    Scores(arrayNovoB, arrayB);

    int resultadoA = ScoreFinal(arrayNovoA);
    int resultadoB = ScoreFinal(arrayNovoB);

    if (resultadoA > resultadoB){
        printf("A");
    } else if (resultadoA < resultadoB){
        printf("B");
    } else {
        printf("Empate");
    }

    return 0;

}