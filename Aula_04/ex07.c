#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10
#define MINAS 10

// Função para inicializar o tabuleiro com as minas
void inicializarTabuleiro(char tabuleiro[LINHAS][COLUNAS], int minas[LINHAS][COLUNAS]) {
    // Preencher com espaços vazios
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = ' ';
            minas[i][j] = 0;
        }
    }

    // Colocar as minas aleatoriamente
    int minasColocadas = 0;
    while (minasColocadas < MINAS) {
        int x = rand() % LINHAS;
        int y = rand() % COLUNAS;
        
        if (minas[x][y] == 0) { // Verifica se já não tem mina nesse local
            minas[x][y] = 1;
            minasColocadas++;
        }
    }

    // Atualizar os números nas células adjacentes às minas
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (minas[i][j] == 1) { // Se for mina, não faz nada
                continue;
            }
            int contador = 0;
            // Verificar todas as células adjacentes
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (i + dx >= 0 && i + dx < LINHAS && j + dy >= 0 && j + dy < COLUNAS) {
                        if (minas[i + dx][j + dy] == 1) {
                            contador++;
                        }
                    }
                }
            }
            minas[i][j] = contador; // Número de minas adjacentes
        }
    }
}

// Função para mostrar o tabuleiro
void mostrarTabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("[%c] ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para revelar a célula
int revelarCelula(int x, int y, char tabuleiro[LINHAS][COLUNAS], int minas[LINHAS][COLUNAS]) {
    if (minas[x][y] == 1) { // Se for mina
        tabuleiro[x][y] = '*';
        return 0; // Jogo perdido
    }

    tabuleiro[x][y] = minas[x][y] + '0'; // Revela o número de minas ao redor
    return 1; // Jogo continua
}

// Função para verificar se o jogador venceu
int verificarVitoria(char tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (tabuleiro[i][j] == ' ' || tabuleiro[i][j] == '.') {
                return 0; // Ainda há células não reveladas
            }
        }
    }
    return 1; // Vitória!
}

int main() {
    char tabuleiro[LINHAS][COLUNAS];
    int minas[LINHAS][COLUNAS];
    int x, y;
    int jogoAtivo = 1;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    inicializarTabuleiro(tabuleiro, minas);

    while (jogoAtivo) {
        mostrarTabuleiro(tabuleiro);
        printf("\nDigite a linha e a coluna para revelar (ex: 3 4): ");
        scanf("%d %d", &x, &y);
        
        // Verifica se as coordenadas são válidas
        if (x < 0 || x >= LINHAS || y < 0 || y >= COLUNAS) {
            printf("Coordenadas inválidas. Tente novamente.\n");
            continue;
        }

        // Revela a célula
        jogoAtivo = revelarCelula(x, y, tabuleiro, minas);
        
        // Verifica se o jogador perdeu
        if (!jogoAtivo) {
            printf("Você perdeu! Uma mina foi detonada.\n");
            break;
        }

        // Verifica se o jogador venceu
        if (verificarVitoria(tabuleiro)) {
            printf("Parabéns, você venceu!\n");
            break;
        }
    }

    return 0;
}
