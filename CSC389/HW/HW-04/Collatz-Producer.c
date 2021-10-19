#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
	long startNum; // the number we will start the Collatz-Conjecture sequence at
	if(argc != 2) { // if there is not exactly 1 argument
		printf("Invalid number of arguments provided. Please try again.\n");
		return 1;
	} else { // if there is only one argument
		startNum = strtol(argv[1], NULL, 10); // store that number as a long in startNum
		if(startNum <= 0) { // if the number is less than or equal to zero, it is invalid
			printf("Invalid argument. Argument must be greater than or equal to 1.\n");
			return 1;
		}
	}

	const int SIZE = 4096; // the size of our shared memory cell
	const char *Obj = "Shm"; // name of the shared memory cell
	int shm_fd; // file descriptor of shared memory
	void *ptr; // pointer to the shared memory

	shm_fd = shm_open(Obj, O_CREAT | O_RDWR, 0666); // create our shared memory object
	ftruncate(shm_fd, SIZE); // set the size of the object
	ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0); // map the shared memory space
	
	if(ptr == MAP_FAILED) { // let the user know if the map failed
		printf("Map failed\n");
		return -1;
	}
	
	char buffer[SIZE]; // create a buffer to store our output in

	long temp = startNum; // temp is the current number that the loop is on
	int i = sprintf(&buffer[i], "%ld", startNum); // i is the current index to add elements to the buffer at. we start it by adding the starting number to it
	while(temp > 1) { // while the current number is higher than one
		if(temp % 2 == 0) { // if the number is even
			temp/=2; // divide it by 2
		} else { // if the number is odd
			temp = 3 * temp + 1; // set temp to 3 * temp + 1
		}
		i+=sprintf(&buffer[i], ", %ld", temp); // output our updated value to the buffer
	}
	strcpy(ptr, buffer); // copy the buffer to the pointer
	printf("Writing the sequence to the shared memory is done!\n"); // let the user know the process is done
	return 0;
}
