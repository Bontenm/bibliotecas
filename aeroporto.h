#ifndef aeroporto_h
#define aeroporto_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _no{
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
}aeroporto;

int _vazia (aeroporto *a){
    return (a == NULL);
}

void ver_horario(int *HoraP, int *MinP, int *HoraC, int *MinC){
    int aux1, aux2, aux3, aux4;
    aux1 = *HoraP;
    aux2 = *MinP;
    aux3 = *HoraC;
    aux4 = *MinC;

    while((aux1<0 || aux1>23) || (aux2<0 || aux2>59)){
        printf("Horario de saida invalido, insira outro:\n");
        scanf("%d%*c%d", &aux1, &aux2);
    }

    while((aux3<0 || aux3>23) || (aux4<0 || aux4>59)){
        printf("Horario de chegada invalido, insira outro:\n");
        scanf("%d%*c%d", &aux3, &aux4);
    }

    *HoraP = aux1;
    *MinP = aux2;
    *HoraC = aux3;
    *HoraP = aux4;
}

void tempo_voo(int HoraDu, int MinDu, int HoraP, int MinP, int HoraC, int MinC){
	int auxHora, auxMin;

	if(MinP + MinC > 59){
		HoraDu++;
		auxMin = MinP + MinC;
		auxMin %= 60;
	}

	auxHora = HoraP + HoraC;
	HoraDu = auxHora;
	MinDu = auxMin;
}

void valida_Sigla(char a[]){
	int i,j;
	char auxS[3];
	
	for(i = 0, j = 0; i < strlen(a); i++){
		if(isalpha(a[i])){
			
			if(islower(a[i])){
				a[i] = toupper(a[i]);
				j++;
			}

			if(isupper(a[i])){
				j++;
			}
		}

		else if(isdigit(a[i])){
			system("cls");
			printf("Sigla Invalida, Sigla Apenas com Letras: \n");
			printf("Por Favor Coloque Novamente: \n");
			printf("_ ");
			fflush(stdin);
			scanf("%[^\n]%*c", &auxS);
			valida_Sigla(auxS);
		}
	}

	if(j > 3){
		system("cls");
		printf("Sigla Invalida, Sigla Apenas com Letras: \n");
		printf("Por Favor Coloque Novamente: \n");
		printf("_ ");
		scanf("%[^\n]%*c", &auxS);
		fflush(stdin);
		valida_Sigla(auxS);
	}

	strcpy(a, "");
	
	for(i = 0; i < 3; i++){
		a[i] = auxS[i];
	}
	
	a[strlen(auxS)+1] = '\0';
}

void compara_Aeroporto(char a[], char b[]){
	int i;
	char auxA[100], auxB[100];
	char siglaDestino[3], siglaOrigem[3];

	if(strcmp(a,b) == 0){
		system("cls");
		printf("Aeroportos Iguais, por favor coloque outros: \n\n");
		
		printf("Inserir Aeroporto de Origem: \n");
   		printf("_ ");
   		scanf("%[^\n]%*c", auxA);

   		system("cls");
	   	printf("Sigla (apenas 3 Digitos e Maiusculo): \n");
   		printf("_ ");
   		fflush(stdin);
   		scanf("%[^\n]%*c", siglaOrigem);
   		valida_Sigla(siglaOrigem);

   		system("cls");
   		printf("Inserir Aeroporto de Destino: \n");
   		printf("_ ");
   		scanf("%[^\n]%*c", auxB);
   		compara_Aeroporto(auxA, auxB);

   		system("cls");
 	  	printf("Sigla (Apenas 3 Digitos e Maiusculo): \n");
   		printf("_ ");
   		fflush(stdin);
   		scanf("%[^\n]%*c", siglaDestino);
   		valida_Sigla(siglaDestino);
	}
	
	strcpy(a, "");
	for(i = 0; i < strlen(auxA); i++){
		a[i] = auxA[i];
	}
	a[strlen(a)+1] = '\0';

	strcpy(b, "");
	for(i = 0; i < strlen(auxA); i++){
		b[i] = auxB[i];
	}
	b[strlen(b)+1] = '\0';
}

aeroporto * cadastra_porto(aeroporto *a){
   	int i;
   	int horaPartida, minutoPartida;
   	int horaChegada, minutoChegada;
   	int horaDuracaoVoo, minDuracaoVoo;
   	char aeroOrigem[100], siglaOrigem[3];
   	char aeroDestino[100], siglaDestino[3];

   	system("cls");
   	printf("Inserir Aeroporto de Origem: \n");
   	printf("_ ");
   	fflush(stdin);
   	scanf("%[^\n]%*c", aeroOrigem);
   
   	system("cls");
   	printf("Sigla (apenas 3 Digitos e Maiusculo): \n");
   	printf("_ ");
   	fflush(stdin);
   	scanf("%[^\n]%*c", siglaOrigem);
   	valida_Sigla(siglaOrigem);

   	system("cls");
   	printf("Inserir Aeroporto de Destino: \n");
   	printf("_ ");
   	fflush(stdin);
   	scanf("%[^\n]%*c", aeroDestino);
   
   	system("cls");
   	printf("Sigla (Apenas 3 Digitos e Maiusculo): \n");
   	printf("_ ");
   	fflush(stdin);
   	scanf("%[^\n]%*c", siglaDestino);
   	valida_Sigla(siglaDestino);

   	//compara_Aeroporto(aeroOrigem, aeroDestino);
   	fflush(stdin);

   	for(i = 0; i < strlen(aeroOrigem); i++){
   		a->_aeroOrigem[i] == aeroOrigem[i];
   	}
   	a->_aeroOrigem[strlen(aeroOrigem)+1] = '\0';

   	for(i = 0; i < strlen(aeroDestino); i++){
   		a->_aeroDestino[i] == aeroDestino[i];
   	}
   	a->_aeroDestino[strlen(aeroDestino)+1] = '\0';

   	system("cls");
   	printf("Insira o Horario de Partida: \n");
   	printf("_ ");
   	scanf("%d%*c%d", &horaPartida, &minutoPartida);

   	system("cls");
   	printf("Insira o Horario de chegada: \n");
   	printf("_ ");
   	scanf("%d%*c%d", &horaChegada, &minutoChegada);

   	ver_horario(&horaPartida, &minutoPartida, &horaChegada, &minutoChegada);
   		
   	a->_horaPartida = horaPartida;
   	a->_minutoPartida = minutoPartida;
   	a->_horaChegada = horaChegada;
   	a->_minutoChegada = minutoChegada;

   	tempo_voo(horaDuracaoVoo, minDuracaoVoo, horaPartida, horaChegada, minutoPartida, minutoChegada);

   	a->_horaDuracaoVoo = horaDuracaoVoo;
   	a->_minDuracaoVoo = minDuracaoVoo;

    return a;
}

aeroporto * inserir_aeroporto(aeroporto *a){
    if(_vazia(a) == 1){
        a = (aeroporto *)malloc(sizeof(aeroporto));
        a = cadastra_porto(a);
        a->prox = NULL;
        return a;
    }
    a->prox = inserir_aeroporto(a->prox);
}
#endif