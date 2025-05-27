#include <stdio.h>
    int main (){
        int numeros[10];
        printf("insira 10 numeros inteiros:\n");
        for(int i=0; i<10; i++) {
            printf("numero %i:", i+1);
            scanf("%i",&numeros[i]);
        }
        int numero;
        printf("\n digite um numero para buscar: ");
        scanf("%i",&numero);
        int achou = -1;
        for(int i=0; i<10; i++){
            if(numeros[i]== numero){
                achou = i;
                break;
            }
            if(achou < 0){
                printf("o numero nao foi encontrado.\n");
            }else{
                printf("o numero foi encontrado na posicao %i\n", &achou);
            }
        }
        return 0;
    }// preciso arrumar este codigo 