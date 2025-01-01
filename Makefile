all: main main_64

main: main.c
	gcc main.c -o main

main_64: main_64.c
	gcc main_64.c -o main_64
