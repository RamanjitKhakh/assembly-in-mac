bits 32
global _printStruct
extern _malloc
extern _printf

struc record
	name: resb 50
	thing: resb 50
	more: resb 29
	_size:   ; leave a empty field for size 
endstruc


section .text

_printStruct:
	mov  ebx, record_size
	sub  esp, 8
	push dword ebx
	push dword lengthString
	call _printf
	add  esp, 16
	xor  eax, eax
	ret	
section .data

recordStr:
	istruc record
		at name, db "frfrffr"
		at thing, db "dfvvvvvv"
		at more, db "fffff"
	iend



lengthString db "length of struct is %d", 0xa, 0

structLen  equ  $ - recordStr
