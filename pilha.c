#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char palavra[100];
    int topo;    
}Pilha;

typedef struct no {
    Pilha p;
    struct no *proximo;
}No;

//Funcao para ler e criar a palavra
Pilha ler_char () {
    Pilha p;
    printf("\n Digite a palavra\n");
    fgets(p.palavra,100,stdin);
    fflush(stdin);
    return p;
}

void imprime_palavra(Pilha p)
{
    printf("\n A palavra eh %s",p.palavra);
}

int main (){
    
    No *topo = NULL;
    No *remover;
    int opcao;

    do {
        printf("\n 0 - Sair\n 1 - Empilhar\n 2 - Retirar\n 3 - Imprimir");
        scanf("%d",&opcao);
        getchar();

        switch(opcao)
        {
            case 1:
            topo = empilhar(topo);
            break;
            
            case 2:
            remover=desempilhar(&topo);
            if(remover)
            {
                printf("\nElemento removido\n\n");
                imprimir_pessoa(remover->p);
            }
            else
            {
                printf("\nSem remocao\n");
            }
            break;

            case 3:
            imprime_pilha(topo);
            break;
            
            default: 
            if(opcao != 0)
            {
                printf("\nERRO\n\n");
            }
        }
    }while(opcao !=0);

    return 0;
}