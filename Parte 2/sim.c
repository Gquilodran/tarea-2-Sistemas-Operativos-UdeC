#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "funcion.c"

int lee_direccionV(char* arg, int page_size){
	int valor;
	//Caso de que sea hexadecimal
	if(arg[0]=='0' && arg[1]=="x"){
		valor = traduce_Hexa(arg);
	}else{
		valor = traduce_Bi(arg);
	}
	double b = log((double)page_size)/log(2.0);
	b = (int)b;
	int Mask = create_Mask(page_size);
	int offset = valor & Mask;
	int nvp = valor >> b;
	return nvp,offset;
}



