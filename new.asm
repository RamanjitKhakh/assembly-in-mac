section .text
use32
global _mystart
extern _printf
_mystart:
	push dword mylen ; message length
	push dword mymsg ; message to write
	push dword 1	 ; file descriptor

	mov  eax, 0x4	 ; system call number for write
	sub  esp, 4	 ; osx (bsd) system calls need extra space on stack
	int  0x80	 ; interrupt 0x80 is a call to system calls

	add  esp, 16	 ; 3 args * 4 bytes + 4 bytes of extra space = 16 bytes
	
; exit the program
	push dword 0 	 ; the 0 in exit(0)

	mov  eax, 0x1	 ; number for exit()
	sub  esp, 4 	 ; that "extra" space
	int  0x80

section .data

	mymsg	db	"Hello from assembly    ", 0xa 
	mylen   equ	$-mymsg  ; calculates the length
