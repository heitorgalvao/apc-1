#include <stdio.h>

    int main(){

        printf("tabela da verdade\n");
        printf("0 E 0 = %i\n", 0 && 0);
        printf("0 E 1 = %i\n", 0 && 1);
        printf("1 E 0 = %i\n", 1 && 0);
        printf("1 E 1 = %i\n", 1 && 1);
        printf("\n");
        printf("0 E 0 = %i\n", 0 || 0);
        printf(" 0 E 1 = %i\n", 0 || 1);
        printf("1 E 0 = %i\n", 1 ||0);
        printf("1 E 1 = %i\n", 1 || 1);
        printf("nao 0 = %i\n", !0);
        printf("1 = %i\n", !1);

    return 0;
}