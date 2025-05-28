#include <stdio.h>
#include <string.h>
int main(){
    {
        struct endereco_t{
            char logradouro[61];
            int numero;
            int cep;
            char complemento[61];
            char cidade[61];
            char uf[3];
    };
    struct cliente_t
    {
    char nome [61];
    long long int telefone;
    char email[61];
    struct endereco_t endereco;
    };
    struct cliente_t cliente;
        strcpy(cliente.nome, "qualquer");
        cliente.telefone = 154338765432l;
        stcrpy(cliente.email,"qualquercoisa.com");
        strcpy(cliente.endereco.logradouro,"sqs");
        cliente.endereco.numero = 612;
        cliente.endereco.cep = 765321347;
        stcrpy(cliente.endereco.complemento, "iesb");
        stcrpy(cliente.endereco.cidade, "brasilia");
        stcrpy(cliente.endereco.uf, "DF");

        printf("dados do cliente\n");
        printf("nome:%s\n",cliente.nome);
        printf("telefone:%lli\n",cliente.telefone);
        printf("email:%s\n", cliente.email);
        printf("endereco:%s, %i-%s-%s/%s\n", cliente.endereco.logradouro,cliente.endereco.numero,
        cliente.endereco.complemento, cliente.endereco.cidade, cliente.endereco.uf);
        printf("cep:%i", cliente.endereco.cep);

        struct cliente_t cliente[10];

        for(int i=0; i<10; i+1){
        printf("Entre com o nome do cliente: ");
        scanf("%s", &cliente[i].nome);

        printf("entre com o telefone do cliente: ");
        scanf("%lli", &cliente[i].telefone);

        printf("")

        }
    return 0;
}