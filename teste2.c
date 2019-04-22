#include <stdio.h>
#include <string.h>
#include <ctype.h>

void troca_coisa(char a[], char b[]){
	char auxA[50], auxB[50];

	if(strcmp(a,b) == 0){
		printf("iguais\n");
		
		scanf("%[^\n]%*c", auxA);
		scanf("%[^\n]%*c", auxB);
	} else 
		troca_coisa(auxA,auxB);
		strcpy(a, auxA);
		printf("a = %s\n", a);
		strcpy(b, auxB);
		printf("b = %s\n", b);
}

int main(){
	char str[10];
	char str2[10];

	scanf("%[^\n]%*c", str);
	scanf("%[^\n]%*c", str2);

	troca_coisa(str, str2);
	printf("str = %s\n", str);
	printf("str2 = %s\n", str2);
	
	return 0;
}