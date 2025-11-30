#include <stdio.h>
#include <string.h>
#include <ctype.h>


int traduce_Hexa(char* arg){
	int hex=0;
	int init=0;
	if(arg[0]=='0' && (arg[1]=='X' || arg[1]=='x')){
		init = 2;
	}
	for(int i = init; i<strlen(arg);i++){
		char c = toupper(arg[i]);
		int digito;

		if(c>='0' && c<='9'){
			digito = c - '0';
		}else if(c>='A' && c<='F'){
			digito = c -'A' + 10;
		}else{
			printf("Error\n");
		}
		hex = (hex * 16) + digito;
	}
	return hex;
} 

int traduce_Bi(char* arg){
	int bi=0;
	for(int i=0; i<strlen(arg); i++){
		int digito = arg[i] - '0';
		bi = (bi*2)+digito;
	}
	return bi;
}

int main(){
	int aux = traduce_Hexa("0x1AE");
	int aux2 =traduce_Bi("11010100");
	printf("%d\n", aux);
	printf("%d\n",aux2);
	return 0;
}
