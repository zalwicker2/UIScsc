#include <stdio.h>
#include <sys/types.h>

void generateSequence(int num) {
	int num2 = 0;
	int num1 = 1;
	
	printf("The first %d numbers in the Fibonacci sequence are 0, 1", num);
	
	int i;
	for(i = 1; i < (num - 1); i++) {
		int currentNum = num1 + num2;
		printf(", %d", currentNum);
		num2 = num1;
		num1 = currentNum;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	long numCount;
	
	if(argc == 2) {
		numCount = strtol(argv[1], NULL, 10);
		if(numCount <= 0) {
			printf("Invalid argument entered. Please try again.\n");
			return 1;
		}
	} else {
		printf("Incorrect number of arguments entered. Please try again.\n");
		return 1;
	}
	pid_t id = fork();
	if(id < 0) { /* if there is an error */
		fprintf(stderr, "Fork Failed\n");
		return 1;	
	} else if(id == 0) { /* child process, runs fibo */
		generateSequence(numCount);
		return 1;
	} else { /* parent process, tells when child is done */
		wait(NULL);
		printf("The child process is done!\n");
	}
	return 0;
}
