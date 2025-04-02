#include <stdio.h>
    int main(){
        float preco;
        float valor_total;
        char nome_produto [31];// 31 e a quantidade de caracteres
        int quantidade;

        printf("entre com o nome do produto: ");
        scanf("%[^\n]s", nome_produto);
        getchar();

        printf("entre com a quantidade do produto: ");
        scanf("%i" , &quantidade); 

        printf("entre com o preco do produto: ");
        scanf("%f", &preco);
        getchar();

        valor_total = preco * quantidade;

        printf("NOTA LEGAL\n");
        printf("item        Qtd Preco valor\n");
        printf("%-15s %03i %7.2f\n", nome_produto, quantidade, preco, valor_total);
        printf("total: %15.2f", valor_total);
        return 0;
    }