#include <stdio.h>
#include <string.h>

struct Pessoa{
    int id;
    char nome[50];
    int idade;
    char atendimento[50];
    char preferencial[50];
};

struct Fila{
    struct Pessoa pessoas[50];
    struct Pessoa* proxima;
};

void inserirpreferencial(struct Fila* fila, int* qtdpreferencial){
    int id = 0;
    for (int i = 0; i < *qtdpreferencial; i++){
        if (fila->pessoas[i].id > id){
            id = fila->pessoas[i].id;
        }
    }

    char nome[50];
    printf("Informe o nome da pessoa: ");
    scanf("%s", nome);

    int idade;
    printf("Informe a idade da pessoa: ");
    scanf("%d", &idade);

    char atendimento[50];
    printf("Informe o atendimento da pessoa (cirgurgia, ortopedia): ");
    scanf("%s", atendimento);

    char preferencial[50];
    printf("Informe o preferencial da pessoa (idoso, gestante, lactante, PCD): ");
    scanf("%s", preferencial);

    if (strcmp(preferencial, "idoso") == 0 || strcmp(preferencial, "gestante") == 0 || strcmp(preferencial, "lactante") == 0 || strcmp(preferencial, "PCD") == 0){
        fila->proxima->id = id + 1;
        strcpy(fila->proxima->nome, nome);
        fila->proxima->idade = idade;
        strcpy(fila->proxima->atendimento, atendimento);
        strcpy(fila->proxima->preferencial, preferencial);

        fila->proxima++;
        *qtdpreferencial = *qtdpreferencial + 1;
    } else {
        printf("Preferencialidade invalida!\n");
    }
}

void inserirgeral(struct Fila* fila, int* qtdgeral){
    int id = 0;
    for (int i = 0; i < *qtdgeral; i++){
        if (fila->pessoas[i].id > id){
            id = fila->pessoas[i].id;
        }
    }

    fila->proxima->id = id + 1;

    printf("Informe o nome da pessoa: ");
    scanf("%s", fila->proxima->nome);

    printf("Informe a idade da pessoa: ");
    scanf("%d", &fila->proxima->idade);

    printf("Informe o atendimento da pessoa (cirgurgia, ortopedia): ");
    scanf("%s", fila->proxima->atendimento);

    strcpy(fila->proxima->preferencial, "Geral");

    fila->proxima++;
    *qtdgeral = *qtdgeral + 1;
}

void listar(struct Fila* fila, int* qtd){
    for (int i = 0; i < *qtd; i++){
        printf("Id: %d\n", fila->pessoas[i].id);
        printf("Nome: %s\n", fila->pessoas[i].nome);
        printf("Idade: %d\n", fila->pessoas[i].idade);
        printf("Atendimento: %s\n", fila->pessoas[i].atendimento);
        printf("Preferencial: %s\n", fila->pessoas[i].preferencial);
        printf("\n");
    }
}

void remover(struct Fila* fila, int id, int* qtd){
    int i = 0;
    while (fila->pessoas[i].id != id){
        i++;
    }
    for (int j = i; j < *qtd; j++){
        fila->pessoas[j] = fila->pessoas[j+1];
    }
    fila->proxima--;
    *qtd = *qtd - 1;
}

void proximoASerAtendido(struct Fila* fila, int* qtd, int posicao){
    printf("Proximo a ser atendido: \n");
    printf("Id: %d\n", fila->pessoas[posicao].id);
    printf("Nome: %s\n", fila->pessoas[posicao].nome);
    printf("Idade: %d\n", fila->pessoas[posicao].idade);
    printf("Atendimento: %s\n", fila->pessoas[posicao].atendimento);
    printf("Preferencial: %s\n", fila->pessoas[posicao].preferencial);
    printf("\n");
    remover(fila, fila->pessoas[posicao].id, qtd);
}

void atender(struct Fila* preferencial, struct Fila* geral, int* prefencialatendido, int* qtdpreferencial, int* qtdgeral){
    if (preferencial->proxima == preferencial->pessoas && geral->proxima == geral->pessoas){
        printf("Nenhuma pessoa na fila!\n");
    } else if (preferencial->proxima == preferencial->pessoas || *prefencialatendido == 1){
        proximoASerAtendido(geral, qtdgeral, 0);
        *prefencialatendido = 0;
    } else {
        int idoso = 0;
        int gestanteOuLactante = 0;
        for (int i = 0; i < *qtdpreferencial; i++){
            if (strcmp(preferencial->pessoas[i].preferencial, "idoso") == 0){
                proximoASerAtendido(preferencial, qtdpreferencial, i);
                idoso = 1;
                break;
            }
        }

        if (idoso == 0){
            for (int i = 0; i < *qtdpreferencial; i++){
                if (strcmp(preferencial->pessoas[i].preferencial, "gestante") == 0 || strcmp(preferencial->pessoas[i].preferencial, "lactante") == 0){
                    proximoASerAtendido(preferencial, qtdpreferencial, i);
                    gestanteOuLactante = 1;
                    break;
                }
            }
            if (gestanteOuLactante == 0){
                for (int i = 0; i < *qtdpreferencial; i++){
                    if (strcmp(preferencial->pessoas[i].preferencial, "PCD") == 0){
                        proximoASerAtendido(preferencial, qtdpreferencial, i);
                        break;
                    }
                }
            }
        }
        *prefencialatendido = 1;
    }
}


int main(){
    struct Fila prefencial;
    int qtdpreferencial = 0;
    prefencial.proxima = prefencial.pessoas;

    struct Fila geral;
    int qtdgeral = 0;
    geral.proxima = geral.pessoas;

    int preferencialatendido = 0;

    int op = 0;
    while (op != 7){
        printf("1 - Inserir pessoa na fila preferencial, 2 - Inserir pessoa na fila geral, 3 - Remover pessoa da fila preferencial, 4 - Remover pessoa da fila geral, 5 - Ateder uma pessoa da fila, 6 - Listar pessoas, 7 - Sair\n");
        printf("Informe sua opcao: ");
        scanf("%d", &op);

        if (op == 1){
            inserirpreferencial(&prefencial, &qtdpreferencial);
        } else if (op == 2){
            inserirgeral(&geral, &qtdgeral);
        } else if (op == 3){
            listar(&prefencial, &qtdpreferencial);
            printf("Informe o id da pessoa a ser removida: ");
            int id;
            scanf("%d", &id);
            remover(&prefencial, id, &qtdpreferencial);
        } else if (op == 4){
            listar(&geral, &qtdgeral);
            printf("Informe o id da pessoa a ser removida: ");
            int id;
            scanf("%d", &id);
            remover(&geral, id, &qtdgeral);
        } else if (op == 5){
            atender(&prefencial, &geral, &preferencialatendido, &qtdpreferencial, &qtdgeral);
        } else if (op == 6){
            printf("Pessoas na fila preferencial: \n");
            listar(&prefencial, &qtdpreferencial);

            printf("Pessoas na fila geral: \n");
            listar(&geral, &qtdgeral);
        }
    }
    return 0;
}