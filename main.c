#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(int argc, char* argv[]) {

	size_t bytes_read; //n bytes read during oparation of read()
	char buffer[1]; //storage for read operation
	int input_file = open("input.txt", O_RDONLY); //input file-strean for read()

	// preform read on input_file until ',' is encountared or no bytes are read
	for(int index = 0; bytes_read = read(input_file, buffer, 1) > 0; index++) {
		if (buffer[0] == ',') {
			printf("period detected at position: %i \n", index);
			return;
		}
	}
	if (bytes_read == 0){ //no bytes read means reached end of file 
		printf("no period detected \n");
	} else if(bytes_read == -1) { //read return an arror as -1 bytes read
		printf("error \n");	
	}

	close(input_file);
	return;
}
