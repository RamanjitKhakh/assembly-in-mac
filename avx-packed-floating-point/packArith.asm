section .data
	sentence dq "hello from the assembly side     ", 0x0a, 0

section .text
global packArithmetic
extern printf

packArithmetic
	sub	rsp, 8 
	
	; adding
	movaps	xmm0, [rdi]
	movaps	xmm1, [rsi]
	xorps	xmm2, xmm2	
	movaps	xmm2, xmm0
	addps	xmm2, xmm1	
	movaps	[rdx], xmm2

	movaps	xmm0, [rdi+16]
	movaps	xmm1, [rsi+16]
	movaps	xmm2, xmm0 
	addps	xmm2, xmm1
	movaps	[rdx+16], xmm2
	
	; subtracting
	movaps	xmm0, [rdi]
	movaps	xmm1, [rsi]
	movaps	xmm2, xmm0
	subps	xmm2, xmm1
	movaps	[rdx+32], xmm2

	movaps	xmm0, [rdi+16]
	movaps	xmm1, [rsi+16]
	movaps	xmm2, xmm0
	subps	xmm2, xmm1
	movaps	[rdx+48], xmm2
	add	rsp, 8
	ret
