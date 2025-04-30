#include <stdio.h>
        int main(){
            float media; 
            printf("digite sua media final:");
            scanf("%f", &media);
            if (media == 0.0f) {
                printf("A mencao eh 'SR'.\n");
              }else if (media < 3.0f) {
                printf("A mencao eh 'II'.\n");
              }else if (media < 5.0f) {
                printf("A mencao eh 'MI'.\n");
              }else if (media < 7.0f) {
                printf("A mencao eh 'MM'.\n");
              }else if (media < 9.0f) {
                printf("A mencao eh 'MS'.\n");
              }else {
                printf("A mencao eh 'SS'.\n");
              }
              
            return 0;
        }