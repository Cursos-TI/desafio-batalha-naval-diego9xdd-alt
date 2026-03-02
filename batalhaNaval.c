#include <stdio.h>
#include <stdlib.h> // Para a função abs()

#define TAM_TAB 10
#define TAM_HAB 5
#define NAVIO 3
#define HABILIDADE 5
#define AGUA 0

/**
 * Lógica Geométrica:
 * - Cone: Preenche colunas expandindo conforme a linha desce.
 * - Cruz: Preenche a linha central e a coluna central.
 * - Octaedro: Preenche onde a distância de Manhattan (soma das distâncias do centro) é constante.
 */

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB] = {0};

    // 1. Posicionamento de Navios (Exemplo do nível anterior)
    for (int j = 1; j <= 3; j++) tabuleiro[1][j] = NAVIO; // Horizontal
    for (int i = 4; i <= 6; i++) tabuleiro[i][8] = NAVIO; // Vertical

    // 2. Definição das Matrizes de Habilidade (5x5)
    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};
    int centro = TAM_HAB / 2;

    // --- Construção Dinâmica das Habilidades ---
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Lógica do CONE (Triângulo apontando para baixo)
            if (i >= centro && j >= centro - (i - centro) && j <= centro + (i - centro)) {
                cone[i][j] = 1;
            }
            // Lógica da CRUZ
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            }
            // Lógica do OCTAEDRO (Losango)
            // Baseado na fórmula: |i - centro| + |j - centro| <= raio
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    // 3. Sobreposição no Tabuleiro
    // Vamos definir pontos de origem (onde o centro da habilidade 5x5 ficará)
    int origemL_Cone = 2, origemC_Cone = 5;
    int origemL_Cruz = 7, origemC_Cruz = 1;
    int origemL_Octa = 6, origemC_Octa = 6;

    // Exemplo de aplicação: Octaedro
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int destL = origemL_Octa + i - centro;
            int destC = origemC_Octa + j - centro;

            // Validação de bordas: Garante que não escrevemos fora do tabuleiro [0-9]
            if (destL >= 0 && destL < TAM_TAB && destC >= 0 && destC < TAM_TAB) {
                if (octaedro[i][j] == 1) {
                    tabuleiro[destL][destC] = HABILIDADE;
                }
            }
        }
    }

    // 4. Exibição do Tabuleiro Final
    printf("--- BATALHA NAVAL: MESTRE ---\n\n");
    printf("Legenda: 0=Agua | 3=Navio | 5=Habilidade\n\n");

    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}