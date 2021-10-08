#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int Thread_Count;

void *Hello_World(void*rank) {
	long my_rank = (long) rank;
	
	printf("Hello from thread %d of %d!\n", my_rank, Thread_Count);
	pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
	long i;
	
	pthread_t* Threads;
	Thread_Count = strtol(argv[1], NULL, 10);

	Threads = malloc(Thread_Count * sizeof(pthread_t));
	
	for(i = 0; i < Thread_Count; i++) {
		pthread_create(&Threads[1], NULL, Hello_World, (void*)i);
	}

	printf("Hello from the main thread!\n");
	for(i = 0; i < Thread_Count; i++) {
		pthread_join(Threads[i], NULL);
	}

	free(Threads);
	return 0;
}
