bits 32

global _fibonacci
extern _printf

section .text

_fibonacci:
	push	ebp
	mov	ebp, esp
	sub	esp, 16
	mov	ecx, [ebp+8]
	push	dword ecx
	push	dword sentence
	call	_printf
	add	esp, 16	
	mov	ecx, [ebp+8]
	xor	ebx, ebx
	cmp	ebx, ecx
	jz	cont
	mov	eax, ecx
	jmp	end
cont:
	mov	eax, 0		
end:
	add	esp, 8
	pop	ebp
	ret
		

section .data
	sentence dd "the param is %d ", 0x0a, 0

