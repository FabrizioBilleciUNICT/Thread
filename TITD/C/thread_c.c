#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int n = 100;

void *tI(){
	int counter = 0;
	while(counter < 1000){
		counter++;
		usleep(100*1000);
		int c = rand() % 10;

		pthread_mutex_lock(&mutex);
		n += c;
		printf("tI: %d\n", n);
		if(n > 150) break;
		pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_unlock(&mutex);
}

void *tD(){
	int counter = 0;
	while(counter < 1000){
		counter++;
		usleep(300*1000);
		int c = rand() % 10;

		pthread_mutex_lock(&mutex);
		n -= c;
		printf("\t\ttD: %d\n", n);
		if(n < 80) break;
		pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_unlock(&mutex);	
}


int main(int argc, char **argv){
	srand(time(NULL));

	pthread_t thI, thD;

	pthread_create(&thI, NULL, tI, NULL);
	pthread_create(&thD, NULL, tD, NULL);

	pthread_join(thI, NULL);
	pthread_join(thD, NULL);

	return 0;
}