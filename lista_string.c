#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct lista Lista;

struct lista {
    char* string; //string armazenada
    struct lista* prox; //ponteiro pro proximo elemento
};

Lista* cria_lista (void){
    return NULL;
}

Lista* insere_palavra(Lista* inicio_lst, char* palavra) // char palavra[]
{
    Lista* novo;
    novo = (Lista*) malloc(sizeof(Lista));
    novo->string = palavra;
    novo->prox = inicio_lst;
    return novo;
}

Lista* busca_palavra(Lista* inicio_lst, char* palavra)
{
    Lista* p = inicio_lst;
    int verificador, valor_verificador;
    
        while(p!=NULL)
        {
            verificador = strcmp(p->string, palavra);
            if(verificador == 0)
            {
                return 1; /* Achou */
            }

            p=p->prox;
        }
    return inicio_lst;
}


Lista* retira_palavra(Lista* inicio_lst, char* palavra)
{
    Lista* p = inicio_lst;
    Lista* anterior = NULL;

    int verificador;
}

void imprime_palavra (Lista* inicio_lst)
{
    Lista* p = inicio_lst;
        
        while(p != NULL)
        {
            printf("\n%s\n",p->string);
            p = p->prox;
        }
}

int main () {

    Lista* inicio_lst = cria_lista();
    
    char palavra[100];
    printf("\n --- Insira aqui a palavra desejada\n\n");
    fflush(stdin);
    scanf("%s",&palavra);

    inicio_lst = insere_palavra(inicio_lst, palavra);

    imprime_palavra(inicio_lst);


    //int escolha;



    /*do {

        printf("1: Adicionar palavra\n");
        printf("2: Remover\n");
        printf("3: Imprimir\n");
        printf("4: Sair\n");
        printf("_______________________\n");
        printf("Escolha a Opcao Desejada: ");
        scanf("%d ",&escolha);*/
        //fflush(stdin);

        /*switch(escolha)
        {
            case 1:
            printf("_______________________\n");
            printf("Voce selecionou adicionar palavra\n");
            printf("_______________________\n");   
            printf("Digite a palavra: ");   
            //fflush(stdin);
            fgets(palavra,100,stdin);

            inicio_lst = insere_palavra(inicio_lst, palavra);
            break;
       

            case 2:
            printf("_______________________\n");
            printf("Voce selecionou imprimir palavra\n");
            printf("_______________________\n");   
            imprime_palavra(inicio_lst);
            break;
        }

    }while(escolha != 4);

    */

    return 0;
}

