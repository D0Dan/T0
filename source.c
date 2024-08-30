#include<stdio.h>

void main(int argc, char** argv) {

	//get input
	printf("input string then press enter [no more then 32 characters]:");
	char input[32];
	scanf("%32[^\n]", input);

	int flag = 33;
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == 46)
		       flag = i;
	}
	
	if (flag != 33)
		printf("period detected at position: %i \n", flag);
	else 
		printf("no period detected \n");

	return;
}
