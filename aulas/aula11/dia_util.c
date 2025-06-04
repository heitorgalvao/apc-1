#include <stdio.h>

    #define VERDDEIRO true

    #define domingo 1
    #define segunda 2 
    #define terca 3
    #define quarta 4
    #define quinta 5
    #define sexta 6
    #define sabado 7
    int main(){
        enum dias_da_semana_e{
            dmo = 1, 
            seg,
            ter,
            quar,
            quin,
            sex,
            sab
        };
        int dia = 0;
        printf("entre com o dia da semana(1 a 7): ");
        scanf("%i",&dia);
        switch (dia){

            case seg:
            case ter:
            case quar:
            case quin:
            case sex:
                printf("eh dia util\n");
                break;
                default:
                printf("dia invalido\n");

        }
        
        
        return 0;
    }