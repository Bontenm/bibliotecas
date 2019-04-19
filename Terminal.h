#ifndef Terminal_h
#define Terminal_h
#define MAX 100

#include <stdio.h>
#include <string.h>
#include <windows.h>

int choice;

void horarios_chegada(){
	printf("_chegada_\t_origem_\t\t_companhia_\t_voo_\t  _terminal_\t_tempo estimado_\t_observacoes_\n");

}

void horarios_partida(){
	printf("_partida_\t_origem_\t\t_companhia_\t_voo_\t  _terminal_\t_tempo estimado_\t_observacoes_\n");

}

void interface_primaria(){

	system("cls");
	printf("      o que deseja \n");
	printf("________________________\n");
	printf("[1]  horarios de chegada \n");
	printf("[2]  horarios de partida\n\n");
	printf("_ ");
	scanf("%d", &choice);

	if(choice == 1){
		system("cls");
		horarios_chegada();
	}
	else
	if(choice == 2){
		system("cls");
		horarios_partida();
	}
}

#endif