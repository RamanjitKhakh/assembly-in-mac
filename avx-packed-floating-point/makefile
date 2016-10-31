all:	assemble compile

assemble: packArith.asm
	nasm -f macho64 --prefix _ ./packArith.asm -o ./packArith.o

compile: packArith.o main.c
	gcc -m64 ./packArith.o ./main.c -o ./main
