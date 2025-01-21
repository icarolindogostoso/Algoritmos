#include <stdio.h>

void imprimir_menu(){
    printf("1. Inserir paciente na fila\n");
    printf("2. Remover paciente na fila\n");
    printf("3. Imprimir fila de pacientes\n");
    printf("4. Sair\n");
}

void inserir_paciente_menu(){
    int opcao;
    printf("Medicos disponiveis:\n");
    printf("1. Isabella\n2. Icaro\n3. Flavio\n4. Gustavo\n5. Emanuelly\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &opcao);
}

int main(){
    int opcao;
    while (1){
        imprimir_menu();
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            inserir_paciente_menu();
            break;

        case 4:
            return 0;
        
        default:
            printf("Opcao invalida\n");
        }
    }
}