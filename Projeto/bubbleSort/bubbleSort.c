#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int trocou;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() {

    int entradas[] = {100, 1000, 10000, 100000};

    for (int j = 0; j < 4; j++) {

        char nome_arquivo_duracao[50];
        sprintf(nome_arquivo_duracao, "%d-duracao.txt", j+1);

        FILE *duracao_file = fopen(nome_arquivo_duracao, "a");
        if (duracao_file == NULL) {
            printf("Erro ao abrir o arquivo de duração!\n");
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int n = entradas[i];
            char nome_arquivo[50];

            sprintf(nome_arquivo, "%d-entradas.txt", n);

            FILE *file = fopen(nome_arquivo, "r");
            if (file == NULL) {
                printf("Erro ao abrir o arquivo %s!\n", nome_arquivo);
                fclose(duracao_file);
                return 1;
            }

            int *arr = (int*)malloc(n * sizeof(int));
            if (arr == NULL) {
                printf("Erro ao alocar memória!\n");
                fclose(file);
                fclose(duracao_file);
                return 1;
            }

            int k = 0;
            while (fscanf(file, "%d", &arr[k]) != EOF) {
                k++;
            }

            fclose(file);

            clock_t start, end;
            start = clock();
            bubbleSort(arr, n);
            end = clock();

            double tempo = (double)(end - start) / CLOCKS_PER_SEC;

            fprintf(duracao_file, "Tempo de execucao: %.6f segundos para %d entradas\n", tempo, n);

            free(arr);

            printf("Tempo de execucao para %d entradas: %.6f segundos\n", n, tempo);
    
            // char nome_arquivo_saida[50];
            // sprintf(nome_arquivo_saida, "ordenado_%d.txt", n);
            // FILE *saida = fopen(nome_arquivo_saida, "w");
            // if (saida == NULL) {
            //     printf("Erro ao abrir o arquivo para escrita!\n");
            //     fclose(duracao_file);
            //     return 1;
            // }

            // for (int j = 0; j < n; j++) {
            //     fprintf(saida, "%d ", arr[j]);
            // }

            // fclose(saida);
            // printf("Os valores ordenados para %d entradas foram salvos em '%s'.\n", n, nome_arquivo_saida);
        }

        fclose(duracao_file);
    }

    // FILE *file = fopen("100000-entradas.txt", "r");
    // if (file == NULL) {
    //     printf("Erro ao abrir o arquivo!\n");
    //     return 1;
    // }

    // int *arr = (int*)malloc(1000000 * sizeof(int));
    // if (arr == NULL) {
    //     printf("Erro ao alocar memória!\n");
    //     fclose(file);
    //     return 1;
    // }

    // int n = 0;

    // while (fscanf(file, "%d", &arr[n]) != EOF) {
    //     n++;
    // }

    // fclose(file);

    // clock_t start, end;

    // start = clock();
    // bubbleSort(arr, n);
    // end = clock();

    // double tempo = (double)(end - start) / CLOCKS_PER_SEC;

    // // Salva o tempo de execução em um arquivo
    // const char *nome_arquivo_duracao = "duracao.txt";
    // FILE *duracao_file = fopen(nome_arquivo_duracao, "a");
    // if (duracao_file == NULL) {
    //     printf("Erro ao abrir o arquivo de duração!\n");
    //     return 1;
    // }

    // fprintf(duracao_file, "Tempo de execução: %.6f segundos\n", tempo);

    // fclose(duracao_file);
    // printf("O tempo de execução foi salvo em '%s'.\n", nome_arquivo_duracao);

    // // Salva os valores ordenados em um arquivo    
    // const char *nome_arquivo = "ordenado.txt";
    // FILE *saida = fopen(nome_arquivo, "w");
    // if (saida == NULL) {
    //     printf("Erro ao abrir o arquivo para escrita!\n");
    //     return 1;
    // }

    // for (int i = 0; i < n; i++) {
    //     fprintf(saida, "%d ", arr[i]);
    // }

    // fclose(saida);
    // printf("Os valores ordenados foram salvos em '%s'.\n", nome_arquivo);

    return 0;
}
