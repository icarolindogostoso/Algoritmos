#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printError(char *mensagem){
    printf("%s\n", mensagem);
}

FILE* abrirArquivo(char *arquivoNome, char *modo){
    FILE *arquivo = fopen(arquivoNome, modo);
    if (arquivo == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    return arquivo;
}

int* arquivoEntrada(char *arquivoNome, int *n){
    FILE *arquivo = abrirArquivo(arquivoNome, "r");

    int i = 0;
    int *arr = (int*)malloc((*n) * sizeof(int));
    if (arr == NULL){
        printf("Erro alocar memoria");
        fclose(arquivo);
        exit(1);
    }

    while(fscanf(arquivo, "%d", &arr[i]) != EOF){
        i++;
    }

    fclose(arquivo);
    return arr;
}

double medicaoTempo(int *arr, int n){
    clock_t inicio, fim;
    inicio = clock();
    insertionSort(arr, n);
    fim = clock();

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void processarDuracaoArquivo(FILE *arquivoDuracao, int *entradas, int numEntradas){
    for (int i = 0; i < numEntradas; i++){
        int n = entradas[i];
        char nomeArquivo[50];
        sprintf(nomeArquivo, "entradas/%d-entradas.txt", n);

        int *arr = arquivoEntrada(nomeArquivo, &n);

        double tempo = medicaoTempo(arr, n);

        fprintf(arquivoDuracao, "Tempo de execucao: %.6f segundos para %d entradas\n", tempo, n);
        free(arr);

        printf("Tempo de execucao para %d entradas: %.6f segundos\n", n, tempo);
    }
}

void processarArquivosDuracao(int *entradas, int numEntradas){
    for (int j = 0; j < 4; j++) {
        char nomeArquivoDuracao[50];
        sprintf(nomeArquivoDuracao, "%d-duracao.txt", j + 1);

        FILE *duracaoFile = abrirArquivo(nomeArquivoDuracao, "a");

        processarDuracaoArquivo(duracaoFile, entradas, numEntradas);

        fclose(duracaoFile);
    }
}

int main() {

    int entradas[] = {100, 1000, 10000, 100000, 1000000};
    int numEntradas = sizeof(entradas) / sizeof(entradas[0]);

    processarArquivosDuracao(entradas, numEntradas);

    return 0;
}
