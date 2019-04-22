#ifndef aviao_h
#define aviao_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct no{
    char modelo[20];
    double comprimento;
    double altura;
    double envergadura;
    double velociade_do_cruzeiro;
    double alcance_maximo;
    int quantidade_de_acentos;
    int quantidade_de_banheiros;
    struct no *prox;
}aeronave; // struct com informação sobre o voo

int vazia (aeronave *a){
    return (a == NULL);
} //verifica se existe algo na struct

aeronave * cadastra_aero(aeronave *a){
    system("cls");
    printf("Insira o Modelo da Aeronave: \n");
    printf("_ ");
    scanf(" %[^\n]%*c", a->modelo); // armazena o modelo da nave
    fflush(stdin);

    system("cls");
    printf("Insira o Comprimento da Mesma(metros): \n");
    printf("_ ");
    fflush(stdin);
    scanf("%lf", &a->comprimento); // armazena o comprimento da nave

    system("cls");
    printf("Insira sua Altura(metros): \n");
    printf("_ ");
    fflush(stdin);
    scanf("%lf", &a->altura); // armazena a altura que a nave tem

    system("cls");
    printf("Insira sua Envergadura(metros)\n");
    printf("_ ");
    fflush(stdin);
    scanf("%lf", &a->envergadura); // armazena a envergadura da nave

    system("cls");
    printf("Insira o Alcance que a Nave Chega (metros): \n");
    printf("_ ");
    fflush(stdin);
    scanf("%lf", &a->alcance_maximo); // armazena o alcance maximo que a nave chega

    system("cls");
    printf("Insira sua Velocidade de Cruzeiro(Km/h): \n");
    printf("_ ");
    fflush(stdin);
    scanf("%lf", &a->velociade_do_cruzeiro); // armazena a sua velocidade maxima

    system("cls");
    printf("Insira a Quantidade de Acentos: \n");
    printf("_ ");
    fflush(stdin);
    scanf("%d", &a->quantidade_de_acentos); // armazena a quantidade de acentos na nave

    system("cls");
    printf("Insira a Quantidade de Banheiros: \n");
    printf("_ ");
    fflush(stdin);
    scanf("%d", &a->quantidade_de_banheiros); // armazena a quantidade de banheiros na nave
    return a;
}

aeronave * inserir_aeronave(aeronave *a){
    if(vazia(a) == 1){
        a = (aeronave *)malloc(sizeof(aeronave)); // cria uma nova struct
        a = cadastra_aero(a);
        a->prox = NULL; // sinaliza que não ha mais structs
        return a; // da o endereço da struct nova
    }
    a->prox = inserir_aeronave(a->prox); // recursivamente vai para a proxima struct
}

aeronave * alterar_aeronave(aeronave *a,char str[]){
    aeronave *aux = a;
    if(strcmp(a->modelo,str) == 0){ // verifica se é a struct desejada
        a = cadastra_aero(a);
        return a;

    } else {
        
        for( ; !vazia(aux) ; aux = aux->prox){ // percorre dentro das structs até acha o que deseja
            
            if(strcmp(aux->modelo,str)==0){
                cadastra_aero(aux);
                break;
            }
        }
    }
    return a; // retorna a struct nova
}

aeronave * excluir_aeronave(aeronave *a,char str[]){
    aeronave * corredor = a,*aux;
    if(strcmp(corredor->modelo,str) == 0){ // percorre até achar o que deseja
        aux = corredor->prox;
        free(corredor); // exclui a struct inteira
        return aux; // retorna o ponteiro anterior 
    }
    for( ; vazia(corredor->prox) == 0 ; corredor = corredor->prox){ // ve se a lista é vazia
        if(strcmp(corredor->prox->modelo,str) == 0) break; // caso ache, para na lista
    }
    if(corredor->prox){
        aux = corredor->prox->prox; // marca a lista a ser excluida
        free(corredor->prox); // exclui a lista marcada
        corredor->prox = aux; // aterra o ponteiro
    }
    return a;
}

void printaNave(aeronave *a){
    printf("%s\n",a->modelo);
    printf("%lf\n",a->comprimento);
    printf("%lf\n",a->altura);
    printf("%lf\n",a->envergadura);
    printf("%lf\n",a->alcance_maximo);
    printf("%lf\n",a->velociade_do_cruzeiro);
    printf("%d\n",a->quantidade_de_acentos);
    printf("%d\n",a->quantidade_de_banheiros);
    if(a->prox != 0) printaNave(a->prox);
}
#endif