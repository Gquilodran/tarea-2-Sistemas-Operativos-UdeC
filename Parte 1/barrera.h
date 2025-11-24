#ifndef BARRERA_H
#define BARRERA_H
#include <pthread.h>


/*
Estructura basica de la barrera, con las bariables principales. Estas son a las que todas las hebras
(que esten ligadas a la misma barrera) podran acceder.
*/
typedef struct{
	int n; //numero total de hebras
	int count; //numero de hebras que han llegado a la barrera
	int etapa; //etapa donde opera una hebra
	pthread_cond_t cond;  
	pthread_mutex_t mutex;	
} barrera_t;

/*
Aqui declaramos las funciones que tendra barrera. Si esto no se hace, el compilador dara error.
*/
void barrera_init(barrera_t* b, int N);
void barrera_wait(barrera_t* b);
void barrera_destroy(barrera_t* b);

#endif