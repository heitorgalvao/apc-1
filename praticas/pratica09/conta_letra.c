#include <stdio.h>
#include <string.h>
    int main(){
        char frase [31];
        printf("escreva uma frase: \n");
        scanf("%s", frase);
        while (getchar() != '\n');
         char letra;
        printf("insira uma letra: \n");
        scanf("%c", &letra);
        int quantidade = 0;
        for(int i=0; i<strlen(frase); i++) {
            if (frase[i] == letra) {
                    quantidade++;
                }else if (quantidade > 0 ){
                    printf("%i" ,&quantidade);
                }else{
                    printf("A frase não contem a letra!");


        }

        

        return 0;
    }
}