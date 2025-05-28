#include <stdio.h>
    int main (){
        int n;
        int anterior = 0;
        int proximo = 1;
        printf("insira um numero qualquer(n):");
        scanf("%i",&n);
        for(int i=0; i<n; i++) {
        int posterior;
        posterior = proximo;
        proximo = anterior + posterior;
        anterior = posterior;
        printf("%i", proximo);
        }
        return 0;
    }