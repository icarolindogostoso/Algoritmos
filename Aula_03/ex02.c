#include <stdio.h>

int main (){
	int i,maior,indiceMaior,menor,indiceMenor, x[10];

	for (i = 0 ; i < 10 ; i++){
		scanf("%d",&x[i]);
	}

    indiceMaior=0;
    maior=x[0];
    indiceMenor = 0;
    menor = x[0];

	for (i = 1 ; i < 10 ; i++){
		if(x[i]>maior){
			indiceMaior=i;
			maior=x[i];
		} if (x[i] < menor){
            indiceMenor = i;
            menor = x[i];
        }
	}

	printf("O maior elemento é %d e está no índice %d\n",maior,indiceMaior);
	printf("O menor elemento é %d e está no índice %d\n",menor,indiceMenor);

	return 0;
}