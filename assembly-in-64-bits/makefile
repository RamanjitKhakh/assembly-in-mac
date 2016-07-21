all:	assemble link

assemble: hello64.asm
	nasm -f macho64 ./hello64.asm -o ./hello64.o

link: hello64.o
	gcc -m64 ./hello64.o -o ./hello64 -lc
