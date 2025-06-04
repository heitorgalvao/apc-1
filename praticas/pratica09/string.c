#include <stdio.h>
#include <string.h>

int main(){
    char string[11];
    memset(string, '\0', sizeof(string));
    char tecla;
    printf("digite uma letra:");
    scanf("%c", &tecla);        //%c le a variável char
    memset(string, tecla, 10); // preenche toda a linha com o letra 
    printf("%s\n", string);    //%s le a variável string 
    memset(string, '*', 5);
    printf("%s\n", string);
    string[5] = '\0';
    printf("%s\n",string);
    for(int i=0; i<10; i++) {
        printf("%c", string[i]);
    }
    printf("\n");

    return 0;
}