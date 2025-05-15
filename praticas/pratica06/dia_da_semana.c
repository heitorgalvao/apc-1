#include <stdio.h>
int main() {
    int dia = 0;
    printf("digite um número de 1 a 7 para definir o dia da semana:");
    scanf("%i",&dia);
    if( dia == 1 ){
    printf("Domingo\n");
    }
    else if(dia == 2){
    printf("Segunda\n");
    }
    else if(dia == 3){
    printf("terça\n");
    }
    else if(dia == 4){
    printf("quarta\n");
    }
    else if(dia == 5){
    printf("quinta\n");
    }
    else if(dia == 6){
    printf("sexta\n");
    }
    else if(dia == 7){
    printf("sabado\n");
    }else{
    printf("dia invalido\n");
    }
    return 0;
}