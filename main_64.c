#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char* argv[]) 
{
	size_t bytes_read; 
	char buffer[64];  // 64 byte buffer
	int input_file = open("input.txt", O_RDONLY); // input file-stream

	clock_t start, end;
	double cpu_time;

	start = clock(); // start of timer 

	// preform read on input_file until '.' is encountered or no bytes are read
	for(int index = 0; (bytes_read = read(input_file, buffer, 64)) != 0; index++)
	{
		for (int i = 0; i <= bytes_read; i++)
		{	
			//printf("-> %c at %i\n", buffer[i], i);
			if (buffer[i] == '.') 
			{
				printf("period detected at position: %i \n", index*64 + i);
				end = clock(); // end of timer
				printf("time taken: %f miliseconds\n", ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0);
				close(input_file);
				return 0;
			}
		}
	} 

	end = clock(); // end of timer if error/no period

	if(bytes_read == -1) 
	{
		printf("error\n");
		printf("time taken: %f miliseconds\n", ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0);
		close(input_file);
		exit(1);	       
	} 
	else
	{
		printf("bytes read : %i\n", bytes_read);
		printf("no period detected\n");
		printf("time taken: %f miliseconds\n", ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0);
	}

	close(input_file);
	return 0;
}
