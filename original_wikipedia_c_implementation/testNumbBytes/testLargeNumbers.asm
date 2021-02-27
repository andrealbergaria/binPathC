[BITS 32]


	extern printf
	global main



section .data
	
    	key:     dd 0 ; use limits in one index, increment nextIndex, limits again
	buf:  dd 0

	fmt: db 0xa,'Buf %x',0xa
	

section .text


main:
	
	mov ebx, dword [key]
	mov dword [buf],ebx
	push dword [buf]
	push fmt
	call printf

	add dword  [key],1

	cmp dword [key],5
	je end
	jmp main

end:
