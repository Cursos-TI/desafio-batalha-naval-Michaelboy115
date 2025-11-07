#include <stdio.h>
#include <ctype.h> // Função toupper()

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.



// Definição do tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// --- FUNÇÃO AUXILIAR: Converte coordenada (e.g., 'C', 4) para índices (2, 3) ---
// Retorna 1 se a coordenada for válida para o navio e 0 caso contrário.
int posicionar_navio(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     char coord_coluna, int coord_linha, char orientacao) {
    
    // Converte a letra da coluna para maiúscula e depois para índice (A=0, B=1, ...)
    int j_inicial = toupper(coord_coluna) - 'A'; 
    // Converte o número da linha para índice (1=0, 2=1, ...)
    int i_inicial = coord_linha - 1; 
    
    int i, j;
    
    // Verifica se a posição inicial está dentro dos limites do tabuleiro.
    if (i_inicial < 0 || i_inicial >= TAMANHO_TABULEIRO || 
        j_inicial < 0 || j_inicial >= TAMANHO_TABULEIRO) {
        printf("ERRO: Coordenada inicial inválida.\n");
        return 0;
    }

    if (orientacao == 'H') { // Navio Horizontal 
        // O navio de 3 casas ocupará: [i_inicial][j_inicial] até [i_inicial][j_inicial + 2]
        if (j_inicial + 2 >= TAMANHO_TABULEIRO) {
            printf("ERRO: Navio horizontal extrapola o limite.\n");
            return 0;
        }
        // Posiciona o navio: C4, D4, E4 -> i=3, j=2, 3, 4
        for (j = j_inicial; j < j_inicial + 3; j++) {
            tabuleiro[i_inicial][j] = '3';
        }
        
    } else if (orientacao == 'V') { // Navio Vertical 
        // O navio de 3 casas ocupará: [i_inicial][j_inicial] até [i_inicial + 2][j_inicial]
        if (i_inicial + 2 >= TAMANHO_TABULEIRO) {
            printf("ERRO: Navio vertical extrapola o limite.\n");
            return 0;
        }
        // Posiciona o navio: C4, C5, C6 -> i=3, 4, 5, j=2
        for (i = i_inicial; i < i_inicial + 3; i++) {
            tabuleiro[i][j_inicial] = '3';
        }
        
    }
    return 1;
}

int main() {
    
    // Inicializando o tabuleiro com um caractere que representa 'Água' ou 'Vazio' como 0.
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // 2. Variáveis para a exibição das coordenadas (1-10, A-J) e entrada
    char linha_labels[] = "ABCDEFGHIJ"; // Usada apenas para exibição
    int i, j;
    
    // Variáveis para a entrada do navio
    char entrada_coluna;
    int entrada_linha;
    char enter_dummy;
    
    // Inicializa todas as casas como 'vazias'
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '0'; // '0' representa a água (vazio)
        }
    }
    
   
    // ENTRADA E POSICIONAMENTO DE NAVIOS
    
    printf("--- Posicionamento de Navios ---\n");
    
    
    // NAVIO 1: HORIZONTAL (Exemplo: C4 -> C4, D4, E4)
    
    printf("Navio Horizontal (3 casas).\n");
    printf("Digite a coordenada inicial (Coluna Linha, ex: C4): ");
    
    if (scanf(" %c%d", &entrada_coluna, &entrada_linha) != 2) {
        printf("ERRO: Formato de entrada inválido.\n");
        return 1;
    }
    
    // Limpa o buffer após scanf
    if (scanf("%c", &enter_dummy) != 1) {} 

    posicionar_navio(tabuleiro, entrada_coluna, entrada_linha, 'H');

    // ----------------------------------------------------
    // NAVIO 2: VERTICAL (Exemplo: B5 -> B5, B6, B7)
    // ----------------------------------------------------
    printf("\nNavio Vertical (3 casas). Ex: B5\n");
    printf("Digite a coordenada inicial (Coluna Linha, ex: B5): ");
    
    // Lê a letra e o número
    if (scanf(" %c%d", &entrada_coluna, &entrada_linha) != 2) {
        printf("ERRO: Formato de entrada inválido.\n");
        return 1;
    }
    
    posicionar_navio(tabuleiro, entrada_coluna, entrada_linha, 'V');
    
    // =========================================================
    
    
    // ---Exibição do Tabuleiro ---

    // Títulos das Colunas (A a J)
    printf("\n   A B C D E F G H I J\n"); 

    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i + 1); // Título da Linha (1 a 10)
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %c", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}