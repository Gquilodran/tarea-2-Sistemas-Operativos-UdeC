#import <stdio.h>
#import <stdint.h>

struct base{
	int n;
	int count;
	int etapa;
	pthread_cond_t count;
	pthread_mutex_t mutex;	
};

void init(int nHilos){
	count = 0;
	etapa = 0;
	N = nhilos;
	mutex_init;
	cont_init;
}