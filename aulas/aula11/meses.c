#include <stdio.h>

int main (){
    enum mese_do_ano {jan, fev, mar, abr, mai, jun, jul, ago, sep, out, nov, dez,};

    char nome_dos_meses[12][10] ={"janeiro", "fevereiro", "marco", "abril", "maio",
    "junho", "julho", "agosto", "novembro", "dezembro"};

    int mes = 0;
    printf("entre com um mes (1 a 12): ");
    scanf("%i", &mes);

    if (jan < mes-1 && mes-1 < dez) {
        printf("o mes escolhido foi %s\n", nome_dos_meses[mes-1]);
    }else {
        printf("mes invalido\n");
    }
    return 0;

}