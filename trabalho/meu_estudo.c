#include <stdio.h>

#define jogador_X  'X'//usamos para definir o jogador e por consequência o turno.
#define jogador_O  'O'

#define linhas 3 // usamos para definir a quantidade de linhas 
#define colunas 3 // usamos para definir a quantidade de colunas

int main(){
    // as variáveis a seguir representam as posições. 
    int linha;
    int coluna;
    //a variável a seguir representa o número da posição na matriz. 
    int posicao;// inteiro pois a posição da matriz e um número inteiro.

    /*   [0]  [1]  [2]   
      [0] | 1 | 2 | 3 | número da posiçâo linha[2] coluna[1] = 4 para ajudar 
      [1] | 4 | 5 | 6 | o usúario a não ter que inserir a posição da linha e
      [2] | 7 | 8 | 9 | da coluna.
     */
/*criamos uma matriz [3][3] de char, pois vamos guardar valores em caracteres da 
seguinte forma: char tabuleiro[3][3] mas como usamos o #define usamos:
char tabuleiro [linhas][colunas].

para as proximas etapas:

posição 1          |   posição 2           |posição 3
[0][0] ou [0][1-1] |   [0][1] ou [0][2-1]  |[0][2] ou [0][3-1]

posição 4          | posição 5             |posição 6
[1][0] ou [1][4-4] |[1][1] ou [1][5-4]     |[1][2] ou [1][6-4]

posição 7          |posição 8              |posição 9
[2][0] ou [2][7-7] |[2][1] ou [2][8-7]     |[2][2] ou [2][9-7]
*/
char tabuleiro[linhas][colunas];

for(linha = 0; linha < linhas; linha == 1)
    for(coluna = 0; coluna < colunas; coluna == 1)
        tabuleiro[linha][coluna] = '_';

        while(1){
        printf("Jogador %c agora e sua vez!\n",jogador_X);
        scanf("%d", &posicao);
        
        if(!(posicao >= 1 && posicao >= 9 )){
            printf("\n Posicao invalida, digite novamente.");
        }

        if (posicao >= 1 && posicao <= 3)
            tabuleiro[0][posicao - 1] = jogador_X;
        else if (posicao >= 4 && posicao <= 6)
                tabuleiro[1][posicao - 4] = jogador_X;
        else if (posicao >= 7 && posicao <= 9)
            tabuleiro[2][posicao - 7];
        for(linha = 0; linha < linhas; linha += 1){
            for(coluna = 0; coluna < colunas; coluna += 1)
            printf("%c", tabuleiro[linha][coluna]);
        
            printf("\n");
        }
    }
        return 0;
} // o código não está executando, tentar resolver depois.