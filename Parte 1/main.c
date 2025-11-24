#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "barrera.h"
#include <time.h>

/*Para compilarlo se necesita el siguiente comando
  gcc main.c barrera.c -lpthread -o programa
  y luego ./programa.exe
*/


/*
Este struct sirve unicamente para pasar más de un dato que deberia tener
cada hilo. Ya que teoricamente no tienen un numero fijos de hilos ni de 
etapas.
*/
typedef struct {
	int id;
	int E;
	barrera_t* b;
} dHebra;

/*
Esta funcion genera un numero alatorio. 
*/
int nRandom(){
	int n = rand()%1000;
	return n;
}

/*
Esta funcion se encarga de simular que la hebra haga algo.
*/
void* trabajo_hebra(void* arg){
	dHebra* d = (dHebra*)arg;
	int id = d -> id;
	int Etapa = d -> E;
	barrera_t* barrera = d -> b;

	for(int i=0; i<Etapa; i++){
		usleep(nRandom());
		printf("%d esperando en etapa %d.\n", id,i);
		barrera_wait(barrera);
		printf("%d paso barrera en etapa %d.\n",id,i);
	}
	return NULL;
}


/*
Funcion principal. Aqui se pide al usuario el numero de etapas y de hebras, 
para luego ser creadas, ademas de crear un array de struct con los datos
*/
int main(int argc, char* argv[]){
	srand(time(NULL));
	int N;
	int E;
	printf("Numero de hebras y Numero de Etapas:\n");
	scanf("%d %d", &N, &E);

	barrera_t b;
	barrera_init(&b, N);

	dHebra datos[N];
	for(int i=0; i<N; i++){
		datos[i].id = i;
		datos[i].E = E;
		datos[i].b = &b;
	}

	pthread_t hebras[N];
	for(int i=0; i<N;i++){
		pthread_create(&hebras[i], NULL, trabajo_hebra, &datos[i]);
	}

	for (int i = 0; i < N; i++) {
        pthread_join(hebras[i], NULL);
    }
    barrera_destroy(&b);
	return 0;
}
