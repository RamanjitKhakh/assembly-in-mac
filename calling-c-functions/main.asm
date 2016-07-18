; some relavent information
;At the entry point of the main routine you already know that you're misaligned due to the return address being stored in the stack for returning from main. This means that if you want to make even a single call you're going to have to move the stack down by at least 12 bytes to make the call.

bits 32
extern _printf
extern _cFunction
global _main

section .text

_main:
	
	sub    esp, 12 ;align to 16 since return address

	;alternatively you can start the function
	;push   ebp
	;mov    ebp, esp
	;sub	esp, 8 
	;this will align the stack but at the end you need to
	;add	esp, 8
	;pop	ebp

	sub	esp, 12
	push	dword sentences
	call	_printf
	add	esp, 16

	call	_cFunction

	xor  	 eax, eax
	add	esp, 12 ; now only the return address is left on stack
	ret	

section .data

	sentences dd "Started from assembly...", 0x0a, 0
