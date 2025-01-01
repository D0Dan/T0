#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) 
{
	size_t bytes_read; 
	char buffer[64];  // 64 byte buffer
	int input_file = open("input.txt", O_RDONLY); // input file-strean for read()

	// preform read on input_file until '.' is encountared or no bytes are read
	for(int index = 0; (bytes_read = read(input_file, buffer, 64)) != 0; index++)
	{
		for (int i = 0; i <= bytes_read; i++)
		{	
			printf("-> %c at %i\n", buffer[i], i);
			if (buffer[i] == '.') 
			{
				printf("period detected at position: %i \n", index*64 + i);
				close(input_file);
				return 0;
			}
		}
	} 

	if(bytes_read == -1) 
	{
		printf("error\n");
		close(input_file);
		exit(1);	       
	} 
	else
	{
		printf("bytes read : %i\n", bytes_read);
		printf("no period detected\n");
	}

	close(input_file);
	return 0;
}
