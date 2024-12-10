#include <stdio.h>
#include <string.h>

struct Pessoa{
    char nome[50];
    int idade;
    char atendimento;
    int preferencia;
};

struct Fila{
    struct Pessoa pessoa[50];
    struct Pessoa* proxima;
};

void inserirpreferencial (struct Fila** preferencial){
    *preferencial = 
}

int main(){
    struct Fila* prefencial;
    struct Fila* geral;

    int op = 0;
    while (op != 10){
        printf("1 - Inserir pessoa na fila preferencial, 2 - Listar pessoas\n");
        printf("Informe sua opcao: ");
        scanf("%d", &op);

        if (op == 1){
            inserirpreferencial(&prefencial);
        } else if (op == 2){
            listar(geral, preferencial, &ultimoGeral, &ultimoPreferencial);
        }
    }
    return 0;
}