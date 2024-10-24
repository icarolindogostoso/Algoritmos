#include <stdio.h>

int main(){
    printf("Bem vindo ao conversor de moedas\n");
    printf("Convertemos as moedas: Dolares, Euros e Reais\n");
    printf("\n");
    int rodando = 1;
    double valor, conversao;
    int moedaescolhida, moedaconvertida;
    while (rodando == 1){
        printf("Digite um valor para ser convertido ou 0 para sair: ");
        scanf("%lf", &valor);
        printf("\n");
        if (valor == 0){
            printf("Fechando...\n");
            break;
        } else if (valor < 0){
            printf("Valor invalido.");
            printf("\n");
        } else{
            printf("Digite em qual moeda é esse valor (1 = Dolar, 2 = Euro, 3 = Real): ");
            scanf("%d", &moedaescolhida);
            printf("\n");
            switch (moedaescolhida){
            case 1:
                printf("Digite em qual moeda esse valor deve ser convertido (1 = Dolar, 2 = Euro, 3 = Real): ");
                scanf("%d", &moedaconvertida);
                printf("\n");
                switch (moedaconvertida){
                    case 1:
                        conversao = valor;
                        printf("Conversão = USD %.2lf para UDS %.2lf\n", valor, conversao);
                        break;
                    case 2:
                        conversao = valor * 0.85;
                        printf("Conversão = USD %.2lf para EUR %.2lf\n", valor, conversao);
                        break;
                    case 3:
                        conversao = valor * 5.2;
                        printf("Conversão = USD %.2lf para BRL %.2lf\n", valor, conversao);
                        break;
                    default:
                        printf("Moeda invalida\n");
                        printf("\n");
                }
                break;
            case 2:
                printf("Digite em qual moeda esse valor deve ser convertido (1 = Dolar, 2 = Euro, 3 = Real): ");
                scanf("%d", &moedaconvertida);
                printf("\n");
                switch (moedaconvertida){
                    case 1:
                        conversao = valor * 1.1;
                        printf("Conversão = EUR %.2lf para UDS %.2lf\n", valor, conversao);
                        break;        
                    case 2:
                        conversao = valor;
                        printf("Conversão = EUR %.2lf para EUR %.2lf\n", valor, conversao);
                        break;
                    case 3:
                        conversao = valor * 5.5;
                        printf("Conversão = EUR %.2lf para BRL %.2lf\n", valor, conversao);
                        break;
                    default:
                        printf("Moeda invalida\n");
                        printf("\n");
                }
                break;
            case 3:
                printf("Digite em qual moeda esse valor deve ser convertido (1 = Dolar, 2 = Euro, 3 = Real): ");
                scanf("%d", &moedaconvertida);
                printf("\n");
                switch (moedaconvertida){
                    case 1:
                        conversao = valor * 0.2;
                        printf("Conversão = BRL %.2lf para UDS %.2lf\n", valor, conversao);
                        break;
                    case 2:
                        conversao = valor * 0.18;
                        printf("Conversão = BRL %.2lf para EUR %.2lf\n", valor, conversao);
                        break;
                    case 3:
                        conversao = valor;
                        printf("Conversão = BRL %.2lf para BRL %.2lf\n", valor, conversao);
                        break;
                    default:
                        printf("Moeda invalida\n");
                        printf("\n");
                }
                break;
            default:
                printf("Moeda invalida\n");
                printf("\n");
            }
        }
    }
    return 0;
}