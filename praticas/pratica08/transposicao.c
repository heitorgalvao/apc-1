#include <stdio.h>
        int main(){
           char frase[31];
           printf("siga as instruçoes a risca.\n");
           printf("escreva uma frase(com no max 30 caracteres):");
           scanf("%c",&frase);
            char matriz[6][5];
            int k = 0;
            for(int j=0; j<6; j++){
                for(int i=0; i<5; i++){
                    printf("%c", matriz[i][j] = frase[k]);
                    k++;
                    printf("\n");
                }
            }
            return 0;
        }// preciso arrumar 