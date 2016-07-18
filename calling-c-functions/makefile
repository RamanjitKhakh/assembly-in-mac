all:  assemble compile link


assemble: main.asm
	nasm -f macho ./main.asm -o ./main.o

compile: cFunction.c
	gcc -c -m32 ./cFunction.c -o ./cFunction.o

link: main.o cFunction.o
	gcc -m32 ./main.o ./cFunction.o -o ./main -lc
