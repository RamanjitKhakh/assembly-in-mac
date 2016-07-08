all: assemble compile link

assemble: new.asm
	nasm -f macho32 ./new.asm -o new.o

compile: test.c
	gcc -c -m32 -lc ./test.c -o test.o

link: test.o new.o
	ld -lc ./test.o ./new.o -e _main -o ./newTest
