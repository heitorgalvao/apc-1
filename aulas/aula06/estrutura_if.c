#include <stdio.h>
    int main(){
        int numero;
        printf("Digite um número inteiro: ");
            scanf("%i", &numero);
            int numero_eh_divisivel_por_2 = numero % 2 == 0;
                if(numero_eh_divisivel_por_2) {
                    printf("O numero %i eh par!\n", numero);
                }else{
                    printf("O numero %i eh impar!\n", numero);
                      }
             return 0;         
                }
        
    