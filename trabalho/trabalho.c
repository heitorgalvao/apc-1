#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho_tabuleiro 3
#define jogador_X 'X'
#define jogador_O 'O'
#define espaco ' '
#define YEL "\e[0;33m" // Amarelo
#define GRN "\e[0;32m" // Verde
#define BLU "\e[0;34m" // Azul
#define RED "\e[0;31m" // Vermelho
#define MAG "\e[0;35m" // Magenta
#define reset "\e[0m"  // Reset de cor
#define CYN "\e[0;36m" // Ciano
#define BLK "\e[0;30m" // Preto

// Estrutura para armazenar o placar do jogo
typedef struct {
    int vitoria_X;
    int vitoria_O;
    int empates;
} placar_jogo;

int main() {
    char tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];
    char jogador_atual;
    placar_jogo placar; // Variável da estrutura placar_jogo
    
    int linha, coluna;
    int escolha_menu;
    int jogo_rolando;

    // O placar sempre iniciar com zeros
    placar.vitoria_X = 0;
    placar.vitoria_O = 0;
    placar.empates = 0;

    // Loop do menu principal
    while (1) {
        system("clear"); // Limpa a tela 
        printf(CYN);
        printf("--- JOGO DA VELHA ---\n");
        printf("1. Novo Jogo\n");
        printf("2. Ver Placar\n");
        printf("3. Sobre o Jogo\n");
        printf("4. Sair\n");
        printf("---------------------\n");
        printf("Escolha uma opcao: ");
        printf(reset);

        // Validação da entrada do menu
        while (scanf("%d", &escolha_menu) != 1 || escolha_menu < 1 || escolha_menu > 4) {
            printf("Opcao invalida. Digite um numero entre 1 e 4: ");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }
        while (getchar() != '\n'); // Limpa o restante do buffer de entrada

        switch (escolha_menu) {
            case 1: { // Novo Jogo
                jogo_rolando = 1;
                // Inicia o tabuleiro
                for (int i = 0; i < tamanho_tabuleiro; i++) {
                    for (int j = 0; j < tamanho_tabuleiro; j++) {
                        tabuleiro[i][j] = espaco; // Define os espaços como vazios
                    }
                }
                jogador_atual = jogador_X; // Começa com o jogador X

                // Loop principal
                while (jogo_rolando) {
                    system("clear");

                    // Desenha o tabuleiro
                    printf("    1   2   3\n");
                    printf(" -----------\n");
                    for (int i = 0; i < tamanho_tabuleiro; i++) {
                        printf("%d | %c | %c | %c |\n", i + 1, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
                        if (i < tamanho_tabuleiro - 1) {
                            printf(" -----------\n");
                        }
                    }
                    printf(" -----------\n");

                    printf("\nJogador %c, e seu turno.\n", jogador_atual);

                    // Entrada da jogada do jogador e validação
                    while (1) {
                        printf("Digite a linha (1-3) e a coluna (1-3) separadas por espaco: ");
                        if (scanf("%d %d", &linha, &coluna) != 2) { // Tenta ler 2 inteiros
                            printf(CYN);
                            printf("Entrada invalida. Digite apenas numeros para linha e coluna (1-3).\n");
                            printf(reset);
                            while (getchar() != '\n');
                            continue; // Volta para pedir a entrada novamente
                        }
                        while (getchar() != '\n'); 

                        linha--; // Ajusta para índice 0 (0, 1, 2)
                        coluna--; // Ajusta para índice 0 (0, 1, 2)

                        // Valida a jogada (se está dentro dos limites e se o espaço está vazio)
                        if (linha < 0 || linha >= tamanho_tabuleiro || coluna < 0 || coluna >= tamanho_tabuleiro || tabuleiro[linha][coluna] != espaco) {
                            printf("Jogada invalida, tente novamente.\n");
                        } else {
                            break; // Jogada válida, sai do loop 
                        }
                    }

                    // Realiza o movimento
                    tabuleiro[linha][coluna] = jogador_atual;

                    // Verifica se houve vitória
                    int venceu = 0;
                    // Verifica as linhas
                    for (int i = 0; i < tamanho_tabuleiro; i++) {
                        if (tabuleiro[i][0] == jogador_atual && tabuleiro[i][1] == jogador_atual && tabuleiro[i][2] == jogador_atual) {
                            venceu = 1;
                            break;
                        }
                    }
                    // Verifica as colunas
                    if (!venceu) {
                        for (int j = 0; j < tamanho_tabuleiro; j++) {
                            if (tabuleiro[0][j] == jogador_atual && tabuleiro[1][j] == jogador_atual && tabuleiro[2][j] == jogador_atual) {
                                venceu = 1;
                                break;
                            }
                        }
                    }
                    // Verifica as diagonais
                    if (!venceu) {
                        if ((tabuleiro[0][0] == jogador_atual && tabuleiro[1][1] == jogador_atual && tabuleiro[2][2] == jogador_atual) ||
                            (tabuleiro[0][2] == jogador_atual && tabuleiro[1][1] == jogador_atual && tabuleiro[2][0] == jogador_atual)) {
                            venceu = 1;
                        }
                    }

                    if (venceu) {
                        system("clear");
                        // Desenha o tabuleiro novamente para mostrar a jogada vitoriosa
                        printf("    1   2   3\n");
                        printf(" -----------\n");
                        for (int i = 0; i < tamanho_tabuleiro; i++) {
                            printf("%d | %c | %c | %c |\n", i + 1, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
                            if (i < tamanho_tabuleiro - 1) {
                                printf(" -----------\n");
                            }
                        }
                        printf(" -----------\n");

                        printf(MAG "\n--- FIM DE JOGO ---\n");
                        printf("O Jogador %c VENCEU!\n" reset, jogador_atual);
                        if (jogador_atual == jogador_X) {
                            placar.vitoria_X++;
                        } else {
                            placar.vitoria_O++;
                        }
                        jogo_rolando = 0; // Termina o jogo
                    } else {
                        // Verifica se houve empate (tabuleiro cheio)
                        int is_empate = 1;
                        for (int i = 0; i < tamanho_tabuleiro; i++) {
                            for (int j = 0; j < tamanho_tabuleiro; j++) {
                                if (tabuleiro[i][j] == espaco) {
                                    is_empate = 0; // Ainda há espaços vazios
                                    break;
                                }
                            }
                            if (!is_empate) break;
                        }

                        if (is_empate) {
                            system("clear");
                            // Desenha o tabuleiro novamente para o estado final
                            printf("    1   2   3\n");
                            printf(" -----------\n");
                            for (int i = 0; i < tamanho_tabuleiro; i++) {
                                printf("%d | %c | %c | %c |\n", i + 1, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
                                if (i < tamanho_tabuleiro - 1) {
                                    printf(" -----------\n");
                                }
                            }
                            printf(" -----------\n");

                            printf(RED "\n--- FIM DE JOGO ---\n");
                            printf("EMPATE! O tabuleiro esta cheio.\n" reset);
                            placar.empates++;
                            jogo_rolando = 0; // Termina o jogo
                        } else {
                            // Alterna o jogador
                            jogador_atual = (jogador_atual == jogador_X) ? jogador_O : jogador_X;
                        }
                    }
                }
                printf(GRN);
                printf("\nPressione ENTER para voltar ao menu principal...");
                printf(reset);
                while (getchar() != '\n');
                break;
            }
            case 2: { // Ver Placar
                system("clear");
                printf(BLU "--- PLACAR GERAL (Sessão Atual) ---\n"); // Clarificando que é da sessão atual
                printf("Vitorias Jogador X: %d\n", placar.vitoria_X);
                printf("Vitorias Jogador O: %d\n", placar.vitoria_O);
                printf("Empates:            %d\n", placar.empates);
                printf("---------------------\n" reset);
                printf("\nPressione ENTER para voltar ao menu...");
                while (getchar() != '\n');
                break;
            }
            case 3: { // Sobre o Jogo
                system("clear");
                printf(BLK);
                printf("--- SOBRE O JOGO DA VELHA ---\n");
                printf("Desenvolvido pelo aluno Heitor.\n");
                printf("Versao: 1.0\n");
                printf("Quase enlouqueci fazendo, mas agora esta lindo e funcional!\n");
                printf("Regras basicas do Jogo da Velha:\n");
                printf("- Dois jogadores, 'X' e 'O', se revezam marcando espacos no tabuleiro 3x3.\n");
                printf("- O objetivo e conseguir tres de suas marcas em uma linha, coluna ou diagonal.\n");
                printf("- Se todas as casas forem preenchidas e ninguem vencer, o jogo termina em empate.\n");
                printf("\nPressione ENTER para voltar ao menu...");
                printf(reset);
                while (getchar() != '\n'); // Espera o usuário pressionar Enter
                break;
            }
            case 4: { // Sair
                printf(YEL);
                printf("Saindo do Jogo da Velha. Ate mais!\n");
                printf(reset);
                return 0; // Encerra o programa
            }
            default: {// caso o usuario venha de gracinha e não leia as instruções direito e fique inserindo
                //o que não deve.
                printf("Opcao invalida. Tente novamente.\n");
                break;
            }
        }
    }

    return 0;
}