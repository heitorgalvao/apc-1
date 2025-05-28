#include <stdio.h>
        int main(){
            int nota;
            printf("digite sua nota:");
            scanf("%i", &nota);
            switch(nota){
             case 1:   printf("Voce ganhou '*'.\n");break;
             case 2:   printf("Voce ganhou '**'.\n");break;
             case 3:   printf("Voce ganhou '***'.\n");break;
             case 4:   printf("Voce ganhou ****!\n");break;
             case 5:   printf("Voce ganhou *****!\n");break;
             default:   printf("Nota invalida! Tente novamente.\n");break;
            }
            return 0;
        }