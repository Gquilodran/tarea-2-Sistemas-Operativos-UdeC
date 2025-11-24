#include <stdio.h>
#include "barrera.h"


/*
Esta funcion se encarga de inicializar la barrera, asignando valores a las variables
del struct y de inicializar el cond y el mutex.
*/
void barrera_init(barrera_t* b, int N){
	b->count = 0;
	b->etapa = 0;
	b->n = N;
	pthread_mutex_init(&b->mutex, NULL);
	pthread_cond_init(&b->cond, NULL);
}

/*
Esta es la funcion principal de la barrera, wait. Primero se cierra el mutex y se guardan en bariables locales
el valor de la etapa y el contador aumenta en 1.
Luego si el valor de contador de la barrera es menor que el numero de hebras representado por N, la hebra se queda en espera (se duerme).
En caso contrario, a la variable etapa de la barrera se aumenta en 1 y el contador se devuelve a 0, y con broadcast despiertan
todas las hebras que hay. Tras esto, se desbloquea el mutex. 
*/
void barrera_wait(barrera_t* b){
	pthread_mutex_lock(&b->mutex);
		int etapa_local = b->etapa;
		b->count = b->count + 1;

		if(b->count < b->n){
			while(b->etapa == etapa_local){
				pthread_cond_wait(&b->cond, &b->mutex);
			}
		}else{
			b->etapa = b->etapa + 1;
			b->count = 0;
			pthread_cond_broadcast(&b->cond);
		}
		pthread_mutex_unlock(&b->mutex);
}

/*
Esta funcion se encarga de destruir tanto el mutex, como la condicion cond. Esto es indispensable.
*/
void barrera_destroy(barrera_t* b){
	pthread_mutex_destroy(&b->mutex);
	pthread_cond_destroy(&b->cond);
}