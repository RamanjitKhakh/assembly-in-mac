section .data

	sentence dd "welcome to the new cpuid test!!!", 0x0a, 0
	sent dd "first param   %d", 0x0a, 0
	sent2 dd "second param %d", 0x0a, 0
	sent3 dd "third param %d", 0x0a, 0

struc CpuidRegs
	RegEAX  resd 1
	RegEBX  resd 1
	RegECX  resd 1
	RegEDX  resd 1
	size	
endstruc


section .text



extern _printf
global _Cpuid_

_Cpuid_:
	push	rdi
	push	rsi
	push	rdx	

	mov		r9, rdx
	mov  	rax, rdi
	mov  	rcx, rsi
	cpuid

	mov  	rsi, r9
	mov  	dword[rsi+RegEAX], eax
	mov  	dword[rsi+RegEBX], ebx
	mov  	dword[rsi+RegECX], ecx
	mov  	dword[rsi+RegEDX], edx

	or  	rax, rbx
	or  	rcx, rdx
	or  	rax, rcx
	
	pop		rdx
	pop		rsi
	pop		rdi
	ret
