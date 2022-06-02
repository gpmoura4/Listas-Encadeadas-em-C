#include <stdio.h>
#include <stdlib.h>

/*Precisamos de struct, pq no Elemento da Lista, temos duas informacoes
o conteudo, e o ponteiro pro proximo elemento*/

struct lista_02 {
    int info;   //conteudo
    struct lista_02 *prox; //ponteiro do tipo da struct para o prox elemtno
    struct lista_02 *anterior;
};typedef struct lista_02 Lista_02;
  
//  Lista_02* n = NULL;
Lista_02* cria_lista (void)
{
    return NULL;   
}

Lista_02* insere_lista(Lista_02* inicio_da_lst, int valor)
{
    Lista_02* novo = (Lista_02*) malloc(sizeof(Lista_02));//Alocando memoria para rececber o elemento
    novo->info = valor; //Passando o valor usado como parâmetro
    novo->prox = inicio_da_lst; //Inserção no inicio
    novo->anterior = NULL;

    /*A lista nao esta vazia? */
    /*Entao, tem elementos nela ja, vamos fazer o ultimo elemento colocado
      apontar para o novo nó através do ponteiro anterior*/
    if(inicio_da_lst != NULL)
    {
        inicio_da_lst->anterior = novo;
    }
    return novo; //ponteiro para o proximo elemento
}

void imprime_lista (Lista_02* inicio_da_lst)
{
    Lista_02* p;
    for(p=inicio_da_lst; p!=NULL; p = p->prox)
    {
        printf("\n Elemento = %d\n",p->info);
    }
}

Lista_02* busca (Lista_02* inicio_da_lst, int valor)
{
   Lista_02* p;

    for(p=inicio_da_lst; p!=NULL; p = p->prox)
    {
        if(p->info == valor)
        {
            return p;
        }      
    } 
    return NULL;
}
  
/* funcao vazia: retorna 1 se a lista_02 ta vazia ou 0 se nao ta vazia */
int lst_vazia(Lista_02* inicio_da_lst)
{
    return (inicio_da_lst == NULL);
}

Lista_02* retirar_da_lista(Lista_02* inicio_da_lst, int valor)
{
    Lista_02* p = inicio_da_lst; /*ponteiro pro começo da lista_02, para percorre-la*/

    /*O Elemento esta na lista_02?*/
    p = busca(inicio_da_lst, valor);

    /* Passamos a lista toda e o valor nao foi encontrado */
    /* Entao o p so pode estar apontando pra NULL*/
    if(p == NULL)
    {
        return inicio_da_lst; //retorna a lista original
    }
   
    /* O Elemento esta no inicio da lista*/
    /* No while acima, o p == valor procurado, entao caimos aqui */
    if(inicio_da_lst == p)
    {
        /* o inicio da lista agora aponta pro
        prox elemento referente aquele que estamos procurando */
        inicio_da_lst = p->prox;
    }
    /*O elemento esta no meio da lista, pra isso
      ajustamos os ponteiros do prox pra apontar pro anterior do p
      e o anterior do p para apontar pro proximo do p*/
    else
    {
        /*O ponteiro para o prox do anterior do p aponta para o próximo do p*/
        p->anterior->prox = p->prox; 
    }
    if(p->prox != NULL)
    {
        /*O ponteiro para anterior do prox do p aponta para o anterior do p*/
        p->prox->anterior = p->anterior;
    }
    free(p); //Elimina o elemento
    return inicio_da_lst;
}

int main()
{
    Lista_02* inicio_da_lst; //Declara uma lista_02 não iniciada /*lst = lista1*/

    int opcao, valor, valor_procurado, valor_pra_retirar, vazia;


    do {
        printf("\n 0 - Sair\n 1 - Criar Lista\n 2 - Inserir\n 3 - Busca\n 4 - Imprimir\n 5 - Verificar se vazia\n 6 - Remover um elemento\n\n");
        scanf("%d",&opcao);
        fflush(stdin);

            switch(opcao)
            {
                case 1 :
                    inicio_da_lst = cria_lista(); //Cria e começa lista vazia
                    printf("\nLista criada com sucesso.\n");
                    break;

                case 2 :
                    printf("Digite o valor para inserir\n\n");
                    fflush(stdin);
                    scanf("%d",&valor);

                    /* inicio_da_lst é um ponteiro, logo ele ta apontando pra um novo nó */
                    inicio_da_lst = insere_lista(inicio_da_lst, valor);
                    /*inicio_da_lst esta recebendo o novo nó
                    valor, e apontando pro valor */

                    printf("\nValor inserido\n");
                    break;
                case 3 :       
                    printf("\n\nDigite o valor procurado\n");
                    fflush(stdin);
                    scanf("%d",&valor_procurado);
                    fflush(stdin);
                    Lista_02* achou = busca(inicio_da_lst,valor_procurado);

                    if(achou  != NULL)
                    {
                        printf("\nO valor foi encontrado!\n\n");
                        break;   
                    }
                    else
                    {
                        printf("\nNao achou\n");
                        break;
                    }
                   
                case 4 :
                    printf("\n --- A lista eh: ---\n");
                    imprime_lista(inicio_da_lst);
                    break;
               
                case 5 :
                vazia = lst_vazia(inicio_da_lst);
                if(vazia == 1)
                {
                    printf("\n A lista esta vazia \n");
                    break;
                }
                else
                {
                    printf("\n a lista tem elementos\n");
                    break;
                }

                case 6:
                printf("\nInsira o valor a ser retirado\n\n");
                scanf("%d",&valor_pra_retirar);
                achou = busca(inicio_da_lst,valor_pra_retirar);

               
                    if(achou != NULL)
                    {
                        retirar_da_lista(inicio_da_lst, valor_pra_retirar);
                        printf("\nValor retirado com sucesso!\n");
                        break;   
                    }
                    else
                    {
                        printf("\nNao achei esse elemento\n");
                        break;
                    }

            }
           
    }while(opcao != 0);


    return 0;
}
