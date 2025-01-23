#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paciente {
    char nome[50];
    int preferencial;
    struct Paciente* proximo;
};

struct Medico {
    char nome[50];
    int atendimentos;
    int sequencia;
    struct Paciente* pacientes;
    struct Medico* proximo;
};

struct Medico* lista_medicos = NULL;

void adicionar_paciente_na_fila(struct Medico* medico, char* nome, int preferencial){
    struct Paciente* novo_paciente = malloc(sizeof(struct Paciente));
    strcpy(novo_paciente->nome, nome);
    novo_paciente->preferencial = preferencial;
    novo_paciente->proximo = NULL;

    if (medico->pacientes == NULL){
        medico->pacientes = novo_paciente;
    } else {
        struct Paciente* atual = medico->pacientes;
        while (atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo_paciente;
    }
}

void remover_paciente_na_fila(struct Medico* medico, char* nome){
    struct Paciente* atual = medico->pacientes;
    struct Paciente* anterior = NULL;
    while (atual != NULL){
        if (strcmp(atual->nome, nome) == 0){
            if (anterior == NULL){
                medico->pacientes = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void exibir_pacientes_na_fila(struct Medico* medico){
    printf("Pacientes na fila para o medico %s:\n", medico->nome);

    struct Paciente* paciente = medico->pacientes;
    if (paciente == NULL){
        printf("Nenhum paciente na fila\n");
        printf("\n");
        return;
    }
    int contador = 1;
    while (paciente != NULL){
        printf("%d. %s (Preferencial: %d)\n", contador, paciente->nome, paciente->preferencial);
        paciente = paciente->proximo;
        contador++;
    }
    printf("\n");
}

void exibir_fila_geral(){
    struct Medico* atual = lista_medicos;

    printf("Fila geral:\n");
    while (atual != NULL){
        struct Paciente* paciente = atual->pacientes;
        if (paciente == NULL){
            printf("\nNenhum paciente na fila para o medico %s\n", atual->nome);
        } else {
            printf("\nMedico %s:\n", atual->nome);
            int contador = 1;
            while (paciente != NULL){
                printf("%d. %s (Preferencial: %d)\n", contador, paciente->nome, paciente->preferencial);
                paciente = paciente->proximo;
                contador++;
            }
        }
        atual = atual->proximo;
    }
    printf("\n");
}

void adicionar_medico(char* nome){
    struct Medico* novo_medico = malloc(sizeof(struct Medico));
    strcpy(novo_medico->nome, nome);
    novo_medico->atendimentos = 0;
    novo_medico->sequencia = 0;
    novo_medico->pacientes = NULL;
    novo_medico->proximo = lista_medicos;
    lista_medicos = novo_medico;
}

void remover_medico(char* nome){
    struct Medico* atual = lista_medicos;
    struct Medico* anterior = NULL;
    while (atual != NULL){
        if (strcmp(atual->nome, nome) == 0){
            if (anterior == NULL){
                lista_medicos = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Medico removido com sucesso\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Medico nao encontrado\n");
}

void exibir_medicos(){
    printf("\nMedicos cadastrados:\n");
    struct Medico* atual = lista_medicos;
    if (atual == NULL){
        printf("Nenhum medico cadastrado\n");
        return;
    }
    int contador = 1;
    while (atual != NULL){
        printf("%d. %s - Atendimentos: %d\n", contador, atual->nome, atual->atendimentos);
        atual = atual->proximo;
        contador++;
    }
    printf("\n");
}

void atender_paciente(struct Medico* medico){
    if (medico->atendimentos >= 15){
        printf("O medico %s ja atendeu 15 pacientes\n", medico->nome);
        return;
    }

    if (medico->pacientes == NULL){
        printf("Nenhum paciente na fila para o medico %s\n", medico->nome);
        return;
    }

    struct Paciente* paciente = medico->pacientes;
    struct Paciente* anterior = NULL;

    if (medico->atendimentos == 0 || medico->atendimentos == 1){
        while (paciente != NULL && paciente->preferencial != 1){
            anterior = paciente;
            paciente = paciente->proximo;
        }

        if (paciente != NULL){
            printf("Atendendo paciente preferencial %s\n", paciente->nome);
            
            if (anterior == NULL){
                medico->pacientes = paciente->proximo;
            } else {
                anterior->proximo = paciente->proximo;
            }
            free(paciente);
            medico->sequencia++;

            if (medico->sequencia > 2){
                medico->sequencia = 0;
            }

        } else {
            paciente = medico->pacientes;
            printf("Atendendo paciente normal: %s\n", paciente->nome);
            medico->pacientes = paciente->proximo;
            free(paciente);

            medico->sequencia = 0;
        }

        medico->atendimentos++;
    } else {
        if (medico->sequencia == 2){
            while (paciente != NULL && paciente->preferencial != 0){
                anterior = paciente;
                paciente = paciente->proximo;
            }

            if (paciente != NULL){
                printf("Atendendo paciente normal %s\n", paciente->nome);
                
                if (anterior == NULL){
                    medico->pacientes = paciente->proximo;
                } else {
                    anterior->proximo = paciente->proximo;
                }
                free(paciente);
                medico->sequencia = 0;
            } else {
                paciente = medico->pacientes;
                printf("Atendendo paciente preferencial: %s\n", paciente->nome);
                medico->pacientes = paciente->proximo;
                free(paciente);
                medico->sequencia++;
                if(medico->sequencia > 2){
                    medico->sequencia = 0;
                }
            }

            medico->atendimentos++;
        } else {
            while (paciente != NULL && paciente->preferencial != 1){
                anterior = paciente;
                paciente = paciente->proximo;
            }

            if (paciente != NULL){
                printf("Atendendo paciente preferencial %s\n", paciente->nome);
                
                if (anterior == NULL){
                    medico->pacientes = paciente->proximo;
                } else {
                    anterior->proximo = paciente->proximo;
                }
                free(paciente);
                medico->sequencia++;
                if(medico->sequencia > 2){
                    medico->sequencia = 0;
                }
            } else {
                paciente = medico->pacientes;
                printf("Atendendo paciente normal: %s\n", paciente->nome);
                medico->pacientes = paciente->proximo;
                free(paciente);
                medico->sequencia = 0;
            }

            medico->atendimentos++;
        }
    }
}


int imprimir_menu(){
    int opcao;
    printf("1. Inserir paciente na fila\n");
    printf("2. Remover paciente na fila\n");
    printf("3. Imprimir fila de pacientes de um medico\n");
    printf("4. Imprimir fila de pacientes\n");
    printf("5. Inserir novo medico\n");
    printf("6. Remover medico\n");
    printf("7. Imprimir medicos\n");
    printf("8. Atender paciente\n");
    printf("9. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

void inserir_medico_menu(){
    char nome[50];
    printf("\nDigite o nome do novo medico: ");
    scanf("%s", nome);
    adicionar_medico(nome);
    printf("Medico adicionado com sucesso\n");
    printf("\n");
}

void remover_medico_menu(){
    char nome[50];
    printf("\nDigite o nome do medico: ");
    scanf("%s", nome);
    remover_medico(nome);
    printf("\n");
}

void imprimir_medicos(){
    exibir_medicos();
}

void inserir_paciente_menu(){
    char nome[50];
    int preferencial, opcao;
    
    exibir_medicos();

    printf("Escolha o medico: ");
    scanf("%d", &opcao);

    struct Medico* selecionado = lista_medicos;
    int contador = 1;

    while (selecionado != NULL && contador < opcao){
        selecionado = selecionado->proximo;
        contador++;
    }

    if (selecionado != NULL){
        printf("\nDigite o nome do paciente: ");
        scanf("%s", nome);
        printf("\nDigite 1 para paciente preferencial ou 0 para nao preferencial: ");
        scanf("%d", &preferencial);
        adicionar_paciente_na_fila(selecionado, nome, preferencial);
    }
}

void remover_paciente_menu(){
    char nome[50];
    int opcao;

    exibir_medicos();

    printf("Escolha o medico: ");
    scanf("%d", &opcao);
    
    struct Medico* selecionado = lista_medicos;
    int contador = 1;

    while (selecionado != NULL && contador < opcao){
        selecionado = selecionado->proximo;
        contador++;
    }

    if (selecionado != NULL){
        printf("\nDigite o nome do paciente: ");
        scanf("%s", nome);
        remover_paciente_na_fila(selecionado, nome);
    }
    printf("\n");
}

void imprimir_fila_medico(){
    int opcao;
    struct Medico* selecionado;

    exibir_medicos();

    printf("Digite o numero do medico: ");
    scanf("%d", &opcao);

    selecionado = lista_medicos;
    int contador = 1;

    while (selecionado != NULL && contador < opcao){
        selecionado = selecionado->proximo;
        contador++;
    }

    if (selecionado != NULL){
        exibir_pacientes_na_fila(selecionado);
    }
}

void imprimir_fila(){
    exibir_fila_geral();
}

void atender_paciente_menu(){
    int opcao;
    struct Medico* selecionado;

    exibir_medicos();

    printf("Digite o numero do medico: ");
    scanf("%d", &opcao);

    selecionado = lista_medicos;
    int contador = 1;
    while (selecionado != NULL && contador < opcao){
        selecionado = selecionado->proximo;
        contador++;
    }

    if (selecionado != NULL){
        atender_paciente(selecionado);
    }
    printf("\n");
}

int main(){
    adicionar_medico("Isabella");
    adicionar_medico("Icaro");
    adicionar_medico("Flavio");
    adicionar_medico("Gustavo");
    adicionar_medico("Emanuelly");

    while (1){
        int opcao = imprimir_menu();
        switch (opcao)
        {
        case 1:
            inserir_paciente_menu();
            break;
        
        case 2:
            remover_paciente_menu();
            break;
        
        case 3:
            imprimir_fila_medico();
            break;

        case 4:
            imprimir_fila();
            break;
        
        case 5:
            inserir_medico_menu();
            break;
    
        case 6:
            remover_medico_menu();
            break;
        
        case 7:
            imprimir_medicos();
            break;
        
        case 8:
            atender_paciente_menu();
            break;

        case 9:
            return 0;
        
        default:
            printf("Opcao invalida\n");
        }
    }
    return 0;
}