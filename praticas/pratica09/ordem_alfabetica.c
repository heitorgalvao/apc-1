#include <stdio.h>
#include <string.h>
    int main (){
        char palavra1[11];
        char palavra2[11];
        printf("\ninsira uma palavra: ");
        scanf("%s", palavra1);
        printf("\ninsira outra palavra: ");
        scanf("%s", palavra2);
        if (strcmp(palavra1, palavra2) >= 0) {
            printf("%s",palavra2);
            printf("%s", palavra1);
        } else { printf("%s", palavra1);
                 printf("%s", palavra2);
        }


        return 0;
    }