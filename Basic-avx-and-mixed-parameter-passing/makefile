all:	assemble compile

assemble: arthimetic.asm
	nasm -f macho64 --prefix _  ./arthimetic.asm -o ./arthimetic.o

compile: arthimetic.o main.c
	gcc -lc -m64 ./arthimetic.o ./main.c -o ./main
