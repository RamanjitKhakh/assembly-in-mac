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
	xor	eax, eax
	add	esp, 16	
	mov	ecx, [ebp+8]
	

	mov	ebx, 1
	cmp	ecx, ebx
	jng	cont
	;mov	eax, ecx

	sub	esp, 12
	sub	ecx, 1
	push	dword ecx
	call	_fibonacci
	mov	ecx, [esp]
	;add	eax, ecx
	add	esp, 16
	
	sub     esp, 8
        sub     ecx, 1
	push	dword eax
        push    dword ecx
        call    _fibonacci
	mov	ecx, [esp+4]
        add     eax, ecx
        add     esp, 16
	

	jmp	end
cont:
	mov	eax, 1		
end:
	add	esp, 8
	pop	ebp
	ret
		

section .data
	sentence dd "the param is %d ", 0x0a, 0


