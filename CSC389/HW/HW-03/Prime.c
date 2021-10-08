#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *getPrimes(void* maxPrime) {
	long numPrimes = (long) maxPrime;
	int primes[numPrimes];
	primes[0] = 2;
	int primeCount = 1;
	int i;
	for(i = 3; i <= numPrimes; i++) {
		int x;
		int prime = 1;
		for(x = 0; x < primeCount; x++) {
			if(i % primes[x] == 0) {
				prime = 0;
				break;
			}
		}
		if(prime == 1) {
			primes[primeCount] = i;
			primeCount++;
		}
	}
	printf("The prime numbers of a given number %d are: ", numPrimes);
	for(i = 0; i < primeCount; i++) {
		printf("%d", primes[i]);
		if(i != primeCount - 1) {
			printf(", ");
		}
	}
	printf("\n");
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	long maxNum;
	if(argc != 2) {
		printf("Invalid number of arguments supplied. Please try again.\n");
		return 1;
	}
	maxNum = strtol(argv[1], NULL, 10);
	if(maxNum < 2) {
		printf("Invalid argument supplied. Please try again.\n");
		return 1;
	}
	pthread_t* Thread;
	
	Thread = malloc(sizeof(pthread_t));
	
	pthread_create(&Thread[0], NULL, getPrimes, (void*) maxNum);
	
	pthread_join(Thread[0], NULL);
	return 1;
}
