/*Este archivo solamente sera un conjunto de funciones que se usaran
en los distintos archivos.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Traduce un str de un numero Hexadecimal a Decimal int
int traduce_Hexa(char* arg){
	int hex=0;
	int init=0;
	int largo = strlen(arg);
	if(arg[0]=='0' && (arg[1]=='X' || arg[1]=='x')){
		init = 2;
	}
	for(int i = init; i<largo;i++){
		char c = toupper(arg[i]);
		int digito;

		if(c>='0' && c<='9'){
			digito = c - '0';
		}else if(c>='A' && c<='F'){
			digito = c -'A' + 10;
		}else{
			printf("Error\n");
			return 1;
		}
		hex = (hex * 16) + digito;
	}
	return hex;
} 

//Convierte un str de un Binario a un Decimal int
int traduce_Bi(char* arg){
	int bi=0;
	for(int i=0; i<strlen(arg); i++){
		int digito = arg[i] - '0';
		bi = (bi*2)+digito;
	}
	return bi;
}

//Crea una mascara
int create_Mask(int page_size){
	int mask = page_size - 1;
	return mask;
}





