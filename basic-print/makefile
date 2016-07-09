all: assemble compile link

assemble: new.asm
	nasm -f macho ./new.asm -o new.o

compile: test.c
	gcc -c -m32 -lc ./test.c -o test.o

link: test.o new.o
	gcc -m32 ./test.o ./new.o -o newTest

#in order to use printf in c you need to flush the buffer w/ \n
