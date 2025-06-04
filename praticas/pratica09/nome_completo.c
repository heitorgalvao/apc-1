#include <stdio.h>
#include <string.h>
    int main(){
        char primeiro_nome[11];
        char ultimo_nome[11];
        printf("digite seu primeiro nome: ");
        scanf("%s", primeiro_nome);// precisamos que ele leia como string por isso %s ao inves de %c.
        printf("\n digite seu ultimo nome: ");
        scanf("%s", ultimo_nome);
        char nome[31];
        strcpy(nome, primeiro_nome);
        strcat(nome, " ");
        strcat(nome, ultimo_nome);
        printf("\nnome completo: %s",nome);
        return 0;
    }