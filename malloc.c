#include <stdio.h>
#include <stdlib.h>

struct ponto {
    int x,y;
};

int main (){
    int *v = malloc(50 * sizeof(int)); //Vetor com (50 * o tamanho do tipo INT)
    //int *v aponta para o começo do vetor

    int *p = malloc(5*sizeof(int));

    if(p==NULL)
    {
        printf("Erro!\n");
        exit(1);
    }

    int i;

    for(i=0;i<sizeof(p);i++)
    {
        printf("Coloque a posicao[%d]\n",i);
        scanf("%d",&p[i]);
    }

    for(i=0;i<sizeof(p);i++)
    {
        printf("Posicao %d p[%d] == \n\n",i,i);
    }

    free(p);


    return 0;
}
