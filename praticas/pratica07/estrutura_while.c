#include <stdio.h>
    int main () {
        int nota;
        printf("insira sua nota:");
        scanf("%i",&nota);
        while(nota < 1 || nota > 10) {
            printf("Nota invalida. Tente novamente!\n");
            printf("insira sua nota:");
            scanf("%i", &nota);
        }
        

        return 0;
    }