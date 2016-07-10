all: assemble compile link

assemble: struct.asm
	nasm -f macho ./struct.asm -o ./struct.o

compile: main.c
	gcc -c -m32 ./main.c -o ./main.o

link: main.o struct.o 
	gcc -m32 ./main.o ./struct.o -o main -lc
