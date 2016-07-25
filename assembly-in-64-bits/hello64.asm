global _main
extern _printf

section .text

_main:
	push	rbp
	mov	rbp, rsp
	mov	rdi, sentence
	call	_printf
	pop	rbp
	ret


section .data
	sentence dq "Hello world !", 0x0a, 0
