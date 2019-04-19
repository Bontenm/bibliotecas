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
}aeronave; 

int vazia (aeronave *a){
    return (a == NULL);
}

aeronave * cadastra_aero(aeronave *a){
    system("cls");
    printf("Insira o Modelo da Aeronave: \n");
    printf("_ \n");
    scanf(" %[^\n]%*c",a->modelo);
    fflush(stdin);

    printf("Insira o Comprimento da Mesma: \n");
    printf("_ \n");
    scanf("%lf",&a->comprimento);
    fflush(stdin);

    printf("Insira sua Altura: \n");
    printf("_ \n");
    scanf("%lf",&a->altura);
    fflush(stdin);

    printf("Insira sua Envergadura\n");
    printf("_ \n");
    scanf("%lf",&a->envergadura);
    fflush(stdin);

    printf("Insira o Alcance que a Nave Chega: \n");
    printf("_ \n");
    scanf("%lf",&a->alcance_maximo);
    fflush(stdin);

    printf("Insira sua Velocidade de Cruzeiro: \n");
    printf("_ \n");
    scanf("%lf",&a->velociade_do_cruzeiro);
    fflush(stdin);

    printf("Insira a Quantidade de Acentos: \n");
    printf("_ \n");
    scanf("%d",&a->quantidade_de_acentos);
    fflush(stdin);

    printf("Insira a Quantidade de Banheiros: \n");
    printf("_ \n");
    scanf("%d ",&a->quantidade_de_banheiros);
    fflush(stdin);
    return a;
}

aeronave * inserir_aeronave(aeronave *a){
    if(vazia(a) == 1){
        a = (aeronave *)malloc(sizeof(aeronave));
        a = cadastra_aero(a);
        a->prox = NULL;
        return a;
    }
    a->prox = inserir_aeronave(a->prox);
}

aeronave * alterar_aeronave(aeronave *a,char str[]){
    aeronave *aux = a;
    if(strcmp(a->modelo,str) == 0){
        a = cadastra_aero(a);
        return a;
    } else{
        for( ; !vazia(aux) ; aux = aux->prox){
            if(strcmp(aux->modelo,str)==0){
                cadastra_aero(aux);
                break;
            }
        }
    }
    return a;
}

aeronave * excluir_aeronave(aeronave *a,char str[]){
    aeronave * corredor = a,*aux;
    if(strcmp(corredor->modelo,str) == 0){
        aux = corredor->prox;
        free(corredor);
        return aux;
    }
    for( ; vazia(corredor->prox) == 0 ; corredor=corredor->prox){
        if(strcmp(corredor->prox->modelo,str) == 0) break;
    }
    if(corredor->prox){
        aux = corredor->prox->prox;
        free(corredor->prox);
        corredor->prox = aux;
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