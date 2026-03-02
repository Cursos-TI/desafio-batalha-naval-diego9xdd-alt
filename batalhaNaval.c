#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define CELULA_NAVIO 3
#define CELULA_AGUA 0

int main() {
    // 1. Inicialização do Tabuleiro 10x10 com 0 (Água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // --- POSICIONAMENTO DOS NAVIOS ---

    // Navio 1: Horizontal (Linha 1, Colunas 1, 2, 3)
    for (int j = 1; j <= TAMANHO_NAVIO; j++) {
        tabuleiro[1][j] = CELULA_NAVIO;
    }

    // Navio 2: Vertical (Coluna 7, Linhas 4, 5, 6)
    for (int i = 4; i < 4 + TAMANHO_NAVIO; i++) {
        tabuleiro[i][7] = CELULA_NAVIO;
    }

    // Navio 3: Diagonal Principal (Crescente: Linha e Coluna aumentam)
    // Coordenada inicial: (2, 5) -> Ocupará (2, 5), (3, 6), (4, 7)
    // Nota: Como o Navio 2 usa (4, 7), vamos ajustar para (2, 4) para evitar sobreposição.
    int d1L = 2, d1C = 4;
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        tabuleiro[d1L + k][d1C + k] = CELULA_NAVIO;
    }

    // Navio 4: Diagonal Secundária (Decrescente: Linha aumenta, Coluna diminui)
    // Coordenada inicial: (7, 2) -> Ocupará (7, 2), (8, 1), (9, 0)
    int d2L = 7, d2C = 2;
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        tabuleiro[d2L + k][d2C - k] = CELULA_NAVIO;
    }

    // --- EXIBIÇÃO DO TABULEIRO ---
    printf("--- BATALHA NAVAL: NÍVEL AVENTUREIRO ---\n\n");

    // Cabeçalho das colunas
    printf("    ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) printf("%d ", j);
    printf("\n");

    // Linhas do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i); // Índice da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}