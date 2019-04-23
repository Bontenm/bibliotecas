#ifndef aeroporto_h
#define aeroporto_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aviao.h"

aeronave *new_aeronave; // deixa um ponteiro para a aeronave

typedef struct _no{
	char _prefixo[100];
	char _aeroOrigem[100];
	char _aeroDestino[100];
	char _siglaOrigem[3];
	char _siglaDestino[3];
	int _horaChegada;
	int _minutoChegada;
	int _horaPartida;
	int _minutoPartida;
	int _horaDuracaoVoo;
	int _minDuracaoVoo;
	struct _no *prox;
}voo; // struct com informações de voo

int _vazia (voo *a){
    return (a == NULL); // verifica se a lista é vazia
}

void ver_horario(int *HoraP, int *MinP, int *HoraC, int *MinC){
    int aux1, aux2, aux3, aux4; // auxiliares de parametro
    aux1 = *HoraP; 
    aux2 = *MinP;
    aux3 = *HoraC;
    aux4 = *MinC;

    while((aux1<0 || aux1>23) || (aux2<0 || aux2>59)){ // ve se o horario é correto e aceitavel
        printf("Horario de saida invalido, insira outro:\n");
        scanf("%d%*c%d", &aux1, &aux2); // troca o valor das variaveis auxiliares
    }

    while((aux3<0 || aux3>23) || (aux4<0 || aux4>59)){ // ve se o horario é correto e aceitavel
        printf("Horario de chegada invalido, insira outro:\n");
        scanf("%d%*c%d", &aux3, &aux4); // troca o valor das variaveis auxiliares
    }

    *HoraP = aux1; // muda o valor das variaveis originais
    *MinP = aux2;
    *HoraC = aux3;
    *HoraP = aux4;
}

void tempo_voo(int HoraDu, int MinDu, int HoraP, int MinP, int HoraC, int MinC){
	int auxHora, auxMin; // auxiliares de parametro

	if(MinP + MinC > 59){
		HoraDu++; // aumenta a hora conforme os minutos
		auxMin = MinP + MinC;
		auxMin %= 60; // faz os minutos restantes corresponderem de acordo
	}

	auxHora = HoraP - HoraC; // da a quantidade de horas de voo 
	HoraDu = auxHora; // atualiza a variavel original
	MinDu = auxMin; // atualiza a variavel original
}

void valida_Sigla(char str[]){
	int i,j; // variaveis auxiliares
	char aux[100];

	strcpy(aux, str); // copia de segurança da variavel original
	for (i = 0, j = 0; i < strlen(str); i++) {	
		if(isalpha(str[i])) { // verifica se é uma letra

			if(islower(str[i])){ // verifica se a letra é minuscula
				str[i] = toupper(str[i]); // torna a letra minuscula maiuscula
				j++; // contador de letras no vetor
			}else

			if(isupper(str[i])){ // verifica se é maiscula
				j++; // contador de letras no vetor
			}
		} else 
		if(isdigit(str[i]) == 1) { // verifica se é um numero
			printf("sigla errada, por favor coloque novamente\n");
			scanf("%[^\n]%*c", str); // atualiza o valor do vetor
			valida_Sigla(str); // recursivamente verifica o novo valor
		}
	}
	
	if (j < 3 || j > 3) { // condição para mais de 3 letras no vetor
		printf("quantidade de letras erradas\n");
		scanf("%[^\n]%*c", str); // altera o valor do vetor original
		valida_Sigla(str); // recursivamente verifica o novo valor
	}
}

void compara_Aeroporto(char a[], char b[]){
	char auxA[100], auxB[100]; // vetores de parametro e troca de aeroporto

	while(strcmp(a,b) == 0){ // verifica se os aeroportos sao iguais
		system("cls");
		printf("Aeroportos Iguais, por favor coloque outros: \n\n");
		
		printf("Inserir Aeroporto de Origem: \n");
   		printf("_ ");
   		fflush(stdin);
   		scanf("%[^\n]%*c", auxA); // atualiza a vetor auxiliar

   		system("cls");
   		printf("Inserir Aeroporto de Destino: \n");
   		printf("_ ");
   		fflush(stdin);
   		scanf("%[^\n]%*c", auxB); // atualiza a vetor auxilia

   		compara_Aeroporto(auxA, auxB); // recursivamente verifica se os aeroportos são iguais
		strcpy(a, auxA); // muda os valores do vetor a
		strcpy(b, auxB); // muda os valores do vetor b
	} 
}

voo * cadastra_porto(voo *a){
   	setlocale(LC_ALL, "Portuguese");
   	int i;
   	int horaPartida, minutoPartida;
   	int horaChegada, minutoChegada;
   	int horaDuracaoVoo, minDuracaoVoo;
   	char aeroOrigem[100], siglaOrigem[5];
   	char aeroDestino[100], siglaDestino[5];
   	// variaveis auxiliares de comparação e atualização

   	system("cls");
   	printf("Inserir Aeroporto de Origem: \n");
   	printf("_ ");
   	fflush(stdin);
   	scanf("%[^\n]%*c", aeroOrigem); // atualiza o vetor auxilia
   
   	system("cls");
   	printf("Sigla (Apenas 3 Letras e Maiusculo): \n");
   	printf("_ ");
   	fflush(stdin);
   	scanf("%[^\n]%*c", siglaOrigem); // atualiza o vetor auxiliar
   	valida_Sigla(siglaOrigem); // verifica se a sigla é aceitavel
   	strcpy(a->_siglaOrigem, siglaOrigem);

   	system("cls");
   	printf("Inserir Aeroporto de Destino: \n");
   	printf("_ ");
   	fflush(stdin);
   	scanf("%[^\n]%*c", aeroDestino); // atualiza o vetor auxiliar
   
   	system("cls");
   	printf("Sigla (Apenas 3 Letras e Maiusculo): \n");
   	printf("_ ");
   	fflush(stdin);
   	scanf("%[^\n]%*c", siglaDestino); // atualiza o vetor auxiliar
   	valida_Sigla(siglaDestino); // verifica se a sigla é aceitavel
   	strcpy(a->_siglaDestino, siglaDestino);

   	compara_Aeroporto(aeroOrigem, aeroDestino);
   	fflush(stdin);

   	strcpy(a->_aeroOrigem, aeroOrigem);
   	strcpy(a->_aeroDestino, aeroDestino);

   	system("cls");
   	printf("insira o prefixo do voo.\n");
   	printf("** o prefixo sera usado para alteracoes no sistema **\n");
   	printf("_ ");
   	scanf("%[^\n]%*c", a->_prefixo); // armazena o prefixo do voo

   	system("cls");
   	printf("Insira o Horario de Partida: \n");
   	printf("H:M\n");
   	printf("_ ");
   	scanf("%d%*c%d", &horaPartida, &minutoPartida); // atualiza as variaveis auxiliares de hora e minuto de partida

   	system("cls");
   	printf("Insira o Horario de chegada: \n");
   	printf("H:M\n");
   	printf("_ ");
   	scanf("%d%*c%d", &horaChegada, &minutoChegada); // atualiza as variaveis auxiliares de hora e minuto de chegada

   	ver_horario(&horaPartida, &minutoPartida, &horaChegada, &minutoChegada); // verifica se os horarios são aceitaveis
   		
   	a->_horaPartida = horaPartida; // atualiza a variavel de hora de partida original
   	a->_minutoPartida = minutoPartida; // atualiza a variavel de minuto de partida original
   	a->_horaChegada = horaChegada; // atualiza a variavel de hora de chegada original
   	a->_minutoChegada = minutoChegada; // atualiza a variavel de minuto de chegada original

   	tempo_voo(horaDuracaoVoo, minDuracaoVoo, horaPartida, horaChegada, minutoPartida, minutoChegada); // faz a contagem de tempo de voo

   	a->_horaDuracaoVoo = horaDuracaoVoo; // atualiza o vetor de hora de duração de voo original
   	a->_minDuracaoVoo = minDuracaoVoo; // atualiza o vetor de minuto de duração de voo original

   	new_aeronave = inserir_aeronave(new_aeronave); // cria as informaç~

    return a; // retorna a struct com as informações feitas
}

voo * inserir_aeroporto(voo *a){
    if(_vazia(a) == 1){ // verifica se a lista é vazia
        a = (voo *)malloc(sizeof(voo));
        a = cadastra_porto(a); // cria uma nova lista
        a->prox = NULL; // aterra a lista
        return a;
    }
    a->prox = inserir_aeroporto(a->prox); // recursivamente procura uma lista vazia
}

voo * alterar_aeroporto(voo *a, char str[]){
    voo *aux = a;
    if(strcmp(a->_prefixo, str) == 0){ // verifica se é a struct desejada
        a = cadastra_porto(a); // altera as informações
        return a; // retorna a nova lista
    
    } else {
        
        for( ; !_vazia(aux) ; aux = aux->prox){ // procura a lista até achar a struct desejada
            
            if(strcmp(aux->_prefixo,str)==0){
                cadastra_porto(aux); // altera as informações
                break; // retorna a nova lista
            }
        }
    }
    return a;
}

voo * exclui_aeroporto(voo *a, char str[]){
	voo * corredor = a,*aux;
    if(strcmp(corredor->_prefixo,str) == 0){ // percorre até achar o que deseja
        aux = corredor->prox;
        free(corredor); // exclui a struct inteira
        return aux; // retorna o ponteiro anterior 
    }
    for( ; _vazia(corredor->prox) == 0 ; corredor = corredor->prox){ // ve se a lista é vazia
        if(strcmp(corredor->prox->_prefixo,str) == 0) break; // caso ache, para na lista
    }
    if(corredor->prox){
        aux = corredor->prox->prox; // marca a lista a ser excluida
        free(corredor->prox); // exclui a lista marcada
        corredor->prox = aux; // aterra o ponteiro
    }
    return a;
}

void printa_Voo(voo *a){
	voo *aux = a;
	while(!_vazia(aux) != 0) { // enquanto a lista nao for vazia
		printf("prefixo: %s\n", a->_prefixo);
		printf("de: [%s]\n", a->_aeroOrigem);
		printf("para: [%s]\n", a->_aeroDestino);
    	printf("siglas: [%s]---[%s]\n", a->_siglaOrigem, a->_siglaDestino);
    	printf("\n");
    	aux = aux->prox;
	}
}

void printa_prefix(voo *a){
	voo *aux = a;
	while(_vazia(aux) != 0){
		printf("[%s]\n", aux->_prefixo);
		aux = aux->prox;
	}
}
#endif