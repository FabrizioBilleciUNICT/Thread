#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int posizione = 0;
int vittorie_tp0 = 0, vittorie_tp1 = 0;

void *tp0(){
	while(1){
		if(vittorie_tp0 >= 10 || vittorie_tp1 >= 10) break;

		int recupero = rand() % 4;
		int forza = rand() % 6;

		usleep(recupero * 1000);

		pthread_mutex_lock(&mutex);
		if(posizione >= 10){
			vittorie_tp1++;
			printf("Sono tp0. tp1 ha vinto.\n");
			posizione = 0;
			pthread_cond_signal(&cond);
		} else {
			posizione -= forza;
			if(posizione <= -10){
				pthread_cond_wait(&cond, &mutex);
			}
		}
		pthread_mutex_unlock(&mutex);

	}
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);	
}

void *tp1(){
	while(1){
		if(vittorie_tp0 >= 10 || vittorie_tp1 >= 10) break;

		int recupero = rand() % 4;
		int forza = rand() % 6;

		usleep(recupero * 1000);

		pthread_mutex_lock(&mutex);
		if(posizione <= -10){
			vittorie_tp0++;
			printf("Sono tp1. tp0 ha vinto.\n");
			posizione = 0;
			pthread_cond_signal(&cond);
		} else {
			posizione += forza;
			if(posizione >= 10){
				pthread_cond_wait(&cond, &mutex);
			}
		}
		pthread_mutex_unlock(&mutex);

	}
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);	
}

int main(int argc, char **argv){
	srand(time(NULL));

	pthread_t t0, t1;

	pthread_create(&t0, NULL, tp0, NULL);
	pthread_create(&t1, NULL, tp1, NULL);

	pthread_join(t0, NULL);
	pthread_join(t1, NULL);

	printf("Partita terminata. tp0:%d - tp1:%d\n", vittorie_tp0, vittorie_tp1);

	return 0;
}