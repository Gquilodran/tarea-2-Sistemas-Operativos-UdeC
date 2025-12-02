/*Este archivo solamente sera un conjunto de funciones que se usaran
en los distintos archivos.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

//Traduce un str de un numero Hexadecimal a Decimal int
long int traduce_Hexa(char* arg){
	long int hex=0;
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
//Nota: al momento de hacer el codigo, lei binario en vez de decimal. por eso esta funcion
int traduce_Bi(char* arg){
	int bi=0;
	for(int i=0; i<strlen(arg); i++){
		int digito = arg[i] - '0';
		if(digito !=0 && digito !=1){
			printf("Error\n");
			return -1;
		}
		bi = (bi*2)+digito;
	}
	return bi;
}

//Crea una mascara
int create_Mask(int page_size){
	int mask = page_size - 1;
	return mask;
}

long int lee_direccionV(char* arg, int page_size, int* npv_out, int* offset_out){
	long int valor_dv;

	if(strlen(arg)>2 && arg[0]=='0' && (arg[1]=='X' || arg[1]=='x')){
		valor_dv = traduce_Hexa(arg);
	}else{
		valor_dv=strtol(arg, NULL, 10);
	}

	if(valor_dv<0){
		return -1;
	}

	// Verificar que page_size es potencia de 2
	if (page_size <= 0 || (page_size & (page_size - 1)) != 0){
		return -1;
	}

	//double b_val=log2((double)page_size);
	//int b=(int)round(b_val);

	//if((1<<b)-1 != page_size){
	//	return -1;
	//}

	int b = 0;
	while ((1 << b) < page_size) b++;

	int Mask= create_Mask(page_size);

	int offset= valor_dv & Mask;
	int npv= valor_dv >> b;
	
	*npv_out=npv;
	*offset_out=offset;
	return valor_dv;
}



