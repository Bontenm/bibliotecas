#ifndef trab_h_
#define trab_h_

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

char escolha[20];
char acao[20];

char fim[20] = {'t','e','r','m','i','n','a','r'};
char alterar[20] = {'a','l','t','e','r','a','r'};
char inserir[20] = {'i','n','s','e','r','i','r'};
char consultar[20] = {'c','o','n','s','u','l','t','a','r'};
char excluir[20] = {'e','x','c','l','u','i','r'};

typedef struct infoPessoa{
    char *NomePrograma;
    char *NomePessoa;
    char *CPF;
    char *Categoria;
    double SaldoMilhas;
} infoPessoa;

typedef struct infoAero{
    char *aerOri;
    char siglaOri[3];
    char *aeroDest;
    char siglaDest[3];
    int *horaPartida;
    int *minutoPartida;
    int *horaChegada;
    int *minutoChegada;
    int *duracao;
} infoAero;

typedef struct infoNave{
    char *prefixo;
    char *aeronave;
} infoNave;



#endif