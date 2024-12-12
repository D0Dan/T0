#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(int argc, char* argv[]) {

	size_t bytes_read;
	char buffer[1];
	int input_file = open("input.txt", O_RDONLY);
	for(int index = 0; bytes_read = read(input_file, buffer, 1) > 0; index++) {
		if (buffer[0] == ',') {
			printf("period detected at position: %i \n", index);
			return;
		}
	}
	if (bytes_read == 0){
		printf("no period detected \n");
	} else if(bytes_read == -1) {
		printf("error \n");	
	}

	close(input_file);
	return;
}
