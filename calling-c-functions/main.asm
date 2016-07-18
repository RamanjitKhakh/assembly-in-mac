bits 32
extern _printf
extern _cFunction
global _main

section .text

_main:
	sub     esp, 12	
	mov	dword[esp], sentences
	call 	_printf 
	add	esp, 12
	call	_cFunction
	xor  	 eax, eax
	ret	

section .data

	sentences db "Started from assembly...", 0x0a, 0

