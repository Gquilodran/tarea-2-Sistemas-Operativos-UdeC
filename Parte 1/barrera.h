#ifndef BARRERA_H
#define BARRERA_H
#include <pthread.h>

typedef struct{
	int n; //numero total de hebras en espera
	int count; //numero de hebras que han llegado a la barrera
	int etapa; //etapa donde operan N hebras
	pthread_cond_t cond;  
	pthread_mutex_t mutex;	
} barrera_t;

void barrera_init(barrera_t* b, int N);
void barrera_wait(barrera_t* b);
void barrera_destroy(barrera_t* b);

#endif