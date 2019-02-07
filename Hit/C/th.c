#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int x = 0;


void *t(void *name){
	int hit = 0;
	while(1){
		int w = rand() % 10;
		usleep(w * 1000);

		pthread_mutex_lock(&mutex);
		if(x > 500) break;
		else {
			x++;
			hit++;
		}
		pthread_mutex_unlock(&mutex);
	}
	printf("%s -> %d\n", (char*)name, hit);
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}



int main(int argc, char **argv){
	srand(time(NULL));

	pthread_t ptA, ptB;

	pthread_create(&ptA, NULL, (void*)&t, (void*)"A");
	pthread_create(&ptB, NULL, (void*)&t, (void*)"B");

	pthread_join(ptA, NULL);
	pthread_join(ptB, NULL);
	
}