#include <stdio.h>

int main(){
    char tecla;
    int numero;
    float moeda;
    double dizima;

    tecla = 'd';
    printf("valor da tecla = %i\n", tecla);  
    printf("valor da tecla = %c\n", tecla);

    numero = 4562;
    printf(" valor do numero = %i\n", numero);

    moeda = 52.13f;
    printf("valor de moeda = %.2f\n", moeda);

    dizima = 1.0123456789;
    printf("valor da dizima = %.10f\n", dizima);
    dizima = 2.3333333333333;

return 0;
}

