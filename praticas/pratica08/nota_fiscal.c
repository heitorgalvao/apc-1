#include <stdio.h>
    int main(){
         #define GRN "\e[0;32m"
        #define BLU "\e[0;34m"
        #define RED "\e[0;31m"
        #define MAG "\e[0;35m"
        #define reset "\e[0m"
        float total = 0.0f;
        float nota_fiscal[5][3];
        printf("entre com 5 valores:\n");
        for(int i=0; i<5; i++){
            printf("item %d:", i+1);
            printf("quantidade:");
            scanf("%f", &nota_fiscal[i][0]);
            printf("  Preco unitario: ");
            scanf("%f", &nota_fiscal[i][1]);
            nota_fiscal[i][2] = nota_fiscal[i][0] * nota_fiscal[i][1];
            total = total + nota_fiscal[i][2];
        }
        printf(RED);
        printf("\n--- Detalhes da Nota Fiscal ---\n");
        printf("Item | Quantidade | Preco Unit. | Subtotal\n");
        printf("------------------------------------------\n");
        printf(reset);
        for (int i = 0; i < 5; i++) {
        printf("%4d |", i + 1);
        for (int j = 0; j < 3; j++) {
            printf(" %10.2f |", nota_fiscal[i][j]);
        }
        printf("\n");
    }
    printf(GRN);
     printf("------------------------------------------\n");
     printf("Total Geral: %.2f\n", total);
     printf(reset);

     return 0 ;
    }