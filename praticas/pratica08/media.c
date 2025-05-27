#include <stdio.h>
    int main (){
        float notas[10];
        float soma = 0.0f;
        float media;
        int qtde_acima_media = 0;
        printf("Digite as 10 notas dos alunos:\n");
        for (int i = 0; i < 10; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma = soma + notas[i];
    }
        media = soma / 10.0f;
        for (int i = 0; i < 10; i++) {
            if (notas[i] > media) {
            qtde_acima_media++;
        }
         printf("\n--- Resultados ---\n");
        printf("Media da turma: %.2f\n", media);
        printf("Quantidade de alunos acima da media: %d\n", qtde_acima_media); 
        }
    return 0;
}