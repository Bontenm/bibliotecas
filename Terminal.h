#ifndef Terminal_h
#define Terminal_h
#define MAX 100

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "aeroporto.h"
#include "aviao.h"

int choice;

void horarios_terminal(voo *a){
	printaVoo(a);
}

void interface_terminal(){
	
}

#endif