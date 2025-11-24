#import <stdio.h>
#import <stdint.h>
#include <pthread.h>
#include <barrera.h>
#define NUM_HEBRAS 5


int main(void* arg){
	pthread_t hebras[NUM_HEBRAS];
	for(int i=0; i<NUM_HEBRAS;i++){
		pthread_create(hebras[i], NULL, /**/, NULL);
	}
	return 0;
}