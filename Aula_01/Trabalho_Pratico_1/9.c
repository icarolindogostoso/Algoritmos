#include <stdio.h>

int main(){
    double salario, vendas;
    printf("Salario fixo do funcionario: R$ ");
    scanf("%lf",&salario);
    printf("Valor das vendas: R$ ");
    scanf("%lf",&vendas);

    double comissao = vendas * 4 / 100;
    double salario_final = salario + comissao;

    printf("Valor da comissao: R$ %.2lf\n",comissao);
    printf("Valor do salario final: R$ %.2lf\n",salario_final);

    return 0;
}