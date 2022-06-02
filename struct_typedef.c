#include <stdio.h>

int main () {

    struct ficha_aluno
    {
        char nome[40];
        int numero;
        float nota1, nota2; 
    };
    typedef struct ficha_aluno ficha_aluno; //Estamos mudando a defininção da Struct, para encurtar a declaração 
    ficha_aluno aluno; //variável aluno do tipo ficha_aluno (Usando o typedef podemos colocar só ""ficha_aluno aluno""")
    typedef float nota;

    float media=0;

    printf("Informe o nome\n\n");
    fgets(aluno.nome,40,stdin);

    printf("\nInsira nota1\n");
    scanf("%f",&aluno.nota1);
    printf("\nInsira nota2\n");
    scanf("%f",&aluno.nota2);

    printf("\n\n%s\n\n",aluno.nome);
    media = (aluno.nota1 + aluno.nota2)/2;
    printf("%f",media);

    return 0;
}

 