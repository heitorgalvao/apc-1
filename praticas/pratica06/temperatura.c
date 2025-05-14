#include <stdio.h>
int main (){
    #define GRN "\e[0;32m"
    #define BLU "\e[0;34m"
    #define RED "\e[0;31m"
    #define MAG "\e[0;35m"
    #define reset "\e[0m"

    float temperatura;
    printf("insira a temperatura que quer avaliar:");
    scanf("%f", &temperatura);
    
    if(temperatura >= 40.0f){
        printf(RED);
        printf("muito quente\n");
        printf(reset);
    }else if(temperatura >= 30.0f){
        printf(MAG);
        printf("quente\n");
        printf(reset);
    }else if(temperatura >= 20.0f){
        printf(GRN);
        printf("agradavel\n");
        printf(reset);
    }else{
        printf(BLU);
        printf("frio\n");
        printf(reset);
    }
    return 0;
}