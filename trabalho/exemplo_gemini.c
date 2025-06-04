#include <stdio.h>   // Para printf, scanf
#include <stdlib.h>  // Para system (limpar tela)

// --- Constantes para o tabuleiro e jogadores ---
#define TAMANHO_TABULEIRO 3
#define VAZIO ' '
#define JOGADOR_X 'X'
#define JOGADOR_O 'O'

// --- Variáveis Globais (para simplificar, mas podem ser passadas como parâmetro) ---
char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
char jogadorAtual; // 'X' ou 'O'

// --- Protótipos das Funções ---
void inicializarTabuleiro();
void desenharTabuleiro();
int obterJogada(int *linha, int *coluna);
int validarJogada(int linha, int coluna);
void realizarMovimento(int linha, int coluna);
int verificarVitoria();
int verificarEmpate();
void alternarJogador();

// --- Função Principal (main) ---
int main() {
    int jogoAtivo = 1; // 1 = jogo rolando, 0 = jogo acabou
    int linha, coluna;

    inicializarTabuleiro();
    jogadorAtual = JOGADOR_X; // X sempre começa

    while (jogoAtivo) {
        system("clear || cls"); // Limpa a tela (Linux/macOS e Windows)
        desenharTabuleiro();

        printf("\nJogador %c, eh a sua vez.\n", jogadorAtual);

        // Loop para garantir uma jogada válida
        while (1) {
            if (obterJogada(&linha, &coluna) == 0) { // Se a leitura falhou ou é inválida
                 printf("Entrada invalida. Digite apenas numeros para linha e coluna (1-3).\n");
                 // Limpa o buffer de entrada para evitar loops infinitos com entradas inválidas
                 while (getchar() != '\n'); 
                 continue; 
            }
            if (validarJogada(linha, coluna)) {
                break; // Sai do loop se a jogada for válida
            } else {
                printf("Jogada invalida! Tente novamente.\n");
            }
        }

        realizarMovimento(linha, coluna);

        if (verificarVitoria()) {
            system("clear || cls");
            desenharTabuleiro();
            printf("\n--- FIM DE JOGO ---\n");
            printf("O Jogador %c VENCEU!\n", jogadorAtual);
            jogoAtivo = 0;
        } else if (verificarEmpate()) {
            system("clear || cls");
            desenharTabuleiro();
            printf("\n--- FIM DE JOGO ---\n");
            printf("EMPATE! O tabuleiro esta cheio.\n");
            jogoAtivo = 0;
        } else {
            alternarJogador();
        }
    }

    return 0;
}

// --- Implementação das Funções ---

// Inicializa o tabuleiro com espaços vazios
void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

// Desenha o tabuleiro no console
void desenharTabuleiro() {
    printf("   1   2   3\n"); // Numeros das colunas
    printf("  -----------\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | %c | %c | %c |\n", i + 1, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < TAMANHO_TABULEIRO - 1) {
            printf("  -----------\n");
        }
    }
    printf("  -----------\n");
}

// Pede ao jogador as coordenadas da jogada
// Retorna 1 se a leitura foi bem sucedida, 0 caso contrário
int obterJogada(int *linha, int *coluna) {
    printf("Digite a linha (1-3) e a coluna (1-3) separadas por espaco: ");
    // Verifica se scanf conseguiu ler dois inteiros
    if (scanf("%d %d", linha, coluna) != 2) {
        return 0; // Leitura falhou
    }
    // Ajusta para índices de array (0-2)
    (*linha)--; 
    (*coluna)--; 
    return 1; // Leitura bem sucedida
}

// Valida se a jogada é possível (dentro dos limites e célula vazia)
int validarJogada(int linha, int coluna) {
    if (linha < 0 || linha >= TAMANHO_TABULEIRO ||
        coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return 0; // Fora dos limites
    }
    if (tabuleiro[linha][coluna] != VAZIO) {
        return 0; // Célula já ocupada
    }
    return 1; // Jogada válida
}

// Coloca a peça do jogador na posição escolhida
void realizarMovimento(int linha, int coluna) {
    tabuleiro[linha][coluna] = jogadorAtual;
}

// Verifica se o jogador atual venceu
int verificarVitoria() {
    // Verificar linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (tabuleiro[i][0] == jogadorAtual &&
            tabuleiro[i][1] == jogadorAtual &&
            tabuleiro[i][2] == jogadorAtual) {
            return 1;
        }
    }

    // Verificar colunas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        if (tabuleiro[0][j] == jogadorAtual &&
            tabuleiro[1][j] == jogadorAtual &&
            tabuleiro[2][j] == jogadorAtual) {
            return 1;
        }
    }

    // Verificar diagonais
    // Diagonal principal
    if (tabuleiro[0][0] == jogadorAtual &&
        tabuleiro[1][1] == jogadorAtual &&
        tabuleiro[2][2] == jogadorAtual) {
        return 1;
    }
    // Diagonal secundária
    if (tabuleiro[0][2] == jogadorAtual &&
        tabuleiro[1][1] == jogadorAtual &&
        tabuleiro[2][0] == jogadorAtual) {
        return 1;
    }

    return 0; // Nenhuma vitória
}

// Verifica se o jogo está em empate (tabuleiro cheio sem vencedor)
int verificarEmpate() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == VAZIO) {
                return 0; // Ainda há espaços vazios, não é empate
            }
        }
    }
    return 1; // Tabuleiro cheio, é empate
}

// Alterna o jogador atual
void alternarJogador() {
    jogadorAtual = (jogadorAtual == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;
}