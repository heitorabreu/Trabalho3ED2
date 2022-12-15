#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    char nome[50];
    char curso[50];
    int RA_UNESP;
};

char* preenche_string(struct aluno a){
    char string[128];
    sprintf(string, "%d|%s|%s|", a.RA_UNESP, a.nome, a.curso);
    // sprintf(string, "%s|", a.nome);
    // sprintf(string, "%s|", a.curso);
    int tam = strlen(string);
    while(tam < 128){
        strcat(string, "#");
        tam++;
    }
    printf("\nTam: %d\n%s", strlen(string), string);
    return string;
}

int main(){
    struct aluno a;
    strcpy(a.nome, "Heitor Xavier de Abreu");
    strcpy(a.curso, "Ciencia da Computacao");
    a.RA_UNESP = 211040983;
    char string[128];
    preenche_string(a);
    printf("\n%s", string);
}