
#include <stdio.h> 
#include <stdlib.h> 
    int main(){
        #define GRN "\e[0;32m"
        #define BLU "\e[0;34m"
        #define RED "\e[0;31m"
        #define MAG "\e[0;35m"
        #define reset "\e[0m"
        int opcao = 0;
        while (opcao != 4){
            system("clear");
        printf(RED);
        printf("   -----------------------------------\n");
        printf("|            MENU PRINCIPAL          |\n");
        printf("  ------------------------------------\n");
        printf("| 1 - Novo jogo                      |\n");
        printf("| 2 - ver score                      |\n");
        printf("| 3 - sobre o jogo                   |\n");
        printf("|4 - Sair                            |\n");
        printf(" -------------------------------------\n");
        printf("escolha uma opcao >");
        scanf("%i", &opcao);
        printf(reset);
        while (getchar() != '\n');

        switch(opcao){
            case 1:{
            int nivel = 0;
            printf("nível do jogo\n");
            printf("1 - facil\n");
            printf("2 - medio\n");
            printf("3 - Dificil\n");
            printf("escolha um nivel >");
            scanf("%i",&nivel);
            while (getchar() != '\n');
            break;
        }
            case 2: {
            printf(BLU);
            printf("score do jogo\n");
            printf("1 - jogador A - 10000 pontos\n");
            printf("2 - jogador B - 7000 pontos\n");
            printf("3 - jogador C - 5000 pontos\n");
            printf("4 - jogador D - 3000 pontos\n");
            printf("5 - jogador E - 1000 pontos\n");
            printf("precione ENTER para continuar........");
            printf(reset);
            while (getchar() != '\n');
            break;
            }
                case 3:{
                printf(MAG);
                printf("Sobre o jogo\n\n");
                printf("Desenvolvido em C\n");
                printf("por Mim e eu mesmo\n\n");
                printf("copyright(C) 2025\n");
                printf("pressione ENTER para continuar.....");
                printf(reset);
                while (getchar() != '\n');
                break;  
            }
                case 4:{
                printf(GRN);
                printf("Ate logo!\n");
                printf(reset);
                break;
        }
                default: printf("opcao invalida! tente novamente");
        }
    }
}