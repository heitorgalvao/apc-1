#include <stdio.h>

int main(){
    //char 'i', 'a' (usamos para omprimir caracter)
    // int -125, 0, 12345654 (imprime números inteiros)
    // float -9.123456, 0.0, 0.665666f (float serve para imprimir letra)
    //double -9.123456789012345, 5.0123456789554654 (para números decimais)
    // void sem tipo (imprime qualquer tipo de varíavel) 

    printf("o tipo 'char' ocupa %i bytes e vai de %i a %i\n", sizeof(char), -128,127);
    printf("o tipo 'int' ocupa %i bytes e vai de %i a %i\n", sizeof(int), -217483648, 21783647);
    printf("o tipo 'float' ocupa %i bytes e vai de %E a %E\n", sizeof(float), -3.E+38, 3.4E+38);
    printf("o tipo 'double' ocupa %i bytes e vai de %E a %E\n", sizeof(double), -1.8E+308, 1.8E+308);
    printf("o tipo 'void'ocupa %i bytes\n", sizeof(void));
 return 0;   
}