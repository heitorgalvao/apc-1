#include <stdio.h>

int main() {
    int idade = 0;
    printf("informe sua idade: ");
    scanf("%i", &idade);

    if(idade<16){
        printf("voce nao pode votar");
    }else{
        if(idade >=18 && idade <= 70);
            printf("voce e obrigado a votar");
        }else{
            printf("voce pode votar!\n");
        }
    }
    
    return 0;
}