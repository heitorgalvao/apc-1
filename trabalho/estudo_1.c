//começamos inserindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
//bem melhor do que eu colocar #define linhas e depois #define colunas 
#define tamanho_tabuleiro 3
#define jogador_X 'X'
#define jogador_O 'O'
#define espaco ' '
#define YEL "\e[0;33m"
#define GRN "\e[0;32m"
#define BLU "\e[0;34m"
#define RED "\e[0;31m"
#define MAG "\e[0;35m"
#define reset "\e[0m"
#define CYN "\e[0;36m"
#define BLK "\e[0;30m"
// vai ser colorido 
// antes de tudo preciso de tudo para fazer o menu 
typedef struct{
    int vitoria_X;
    int vitoria_O;
    int empates;
}placar_jogo;
char tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];
char jogador_atual;
placar_jogo placar;
// tive que pesquisar, esse é o jeito que encontrei para armazenar os dados do placar
#define arquivo_p "placar.txt"

int iniciar_tabuleiro();
int desenhar_tabuleiro();
int jogada(int *linha, int *coluna);
int validar_jogada(int linha, int coluna);
int movimento(int linha, int coluna);
int vitoria();
int empate();
int alternar_jogador();

int carregar_placar();
int salvar_placar();
int menu_principal();
int sobre_o_jogo();

int main(){
    int linha;
    int coluna;
    int escolha_menu;
     placar.vitoria_X = 0;
    placar.vitoria_O = 0;    // para o placar sempre começar zerado.
    placar.empates = 0;
    salvar_placar();

    carregar_placar();

    while(1){
        escolha_menu = menu_principal();

        switch(escolha_menu){
        case 1: {int jogo_rolando = 1; // jogo rolando 
                iniciar_tabuleiro();
                jogador_atual = jogador_X;
                while(jogo_rolando){
                system("clear");
                desenhar_tabuleiro();

                printf("\njogador %c e seu turno", jogador_atual);

                while(1){
                    if(jogada(&linha, &coluna) == 0){
                        printf(CYN);
                        printf("Entrada invalida. Digite apenas numeros para linha e coluna (1-3).\n");
                        printf(reset);
                        while(getchar() != '\n');
                        continue;
                    }
                    if(validar_jogada(linha, coluna)){
                        break;
                    }else{
                        printf("jogada invalida, tente novamente.\n");
                    }
                }
                movimento(linha, coluna);
                if(vitoria()){
                    system ("clear");
                    desenhar_tabuleiro();
                    printf(MAG);
                    printf("\n--- FIM DE JOGO ---\n");
                    printf("O Jogador %c VENCEU!\n", jogador_atual);
                    printf(reset);
                    if(jogador_atual == jogador_X){
                        placar.vitoria_X++;
                    }else{
                        placar.vitoria_O++;
                    }
                    salvar_placar();
                    jogo_rolando = 0; // termina o jogo 
                }else if (empate()){
                    system("clear");
                    desenhar_tabuleiro();
                    printf(RED);
                    printf("\n--- FIM DE JOGO ---\n");
                    printf("EMPATE! O tabuleiro esta cheio.\n");
                    printf(reset);
                    placar.empates++;
                    salvar_placar();
                    jogo_rolando = 0;
                }else{
                    alternar_jogador();
                }
            }
                printf(GRN);
                printf("\nPressione ENTER para voltar ao menu principal...");
                printf(reset);
                while (getchar() != '\n');
                break;
        }
        case 2: {
            system("clear");
                printf(BLU);
                printf("--- PLACAR GERAL ---\n");
                printf("Vitorias Jogador X: %d\n", placar.vitoria_X);
                printf("Vitorias Jogador O: %d\n", placar.vitoria_O);
                printf("Empates:           %d\n", placar.empates);
                printf("---------------------\n");
                printf("\nPressione ENTER para voltar ao menu...");
                printf(reset);
                while (getchar() != '\n'); // Espera o usuário pressionar Enter
                break;
        }
        case 3: {
            sobre_o_jogo();
            break;
        }
        case 4: {
            printf(YEL);
            printf("Saindo do Jogo da Velha. Ate mais!\n");
            printf(reset);
            salvar_placar();
            return 0;
        }
        default:
        {
            printf("Opcao invalida. Tente novamente.\n");
                break;
        }
     }

}
    return 0;
}
int iniciar_tabuleiro(){
    for(int i = 0; i < tamanho_tabuleiro; i++){
         for (int j = 0; j < tamanho_tabuleiro; j++) {
            tabuleiro[i][j] = espaco;     // e normal o código ser desse tamanho ? 
    }
}
return 0;
}

int desenhar_tabuleiro(){
printf("   1   2   3\n");
printf(" -----------\n");
for (int i = 0; i < tamanho_tabuleiro; i++) {
        printf("%d | %c | %c | %c |\n", i + 1, tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < tamanho_tabuleiro - 1) {
            printf(" -----------\n");
        }
    }
    printf(" -----------\n");
    return 0;
}
int jogada(int *linha, int *coluna) {
    printf("Digite a linha (1-3) e a coluna (1-3) separadas por espaco: ");
    if (scanf("%d %d", linha, coluna) != 2) {
        return 0;
    }
     (*linha)--; 
    (*coluna)--; 
    return 1;
    }

    int validar_jogada(int linha, int coluna) {
    if (linha < 0 || linha >= tamanho_tabuleiro || coluna < 0 || coluna >= tamanho_tabuleiro) {
        return 0; // 
    }
    if (tabuleiro[linha][coluna] != espaco) {
        return 0;
    }
    return 1;
}
int movimento(int linha, int coluna) {
    tabuleiro[linha][coluna] = jogador_atual;
    return 0; 
}
int vitoria(){
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        if (tabuleiro[i][0] == jogador_atual &&
            tabuleiro[i][1] == jogador_atual &&
            tabuleiro[i][2] == jogador_atual) {
            return 1;
        }
}

    for (int j = 0; j < tamanho_tabuleiro; j++) {
        if (tabuleiro[0][j] == jogador_atual &&
            tabuleiro[1][j] == jogador_atual &&
            tabuleiro[2][j] == jogador_atual) {
            return 1;
        }
    }
     if (tabuleiro[0][0] == jogador_atual &&
        tabuleiro[1][1] == jogador_atual &&
        tabuleiro[2][2] == jogador_atual) {
        return 1;
    }
    if (tabuleiro[0][2] == jogador_atual &&
        tabuleiro[1][1] == jogador_atual &&
        tabuleiro[2][0] == jogador_atual) {
        return 1;
    }

    return 0;
}
int empate() {
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            if (tabuleiro[i][j] ==espaco) {
                return 0; 
            }
        }
    }
    return 1; 
}
int alternar_jogador() { 
    jogador_atual = (jogador_atual == jogador_X) ? jogador_O : jogador_X;
    return 0; 
}
int carregar_placar() {
    FILE *arquivo = fopen(arquivo_p, "r"); 
    if (arquivo_p == NULL) {
        placar.vitoria_X = 0;
        placar.vitoria_O = 0;
        placar.empates = 0;
        return 0;
    }
    if (fscanf(arquivo, "%d %d %d", &placar.vitoria_X, &placar.vitoria_O, &placar.empates) != 3) {
        placar.vitoria_X = 0;
        placar.vitoria_O = 0;
        placar.empates = 0;
        fclose(arquivo);
        return 0;
    }
    fclose(arquivo); // Fecha o arquivo
    return 1; // Sucesso ao carregar
}
// Salva o placar no arquivo
// Retorna 1 se sucesso, 0 se falha
int salvar_placar() {
    FILE *arquivo = fopen(arquivo_p, "w"); // Abre para escrita ("w"), sobrescreve o arquivo
    if (arquivo == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo de placar para escrita.\n");
        return 0; // Falha
    }
    fprintf(arquivo, "%d %d %d", placar.vitoria_X, placar.vitoria_O, placar.empates);
    fclose(arquivo); // Fecha o arquivo
    return 1; // Sucesso ao salvar
}
// Exibe o menu principal e retorna a escolha do usuário
int menu_principal() {
    int escolha;
    system("clear");
    printf(CYN);
    printf("--- JOGO DA VELHA ---\n");
    printf("1. Novo Jogo\n");
    printf("2. Ver Placar\n");
    printf("3. Sobre o Jogo\n");
    printf("4. Sair\n");
    printf("---------------------\n");
    printf("Escolha uma opcao: ");
    printf(reset);
    while (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > 4) {
        printf("Opcao invalida. Digite um numero entre 1 e 4: ");
        // Limpa o buffer de entrada
        while (getchar() != '\n'); 
    }
    while (getchar() != '\n'); 
    // Limpa o resto do buffer após a leitura do inteiro
    return escolha;
}
// Exibe informações sobre o jogo
int sobre_o_jogo() {
    system("clear");
    printf(BLK);
    printf("--- SOBRE O JOGO DA VELHA ---\n");
    printf("Desenvolvido pelo aluno Heitor.\n");
    printf("Versao: 1.0\n");
    printf("quase enlouqueci fazendo mas agora ta lindo é funcional");
    printf("Regras basicas do Jogo da Velha:\n");
    printf("- Dois jogadores, 'X' e 'O', se revezam marcando espacos no tabuleiro 3x3.\n");
    printf("- O objetivo e conseguir tres de suas marcas em uma linha, coluna ou diagonal.\n");
    printf("- Se todas as casas forem preenchidas e ninguem vencer, o jogo termina em empate.\n");
    printf("\nPressione ENTER para voltar ao menu...");
    printf(reset);
    while (getchar() != '\n'); // Espera o usuário pressionar Enter
    return 0;
    //preciso encaixar tudo isso exclusivamente na função main 
}
    