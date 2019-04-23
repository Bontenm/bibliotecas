#ifndef interface_h
#define interface_h

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "horario.h"
#include "aeroporto.h"
#include "aviao.h"

int opcao;
voo *new_voo;

int retorno(voo *a){
	voo *aux = a;
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	printf("_____BEM  VINDO_____\n");
	printf("[1] Terminais de voo\n");
	printf("[2] Inserir novo Voo\n");
	printf("[3] Sair do programa\n");
	printf("\nO que deseja fazer ?\n");
	printf("_ ");
	scanf("%d", &opcao);

	while(opcao != 1 && opcao != 2 && opcao != 3){
		retorno(aux);
	}

	
	
	if(opcao == 3) {
		system("cls");
		free(aux);
		return 0;
	}
}

int segundo_painel(voo *a){
	system("cls");
	voo *aux = a;
	printf("_____BEM  VINDO_____\n");
	printf("[1] Terminais de voo\n");
	printf("[2] Inserir novo Voo\n");
	printf("[3] editar voo\n");
	printf("[4] Sair do programa\n");
	printf("\nO que deseja fazer ?\n");
	printf("_ ");
	scanf("%d", &opcao);

	while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
		segundo_painel(aux);
	}

	if(opcao == 1) {
		printa_Voo(aux);
		printf("deseja retornar ?\n");
		printf("[1] sim\n");
		printf("[2] nao\n");
		printf("_ ");
		scanf("%d", &opcao);
		
		while(opcao == 1){
			retorno(aux);
			printf("\n_ ");
			scanf("%d", &opcao);
		}
	}

	if(opcao == 2) {
		new_voo = inserir_aeroporto(aux);
		segundo_painel(aux);
	}

	if(opcao == 3){
		system("cls");
		printf("_____O que Deseja Alterar_____\n");
		printf("[1] Alterar Informações do Voo\n");
		printf("[2] Alterar Informações da Nave\n");
		printf("_ ");
		scanf("%d", &opcao);

		while(opcao != 1 && opcao != 2){
			printf("_ ");
			scanf("%d", &opcao);
		}
		
		if(opcao == 1) {
			char str[100];
			system("cls");
			printf("__qual voo deseja alterar__\n");
			printa_prefix(a);
			printf("_ ");
			scanf("%[^\n]%*c", str);
			alterar_aeroporto(a, str);
		}else

		if(opcao == 2) {
			system("cls");
			printf("__qual aeronave deseja alterar__\n");

		}
	}

	if(opcao == 4){
		free(aux);
		return 0;
	}
}

int ver_opcao(int x,voo *a){
	if(x == 1) {
		system("cls");
		new_voo = inserir_aeroporto(a);
		segundo_painel(a);
	}
	
	if(x == 2) {
		system("cls");
		return 0;
	}
}

void interface_Opcao(){
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	//tempo_real();
	printf("_____BEM  VINDO_____\n");
	printf("[1] Inserir novo Voo\n");
	printf("[2] Sair do programa\n");
	printf("\nO que deseja fazer ?\n");
	printf("_ ");
	scanf("%d", &opcao);
		while(opcao != 1 && opcao != 2){
			interface_Opcao();
		}

	ver_opcao(opcao, new_voo);
}

#endif