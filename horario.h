#ifndef horario_h
#define horario_h

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void tempo_real(){
	int segundos, minutos, horas;
	printf("__defina o tempo que voce quer_\n");
	printf("_________formato(H:M:S)________\n");
	scanf("%d%*c%d%*c%d", &horas, &minutos, &segundos);

	while(1 == 1){
		Sleep(1000);
		segundos ++;
		system("CLS");
		if(segundos > 59){
			minutos ++;
			segundos = 0;
		}
		if(minutos > 59){
			horas ++;
			minutos = 0;
		}
		if(horas > 23){
			segundos = 0;
			minutos = 0;
			horas = 0;
		}
	}
}
#endif