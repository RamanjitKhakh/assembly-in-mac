
bits 32
global _mystart
extern _printf
extern _fflush
section .text
_mystart:
	push dword mylen ; message length
	push dword mymsg ; message to write
	push dword 1	 ; file descriptor

	mov  eax, 0x4	 ; system call number for write
	sub  esp, 4	 ; osx (bsd) system calls need extra space on stack
	int  0x80	 ; interrupt 0x80 is a call to system calls

	add  esp, 16	 ; 3 args * 4 bytes + 4 bytes of extra space = 16 bytes


	sub esp, 12
	mov dword[esp], message
	call _printf
	add  esp, 12

; exit the program but we want to the c program to continue
	;push dword 0 	 ; the 0 in exit(0)

	;mov  eax, 0x1	 ; number for exit()
	;sub  esp, 4 	 ; that "extra" space
	;int  0x80
	
	sub esp, 8
	push dword mylen
	push dword printFormat 
	;pushing in this order is the same as printf("the length of mymsg is %d", mylen);
	call _printf
	add  esp, 16


	
	xor   eax, eax ; return 0
	ret
section .data

	mymsg	db	"Hello from assembly", 0xa, 0 
	mylen   equ	$-mymsg  ; calculates the length
	message db	"Another way of printing", 0xa, 0
	printFormat db  "the length of mymsg is %d", 0xa, 0

