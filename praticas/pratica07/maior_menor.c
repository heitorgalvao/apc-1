#include <stdio.h>
    int main (){
        int numero;
        int maior;
        int menor;

        printf("insira um numero inteiro:");
        scanf("%i",&numero);
        
        menor = numero;
        maior = numero;


        while(numero != 0){
        if (numero > maior){
        printf("%i",&maior);
        }if (numero < menor){
        printf("%i",&menor);
        }
    }
        return 0;
    }