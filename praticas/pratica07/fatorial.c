#include <stdio.h>
    int main() {
        int numero;
        printf("insira um numero inteiro:");
        scanf("%i", &numero);
        int fatorial =1;


        for(int i=numero; i>0; i--) {
            fatorial = fatorial * i;
        }
        printf("o fatorial de %i e %i", &numero , &fatorial);

        return 0;
    }