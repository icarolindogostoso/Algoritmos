#include <stdio.h>

int main(){
    int funcionamento = 1;
    double dinheiro;
    double saldo;
    int rodando = 1;
    while (rodando == 1) {
        printf("Bem vindo ao caixa eletronico\n");
        printf("Digite 1 para Sacar, 2 para Depositar, 3 para Verificar Saldo, 0 para sair\n");
        printf("Operacao: ");
        scanf("%d", &funcionamento);
        printf("\n");

        if (funcionamento == 0){
            printf("Fechando...\n");
            break;
        }

        else if (funcionamento == 1){
            printf("Digite quanto dinheiro voce quer sacar: R$ ");
            scanf("%lf", &dinheiro);
            printf("\n");
            if (dinheiro > saldo) {
                printf("Saldo insuficiente!!!!\n");
                printf("\n");
            } 
            else if (dinheiro < 0){
                printf("Nao foi possivel realizar saque.\n");
                printf("\n");
            }
            else {
                saldo = saldo - dinheiro;
                printf("Saque realizado com sucesso!!\n");
                printf("\n");
            }
        }

        else if (funcionamento == 2) {
            printf("Digite quanto dinheiro voce quer depositar: R$ ");
            scanf("%lf", &dinheiro);
            printf("\n");
            if (dinheiro < 0){
                printf("Nao foi possivel realizar deposito.\n");
                printf("\n");
            } else{
                saldo = saldo + dinheiro;
                printf("Deposito realizado com sucesso!\n");
                printf("\n");
            }
        }

        else if (funcionamento == 3){
            printf("Seu saldo é R$ %.2lf\n", saldo);
            printf("\n");
        }

        else{
            printf("Operacao desconhecida, tente novamente\n");
            printf("\n");
        }
    }
    return 0;
}