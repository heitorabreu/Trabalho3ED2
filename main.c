#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char nome[50];
    char curso[50];
    int RA_UNESP;
};

//Esta é uma função que preenche uma string com 128 bytes, para que possamos usar os
//registro de tamanho fixo para escrita no arquivo
//Para usar esta função, o primeiro argumento a ser passado deve ser uma struct do tipo
//aluno, e um vetor de char com 129 posições
//A função retorna uma string com 128 bytes, para que o registro possa ser escrito no arquivo
void preenche_string(struct aluno a, char string[]){
    int tam;
    sprintf(string, "%d|%s|%s|", a.RA_UNESP, a.nome, a.curso);
    tam = strlen(string);
    if(tam >128)
        return;
    while(tam < 128){
        strcat(string, "#");
        tam++;
    }
}

int main(){
    struct aluno a;
    char string[129];
    FILE *arq_dados;    
    // strcpy(a.nome, "Heitor Xavier de Abreu");
    // strcpy(a.curso, "Ciencia da Computacao");
    // a.RA_UNESP = 211040983;
    // preenche_string(a, string);
    // printf("\n%s\n", string);

    arq_dados = fopen("turma.dat", "a+");
    int op, ra;
    do{
        printf("\n\tMENU");
        printf("\n1 - Gravar Aluno");
        printf("\n2 - Buscar Aluno");
        printf("\n0 - Fechar");
        printf("\nDigite sua opção: ");
        scanf("%d ", &op);
        fflush(stdin);
        getchar();
        //scanf("%c");

        if(op == 1){
            //fflush(stdin);
            printf("\nDigite o nome do aluno: ");
            getchar();
            fgets(a.nome, 50, stdin);
            printf("\nDigite o curso do aluno: ");
            fgets(a.curso, 50, stdin);
            printf("\nDigite o RA do aluno: ");
            scanf("%d", &a.RA_UNESP);
            fflush(stdin);
            preenche_string(a, string);
            fseek(arq_dados, SEEK_END, 0);
            fprintf(arq_dados, "%s", string);
        }
        else if(op == 2){
            printf("\nDigite o RA do aluno que deseja buscar: ");
            scanf("%d", &ra);
            fflush(stdin);
        }
        else if(op == 0){

        }
        else{
            printf("\nOpção inválida.");
        }
    }while(op!=0);
    //remove(arq_dados);
    fclose(arq_dados);
}