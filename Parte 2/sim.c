#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "funcion.c"

int lee_direccionV(char* arg, int page_size, int* npv, int* offset){
	long int valor;
	
	//Caso de que sea hexadecimal
	if(arg[0]=='0' && (arg[1]=='x' || arg[1] == 'X')){
		valor = traduce_Hexa(arg);
	}else{
		// Caso de que sea binario
		valor = traduce_Bi(arg);
	}

	int b = (int)(log(page_size) / log(2.0));
	int Mask = create_Mask(page_size);

	*offset = valor & Mask;
	*npv = valor >> b;
	return valor;
}



