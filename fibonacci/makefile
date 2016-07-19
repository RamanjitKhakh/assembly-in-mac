all: assemble compile

assemble: fibonacci.asm
	nasm -f macho ./fibonacci.asm -o fibonacci.o

compile: main.c fibonacci.o
	gcc -m32 ./main.c ./fibonacci.o -o main -lc
