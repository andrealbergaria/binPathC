[BITS 32]


	extern printf
	global main



section .data
	
    key:     db 0,0
	
	fmt: db 0xa,'Buf %x , IDX : %x',0xa
		
;nasm testLargeNumbers.asm -g -F dwarf -f elf32 -o tryCombs.o
section .text
; ebx points to current byte of key (the array, meaning its a index), assigning it values
; esi has length in bytes of key

main:
	xor ebx,ebx
	
	; number of iterations on increment one byte (0xff)
	; bytes to cycle ( ebx =0 , 0xff , ebx=1 , 0xffff )

; specify byte and increment from 0 to 0xff. Byte number is on ebx
	; ebx -> Number of bytes to check
	incrementFF:
		cmp ebx,2
		je done
		
		cmp DWORD [key+ebx], 0xff
		je incrementInterval

afterIncrementInterval:
		add DWORD [key+ebx],1
		
		push ebx 
		push dword [key+ebx] ; needs to mulitply by 4 because im only testing byte to byte (4 because the real func is int)
		push fmt
		call printf
	
	
		
		jmp incrementFF
			
incrementInterval:
		inc ebx
		jmp afterIncrementInterval

		
		

;	mov edx,0	;beggining of array
;	mov ecx,1   ;end of array (number of bytes required, for three 0xff , ecx=2)
	

	
;	mov edx,0  ; repeats last component of array [255....255...0] to set up the numbers
	;inc ecx 
;	call incrementFF
	
done:
 	mov eax, 1          ;system call number (sys_exit)
    int 0x80            ;call kernel
	
