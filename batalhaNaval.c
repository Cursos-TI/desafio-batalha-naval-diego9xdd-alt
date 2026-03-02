#include <stdio.h>

#define TAM 10 // Tamanho do tabuleiro 10x10

int main() {
    // Inicialização do tabuleiro preenchido com 0 (água)
    int tabuleiro[TAM][TAM] = {0};

    // --- NÍVEL NOVATO & AVENTUREIRO: Posicionamento de Navios ---
    
    // Navio Horizontal (Tamanho 3) na Linha 1
    for (int j = 1; j <= 3; j++) tabuleiro[1][j] = 3;

    // Navio Vertical (Tamanho 3) na Coluna 5
    for (int i = 6; i <= 8; i++) tabuleiro[i][5] = 3;

    // Navio Diagonal 1 (Tamanho 3) - Noroeste para Sudeste
    for (int i = 0; i < 3; i++) tabuleiro[i + 7][i + 1] = 3;

    // Navio Diagonal 2 (Tamanho 3) - Sudoeste para Nordeste
    for (int i = 0; i < 3; i++) tabuleiro[4 - i][i + 7] = 3;


    // --- NÍVEL MESTRE: Habilidades Especiais ---
    // Usaremos o valor 1 para representar a área afetada pelas habilidades

    // 1. Habilidade em Cone (Base na linha 4, coluna 2)
    // Representa um triângulo: topo (1), meio (3), base (5)
    int coneTopoLinha = 2, coneTopoColuna = 4;
    for (int i = 0; i < 3; i++) { // Altura do cone
        for (int j = -i; j <= i; j++) { // Largura expandindo a cada linha
            tabuleiro[coneTopoLinha + i][coneTopoColuna + j] = 1;
        }
    }

    // 2. Habilidade em Cruz (Centro na linha 1, coluna 8)
    int cruzLinha = 1, cruzCol = 8;
    for (int i = 0; i < 5; i++) {
        tabuleiro[cruzLinha][(cruzCol - 2) + i] = 1; // Eixo Horizontal
        if (i < 3) tabuleiro[(cruzLinha - 1) + i][cruzCol] = 1; // Eixo Vertical
    }

    // 3. Habilidade em Octaedro (Centro na linha 8, coluna 8)
    // Formato de diamante/losango
    int octLinha = 8, octCol = 8;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // A condição de um octaedro/diamante simples: soma das distâncias <= 1
            if (abs(i) + abs(j) <= 1) {
                tabuleiro[octLinha + i][octCol + j] = 1;
            }
        }
    }

    // --- EXIBIÇÃO DO TABULEIRO ---
    printf("     TABULEIRO FINAL (Navios: 3 | Habilidades: 1)\n\n");
    printf("    ");
    for(int j = 0; j < TAM; j++) printf("%d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}