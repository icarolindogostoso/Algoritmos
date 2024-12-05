#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
};

struct Contato* criarContato(char nome[], char telefone[]){
    struct Contato* contato = (struct Contato*) malloc(sizeof(struct Contato));

    strcpy(contato->nome, nome);
    strcpy(contato->telefone, telefone);
}

int main() {
    struct Contato agenda[100];
    int totalContatos = 0;

    int op = 0;
    while (op != 5){
        printf("1 - Criar contato, 2 - Listar contatos, 3 - Atualizar contato, 4 - Excluir contato, 5 - Fim\n");
        printf("Informe sua opção: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite o nome do contato: ");
            scanf("%s", agenda[totalContatos].nome);

            printf("Digite o telefone do contato: ");
            scanf("%s", agenda[totalContatos].telefone);

            totalContatos++;
            break;

        case 2:
            for (int j = 0; j < totalContatos; j++){
                printf("%s ", agenda[j].nome);
                printf("%s\n", agenda[j].telefone);
            }
            break;
        
        case 3:
            break;

        case 4:
            break;

        default:
            printf("Opção invalida");
            break;
        }
    }

    return 0;
}