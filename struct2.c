#include <stdio.h>

    struct endereco
    {
        char nome_rua[40];
        char bairro[40]; 
        int numero;
        char cidade[40];
        int cep;
    };
 
    struct data_nascimento
    {
        int dia;
        int mes;
        int ano;
    };

    struct cadastro_cliente
    {
        char nome_cliente[40];
        int telefone;
        struct endereco dados_endereco; //variável dados_endereco do tipo endereco
        struct data_nascimento data_nascimento;
    }cad_cliente[2];


int main () {

    int i,j,k;
    
    //Aqui nós vamos fazer um VETOR DE STRUCSTS 
    //Dentro do cad_cliente, teremos duas structs
    for(i=0<i<2;i++)
    {
        printf("\n\n--Digite o nome do cliente--\n\n");
        fflush(stdin);
        fgets(cad_cliente[i].nome_cliente,40,stdin);
        
        printf("\n\n--Digite o telefone do cliente--\n\n");
        scanf("%d",&cad_cliente[i].telefone);

        printf("\n\n--Digite o nome da rua--\n\n");
        fflush(stdin);
        fgets(cad_cliente[i].dados_endereco.nome_rua,40,stdin);

        printf("\n\n--Digite o numero--\n\n");
        scanf("%d",&cad_cliente[i].dados_endereco.numero);
        
        printf("\n\n--Digite o bairro--\n\n");
        fflush(stdin);
        fgets(cad_cliente[i].dados_endereco.bairro,40,stdin);

        printf("\n\n--Digite o nome da cidade--\n\n");
        fflush(stdin);
        fgets(cad_cliente[i].dados_endereco.cidade,40,stdin);

        printf("\n\n--Digite o CEP\n\n");
        scanf("%d",&cad_cliente[i].dados_endereco.cep);

        printf("\n\n--Digite o dia de nascimento--\n\n");
        scanf("%d",&cad_cliente[i].data_nascimento.dia);
        
        printf("\n\n--Digite o mes de nascimento--\n\n");
        scanf("%d",&cad_cliente[i].data_nascimento.mes);

        printf("\n\n--Digite o ano de nascimento--\n\n");
        scanf("%d",&cad_cliente[i].data_nascimento.ano);
    }


 


    return 0;
}

