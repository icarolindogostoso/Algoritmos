#include <stdio.h>
#include <stdlib.h>

struct Node {
    int valor;
    struct Node* proximo;
};

struct Node* inicio = NULL;

void inserir(int valor){
    struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
    novo->valor = valor;
    novo->proximo = inicio;
    inicio = novo;
}

void remover (){
    struct Node* temp = inicio;
    inicio = inicio->proximo;
    free(temp);
}

int busca (int valor){
    struct Node* temp = inicio;
    while (temp != NULL){
        if (temp->valor == valor){
            return 1;
        }
        temp = temp->proximo;
    }
}

void imprime (){
    struct Node* temp = inicio;
    while (temp != NULL){
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");
}

int tamanho (){
    int tam = 0;
    struct Node* temp = inicio;
    while (temp != NULL){
        tam++;
        temp = temp->proximo;
    }
    return tam;
}

int vazia (){
    return inicio == NULL;
}

int main (){
    inserir(10);
    inserir(20);
    inserir(30);
    inserir(40);
    inserir(50);

    imprime();

    printf("Tamanho: %d\n", tamanho());

    remover();
    remover();

    imprime();
    printf("Tamanho: %d\n", tamanho());

    printf("Busca: %d\n", busca(20));
    printf("Busca: %d\n", busca(50));

    return 0;
}