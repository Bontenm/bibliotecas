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

void segundo_painel(voo *a){
	system("cls");
	printf("_____BEM  VINDO_____\n");
	printf("[1] Terminais de voo\n");
	printf("[2] Inserir novo Voo\n");
	printf("[3] editar voo\n");
	printf("[4] Sair do programa\n");
	printf("\nO que deseja fazer ?\n");
	printf("_ ");
	scanf("%d", &opcao);

	if(opcao == 1){
		system("cls");
		printaVoo(a);
	}

	if(opcao == 2) {
		system("cls");
		new_voo = inserir_aeroporto(new_voo);
		segundo_painel(new_voo);
	}

	if(opcao == 3){
		system("cls");
		printf("_____O que Deseja Alterar_____\n");
		printf("[1] Alterar Informações do Voo\n");
		printf("[2] Alterar Informações da Nave\n");
		printf("_ ");
		scanf("%d", &opcao);
		
		if(opcao == 1) {
			system("cls");
			printf("__qual voo deseja alterar__\n");
			printa_Voo(a);
		}
	}
}


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

	if(opcao == 1) {
		printaVoo(a);
	}

	if(opcao == 2) {
		new_voo = inserir_aeroporto(new_voo);
		segundo_painel(new_voo);
	}
	
	if(opcao == 3) {
		system("cls");
		return 0;
	}
}

int ver_opcao(int x,voo *a){
	if(x == 1) {
		system("cls");
		new_voo = inserir_aeroporto(a);
		retorno(a);
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
	ver_opcao(opcao, new_voo);
}

#endif