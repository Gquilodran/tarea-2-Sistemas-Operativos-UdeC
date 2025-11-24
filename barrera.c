#include <stdio.h>
#include "barrera.h"


void barrier_init(barrera_t* b, int N){
	b->count = 0;
	b->etapa = 0;
	b->n = N;
	pthread_mutex_init(&b->mutex, NULL);
	pthread_cond_init(&b->cond, NULL);
}
void barrier_wait(barrera_t* b){
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

void barrier_destroy(barrera_t* b){
	pthread_mutex_destroy(&b->mutex);
	pthread_cond_destroy(&b->cond);
}