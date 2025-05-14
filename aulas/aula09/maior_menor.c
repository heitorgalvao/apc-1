#include <stdio.h> // aprendendo matriz
    int main (){  
        int maior = -9999;
        int menor = 9999;                                         //        0 1 2 3 4 5 6 7 8 9
        int numeros[10]; // matriz unidimensional = vetor = array = |0|-1|10|6|-5|-7|7|11|2|0|
        numeros[0] =5;
        numeros[1] = -1;
        numeros[2] = 10;
        numeros[3] = 6;
        numeros[4] = -5;
        numeros[5] = -7;
        numeros[6] = 7;
        numeros[7] = 11;
        numeros[8] = 2;
        numeros[9] = 0;
        printf("entre com 10 numeros inteiros\n");
        for(int i=0; i<10; i++){
            printf("numero %i:", i+1);
            scanf("%i",&numeros[i]);

            if (maior < numeros[i]){
                maior = numeros[i];
            }
            if (menor > numeros[i]){
                menor = numeros[i];
            }
        }
        printf("seus numeros foram: ");
        for(int i=0; i < 10; i ++){
            printf("%i, ", numeros[i]);
        }
        printf("\n");
        
        return 0;
    }