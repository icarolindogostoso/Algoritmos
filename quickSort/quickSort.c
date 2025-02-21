#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Função para trocar dois elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição do Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Obtém o índice do pivô
        quickSort(arr, low, pi - 1); // Ordena a parte esquerda
        quickSort(arr, pi + 1, high); // Ordena a parte direita
    }
}

#define MAX_LINE_LENGTH 1000000

// Função para ler o arquivo e armazenar os dados
void ler_arquivo(char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    int *lista = malloc(sizeof(int) * 10);  // Alocando espaço inicial para 10 inteiros
    int capacidade = 10;  // Capacidade inicial do vetor
    int tamanho = 0;      // Tamanho atual da lista
    int valor;

    // Lendo os números inteiros do arquivo
    while (fscanf(arquivo, "%d", &valor) == 1) {
        if (tamanho == capacidade) {
            capacidade *= 2;
            lista = realloc(lista, sizeof(int) * capacidade);
        }
        lista[tamanho] = valor;
        tamanho++;
    }

    fclose(arquivo);

    clock_t start = clock(); // Tempo inicial
    quickSort(lista, 0, tamanho - 1); // Chama o Quick Sort
    clock_t end = clock(); // Tempo final

    double tempoExecucao = (double)(end - start) / CLOCKS_PER_SEC; // Calcula o tempo em milissegundos

    printf("Tempo de execucao: %.6f segundos\n", tempoExecucao);

    free(lista);  // Liberando o vetor de ponteiros
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso correto: %s <arquivo.txt>\n", argv[0]);
        return 1;
    }

    ler_arquivo(argv[1]);
    return 0;
}
