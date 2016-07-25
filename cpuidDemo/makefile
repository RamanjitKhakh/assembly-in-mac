all:  assemble compile

assemble: cpuid.asm
	nasm -f macho64 ./cpuid.asm -o ./cpuid.o

compile: cpuid.o main.c
	gcc -m64  ./cpuid.o main.c -o ./test.exe -lc

