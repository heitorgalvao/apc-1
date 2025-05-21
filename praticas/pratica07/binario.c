#include <stdio.h>
    int main (){
        int numero;
        printf("insira um numero para transformar em binario:");
        scanf("%i",numero);
        int decimal;
        decimal = numero;
        for(int i=128; i>0; i=i/2) {
            int bit = decimal % i;
            printf("%i", bit);
            decimal = decimal - bit * i;
}

        return 0;
    }// ta faltando alguma coisa, tenho que descobrir oq é 