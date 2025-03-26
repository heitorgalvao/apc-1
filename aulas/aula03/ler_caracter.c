#include <stdio.h>
int main(){
    char tecla;

    printf("pressione uma tecla e depois enter: ");
    scanf("%c", &tecla);// tecla = 'a'
    getchar();//ler o /n da leitura anterior
    printf("voce pressionou a tecla: %c\n", tecla);


    printf("pressione outra tecla: e depois enter: ");
    scanf("%c", &tecla);//tecla ='a';

    printf("Voce prssionou a tecla '%c'\n", tecla);

return 0;

}