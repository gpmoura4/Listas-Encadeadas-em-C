#include <stdio.h>
#include <stdlib.h>

/*Precisamos de struct, pq no Elemento da Lista, temos duas informacoes 
o conteudo, e o ponteiro pro proximo elemento*/
struct lista { 
    int info;   //conteudo
    struct lista *prox; //ponteiro do tipo da struct para o prox elemtno
};typedef struct lista Lista;
   
//  Lista* n = NULL;
Lista* cria_lista (void)
{ 
    return NULL;    
}

Lista* insere_lista(Lista* inicio_da_lst, int valor)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));//Alocando memoria para receber o elemento
    novo->info = valor; //Passando o valor usado como parâmetro
    novo->prox = inicio_da_lst; //Inserção no inicio
    return novo; //ponteiro para o proximo elemento
   
    /*Exemplo: lst = insere_lista(inicio_da_lst, 23)
    -Inserindo o valor 23 na lista
    -Primeiramente a lista estava vazia, mas agora o 23 foi incluido
    -E o 23 agora, está apontando pra NULL (novo->prox= inicio_da_lst)
    -Sendo que o inicio_da_lst aponta pra NULL
   
    -E se depois inserirmos o valor 45
    -o novo->info vai adicionar o valor 45
    -Depois disso ele vai apontar pro próximo elemento da lst
    -O prox elemento é o 23, então ele vai apontar pra ele
    */
}

void imprime_lista (Lista* inicio_da_lst)
{
    Lista* p;
    for(p=inicio_da_lst; p!=NULL; p = p->prox)
    {
        printf("\n Elemento = %d\n",p->info);
    }
}

Lista* busca (Lista* inicio_da_lst, int valor)
{
   Lista* p; 

    for(p=inicio_da_lst; p!=NULL; p = p->prox)
    {
        if(p->info == valor)
        {
            return p;
        }       
    }  
    return NULL;
}
   
/* funcao vazia: retorna 1 se a lista ta vazia ou 0 se nao ta vazia */
int lst_vazia(Lista* inicio_da_lst)
{
    if(inicio_da_lst == NULL)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
    //return (inicio_da_lst == NULL);
}

Lista* retirar_da_lista(Lista* inicio_da_lst, int valor)
{
    Lista* p = inicio_da_lst; /*ponteiro pro começo da lista, para percorre-la*/
    Lista* anterior = NULL; /*ponteiro pro elemento anterior*/

    /*O Elemento esta na lista?*/
    while(p != NULL && p->info != valor)
    {
        anterior = p; //anterior guarda o elemento que acabamos de passar
        p = p->prox; //p vai para o prox elemento
    }

    /* Passamos a lista toda e o valor nao foi encontrado */
    /* Entao o p so pode estar apontando pra NULL*/
    if(p == NULL)
    {
        return inicio_da_lst; //retorna a lista original
    }
    
    /* O Elemento esta no inicio da lista*/
    /* No while acima, o p == valor procurado, entao caimos aqui */
    if(anterior == NULL)
    {
        /* o inicio da lista agora aponta pro 
        prox elemento referente aquele que estamos procurando */
        inicio_da_lst = p->prox; //retira elemento do inicio da lista
    }
    else
    {
        anterior->prox = p->prox;
    }
    free(p); //Elimina o elemento 
    return inicio_da_lst;
}

void destroi_lista(Lista* inicio_da_lst)
{
    Lista* p = inicio_da_lst;

    while(p != NULL)
    {
        Lista* t = p->prox; // Guarda a referencia pro prox elemento 
        free(p);            //  libera a memoria apontada por p 
        p = t;              //   faz o p apontar pro proximo elemento
    }
}

Lista* inserir_ordenado(Lista* inicio_da_lst, int valor)
{
    Lista* novo;
    Lista* anterior = NULL;
    Lista* p = inicio_da_lst;

    /// o valor eh menor do que o que ta no p->info?
    while(p != NULL && p->info < valor)
    {
        anterior = p;
        p = p->prox;
    }

    novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    
    if(anterior== NULL)//O elemento vai ser inserido no começo da lista
    {
        novo->prox = inicio_da_lst;
        inicio_da_lst = novo;
    }
    
    else //O elemento vai ser inserido no meio da lista
    {
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
    return inicio_da_lst;

}



int main()
{
    Lista* inicio_da_lst; //Declara uma lista não iniciada /*lst = lista1*/

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
                    printf("\nValor inserido\n");
                    /*inicio_da_lst esta recebendo o novo nó
                    valor, e apontando pro valor */
                    break;
                case 3 :        
                    printf("\n\nDigite o valor procurado\n");
                    fflush(stdin);
                    scanf("%d",&valor_procurado);
                    fflush(stdin);
                    Lista* achou = busca(inicio_da_lst,valor_procurado);

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
