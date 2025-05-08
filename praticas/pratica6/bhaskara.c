#include <stdio.h>
#include <math.h>

int main (){
    int a;
    int b;
    int c;
    printf("insira as 3 variaveis espassadas:\n");
    scanf("%i %i %i", &a, &b, &c);
    float delta = b*b - 4*a*c;

        if(delta > 0){
        float x1 = (-b + sqrt(delta)) / 2*a;
        float x2 =  (-b - sqrt(delta)) / 2*a;

        printf("a primeira raiz e %2.f", x1);
        printf("a segunda raiz e %2.f" , x2);

        }else{
        printf("a equacao nao tem raizes reais");
        } 
    return 0;
}