#include <stdio.h>

int main(){
    int numero = 0;

    while(numero < 1 || numero > 10){
    printf("entre com um numero inteiro entre 1 e 10:");
    scanf("%i", &numero);
    while(getchar() != '\n');//limpar buffer do teclado
    } 
    return 0;
}