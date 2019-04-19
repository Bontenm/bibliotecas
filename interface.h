#ifndef interface_h
#define interface_h

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Terminal.h"
#include "horario.h"
#include "aeroporto.h"
#include "aviao.h"

int opcao;
aeroporto *new_aeroporto;
aeronave *new_aeronave;

/*void open_painel(){
	
}*/

int ver_opcao(int x){
	if(x == 1) {
		interface_primaria();
	}
	if(x == 2) {
		new_aeroporto = inserir_aeroporto(new_aeroporto);
		new_aeronave = inserir_aeronave(new_aeronave);
	}
	if(x == 3) {
		system("cls");
		return 0;
	}
}

void interface_Opcao(){
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	//tempo_real();
	printf("_____BEM  VINDO_____\n");
	printf("[1] Terminais de voo\n");
	printf("[2] Inserir novo Voo\n");
	printf("[3] Sair do programa\n");
	printf("\nO que deseja fazer ?\n");
	printf("_ ");
	scanf("%d", &opcao);
	ver_opcao(opcao);
}

#endif