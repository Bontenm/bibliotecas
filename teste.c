#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "aeroporto.h"

voo * new_porto;

int main(){
	new_porto = inserir_aeroporto(new_porto);
	printa_Voo(new_porto);
	
	return 0;
}