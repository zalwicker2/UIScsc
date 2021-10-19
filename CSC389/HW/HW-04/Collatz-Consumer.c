#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
	const int SIZE = 4096; // size of the shared memory
	const char *Obj = "Shm"; // name of the shared memory

	int shm_fd; // file descriptor of the shared memory
	void *ptr; // pointer to shared memory
	
	shm_fd = shm_open(Obj, O_RDONLY, 0666); // open the shared memory
	
	if(shm_fd == -1) { // if the memory has failed, usually because the producer hasn't been run yet
		printf("Shared memory failed");
		exit(-1);
	}
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0); // map the shared memory
	
	if(ptr == MAP_FAILED) { // if the map has failed, let the user know
		printf("Map failed\n");
		exit(-1);
	}

	printf("The output sequence is: %s\n", (char *)ptr); // output the sequence that was stored in the shared memory

	if(shm_unlink(Obj) == -1) { // remove the shared memory, let the user know if there was an error
		printf("Error removing %s\n", Obj);
		exit(-1);
	}
	return 0;
}
