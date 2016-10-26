; Function signature 
; void arthimeticAvx(double a, double b, double *c)i
; Things to know
; printf looks at the rax register to determine if the
; parameters for format argument come from general purpose
; or floating point register (xmm0 to 7)
; 
; xmm0 - double a
; xmm1 - double b
; rsi - double *c
;
; the third parameter is a pointer and is place in general
; purpose register. The floating point doubles are place in 
; the xmm0-7 registers reserved for floating points (System V)

DEFAULT REL
section .data
	sentence dq "welcome to the assembly ", 0x0a, 0
	sent2 dq "the num %lf %lf  %lf    ", 0x0a, 0

section .text

extern printf
global arthimeticAvx

arthimeticAvx:
	sub	rsp, 8
	
	;this print statemnet will show you the 
	;3rd parameter. Because printf will assume
	;all arguments are in the xmm registers
	;movq	xmm2, [rdi]
	;mov	rdi, sent2

	;clearing the rax register denotes there are 
	; no xmm float parameters
	;call	printf

	vaddsd	xmm2, xmm0, xmm1
	vsubsd	xmm3, xmm0, xmm1
	vmulsd	xmm4, xmm0, xmm1
	vdivsd	xmm5, xmm0, xmm1
	
	vmovsd	qword[rdi], xmm2
	vmovsd	qword[rdi+8], xmm3
	vmovsd	qword[rdi+16], xmm4
	vmovsd	qword[rdi+24], xmm5

	add	rsp, 8
	ret	
