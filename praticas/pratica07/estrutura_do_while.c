#include <stdio.h>
    int main () {
        int nota;
        printf("insira sua nota:");
        scanf("%i", &nota);
        do {
        } while(nota < 1 || nota > 10);
            if(nota < 1 || nota > 10) {
            printf("Nota invalida. Tente novamente!\n");
         }
         

        return 0;
    }