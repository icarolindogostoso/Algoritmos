#include <stdio.h>

int main(){
    int isabella = 27, icaro = 15, flavio = 7;
    int votosisa = 0, votosicaro = 0, votosflavio = 0;
    printf("Estamos em epoca de eleicao!\n");
    printf("Os candidatos da vez são:\n");
    printf("primeiro - Isabella - numero 27\n");
    printf("primeiro - Icaro - numero 15\n");
    printf("primeiro - Flavio - numero 7\n");
    
    int repeticao = 1;
    while (repeticao == 1){
        int candidato;
        printf("Digite o numero do seu candidato ou 0 para fechar: ");
        scanf("%d", &candidato);

         if (candidato == 27){
            printf("Voto realizado com sucesso!!\n");
            printf("\n");
            votosisa ++;
        } else if (candidato == 15){
            printf("Voto realizado com sucesso!!\n");
            printf("\n");
            votosicaro ++;
        } else if (candidato == 7){
            printf("Voto realizado com sucesso!!\n");
            printf("\n");
            votosflavio ++;
        } else if (candidato == 0){
            break;
        } else {
            printf("Candidato inexistente\n");
            printf("\n");
        }
    }

    printf("Quantidade de votos para cada canditado: \n");
    printf("Isabella = %d votos\n", votosisa);
    printf("Icaro = %d votos\n", votosicaro);
    printf("Flavio = %d votos\n", votosflavio);

    return 0;
}