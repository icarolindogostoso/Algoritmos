#include <stdio.h>
#include <string.h>

struct Pessoa{
    char nome[50];
    int idade;
    char atendimento[50];
    char preferencial[50];
};

struct Fila{
    struct Pessoa pessoas[50];
    struct Pessoa* proxima;
};

void inserirpreferencial(struct Fila* fila){
    printf("Informe o nome da pessoa: ");
    scanf("%s", fila->proxima->nome);

    printf("Informe a idade da pessoa: ");
    scanf("%d", &fila->proxima->idade);

    printf("Informe o atendimento da pessoa (cirgurgia, ortopedia): ");
    scanf("%s", fila->proxima->atendimento);

    printf("Informe o preferencial da pessoa (idoso, gestante, lactante, PCD): ");
    scanf("%s", fila->proxima->preferencial);

    fila->proxima++;
}

void inserirgeral(struct Fila* fila){
    printf("Informe o nome da pessoa: ");
    scanf("%s", fila->proxima->nome);

    printf("Informe a idade da pessoa: ");
    scanf("%d", &fila->proxima->idade);

    printf("Informe o atendimento da pessoa (cirgurgia, ortopedia): ");
    scanf("%s", fila->proxima->atendimento);

    strcpy(fila->proxima->preferencial, "Geral");

    fila->proxima++;
}

void listarpreferencial(struct Fila* fila){
    int i = 0;
    for (i; i < fila->proxima - fila->pessoas; i++){
        printf("Nome: %s\n", fila->pessoas[i].nome);
        printf("Idade: %d\n", fila->pessoas[i].idade);
        printf("Atendimento: %s\n", fila->pessoas[i].atendimento);
        printf("Preferencial: %s\n", fila->pessoas[i].preferencial);
        printf("\n");
        i++;
    }
}

void listargeral(struct Fila* fila){
    int i = 0;
    for (i; i < fila->proxima - fila->pessoas; i++){
        printf("Nome: %s\n", fila->pessoas[i].nome);
        printf("Idade: %d\n", fila->pessoas[i].idade);
        printf("Atendimento: %s\n", fila->pessoas[i].atendimento);
        printf("Preferencial: %s\n", fila->pessoas[i].preferencial);
        printf("\n");
        i++;
    }
}

void removerpreferencial(struct Fila* fila, char* nome){
    int i = 0;
    while (strcmp(fila->pessoas[i].nome, nome) != 0){
        i++;
    }
    for (int j = i; j < 50; j++){
        fila->pessoas[j] = fila->pessoas[j+1];
    }
    fila->proxima--;
}

void removergeral(struct Fila* fila, char* nome){
    int i = 0;
    while (strcmp(fila->pessoas[i].nome, nome) != 0){
        i++;
    }
    for (int j = i; j < 50; j++){
        fila->pessoas[j] = fila->pessoas[j+1];
    }
    fila->proxima--;
}

void atender(struct Fila* preferencial, struct Fila* geral, int* prefencialatendido){
    if (preferencial->proxima == preferencial->pessoas || *prefencialatendido == 1){
        printf("Proximo a ser atendido: \n");
        printf("Nome: %s\n", geral->pessoas[0].nome);
        printf("Idade: %d\n", geral->pessoas[0].idade);
        printf("Atendimento: %s\n", geral->pessoas[0].atendimento);
        printf("Preferencial: %s\n", geral->pessoas[0].preferencial);
        printf("\n");
        removergeral(geral, geral->pessoas[0].nome);
        *prefencialatendido = 0;
    } else {
        *prefencialatendido = 1;
    }
}

int main(){
    struct Fila prefencial;
    prefencial.proxima = prefencial.pessoas;

    struct Fila geral;
    geral.proxima = geral.pessoas;

    int op = 0;
    while (op != 7){
        printf("1 - Inserir pessoa na fila preferencial, 2 - Inserir pessoa na fila geral, 3 - Remover pessoa da fila preferencial, 4 - Remover pessoa da fila geral, 5 - Ateder uma pessoa da fila, 6 - Listar pessoas, 7 - Sair\n");
        printf("Informe sua opcao: ");
        scanf("%d", &op);

        if (op == 1){
            inserirpreferencial(&prefencial);
        } else if (op == 2){
            inserirgeral(&geral);
        } else if (op == 3){
            listarpreferencial(&prefencial);
            printf("Informe o nome da pessoa a ser removida: ");
            char nome[50];
            scanf("%s", nome);
            removerpreferencial(&prefencial, nome);
        } else if (op == 4){
            listargeral(&geral);
            printf("Informe o nome da pessoa a ser removida: ");
            char nome[50];
            scanf("%s", nome);
            removergeral(&geral, nome);
        } else if (op == 5){
            int preferencialatendido = 0;
            atender(&prefencial, &geral, &preferencialatendido);
        } else if (op == 6){
            printf("Pessoas na fila preferencial: \n");
            listarpreferencial(&prefencial);

            printf("Pessoas na fila geral: \n");
            listargeral(&geral);
        }
    }
    return 0;
}