/////////////////////////////////////////////////////////////////
//
// This is an simple program of UNIX pipes.
//
// Compile:  gcc  Pipe.c  -o  Pipe
//
// Run:      ./Pipe
//
///////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


#define SIZE       100
#define WRITE_END	1
#define READ_END	0


int main(void)
{
	char Write_Msg[SIZE]; // buffer to store a message to write to a pipe
	char Read_Msg[SIZE]; // buffer to store a message read from a pipe
	int pipe1[2]; // our first pipe, will be used to send the message to the child process
    int pipe2[2]; // our second pipe, will be used to send the converted message back to the parent process
	pid_t pid; // variable to determine whether we are on the parent or child process

	printf("Please input a character string: \n");
	fgets(Write_Msg, SIZE, stdin); // store the input given from the console into Write_Msg

	if (pipe(pipe1) == -1) { // perform check on if pipe1 was successfully piped
		fprintf(stderr,"Pipe 1 failed");
		return 1;
	}
    if (pipe(pipe2) == -1) { // perform check on if pipe2 was successfully piped
		fprintf(stderr,"Pipe 2 failed");
		return 1;
	}

	pid = fork(); // fork the process

	 if (pid < 0) // let the user know if the fork failed
	{
		fprintf(stderr, "Fork failed");
		return 1;
	}

	if (pid > 0) {  // parent process
		close(pipe1[READ_END]); // close the pipes we aren't using
        close(pipe2[WRITE_END]);

		write(pipe1[WRITE_END], Write_Msg, strlen(Write_Msg)+1); // write the inputted message to the first pipe

		close(pipe1[WRITE_END]); // close the write end because we don't need to write more

        wait(NULL); // wait for the child process to terminate.

        read(pipe2[READ_END], Read_Msg, SIZE); // read the end of the pipe into Read_Msg, should be our reversed case message
        close(pipe2[READ_END]); // close the reading end of the pipe

        printf("%s", Read_Msg); // print out the reversed string
	} else { // child process
		close(pipe1[WRITE_END]); // close the pipe ends we aren't using
        close(pipe2[READ_END]);

		read(pipe1[READ_END], Read_Msg, SIZE); // read the message into the read message
        close(pipe1[READ_END]); // close the pipe end because we don't need to read anymore
        int i;
        for(i = 0; i < SIZE; i++) { // for as many characters as can be in the string
            char temp = Read_Msg[i]; // store the character temporarily
            if(islower(temp)) { // if the char is lowercase
                Read_Msg[i] = toupper(temp); // make it uppercase
                continue; // move on to the next section of the loop so we don't set the char to lowercase in the next if
            }
            if(isupper(temp)) { // if the char is uppercase
                Read_Msg[i] = tolower(temp); // make it lowercase
            }
        }
		write(pipe2[WRITE_END], Read_Msg, strlen(Read_Msg) + 1); // write the updated message to the second pipe
        close(pipe2[WRITE_END]); // close the second pipe
	}

	return 0;
}
