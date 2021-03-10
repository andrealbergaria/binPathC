[BITS 32]


	extern printf
	global main



section .data
	
    key:     dw 0,0
	
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
		
		

ebx1: ;begin and end of arrays of bytes ; begin is always 0 , ecx -> last byte ,ebx -> num of bytes
					; [255...255...0]
					ebx=2	ebx=1
					; [255...0...0
					;  ecx   ecx ; from 0 to 255 n times (n=ebx)
					; starts with ebx=0, then ebx=0 and ebx=1 and ebx=0 and ebx=1 end ebx=2
					; para cada ebx2, do ebx1
		cmp word [key+ebx*2], 0xff
		je end
		
		add word [key+ebx*2],1
		jmp ebx1 
		
ebx2: 
		cmp word [ key+ebx2*2],0xff
		je end2
		call ebx1
		add word [key+ebx2*2],1
		jmp ebx2 
		
		push ebx
		push dword [key+ebx*2] ; needs to mulitply by 4 because im only testing byte to byte (4 because the real func is int)
		push fmt
		call printf ;	fmt: db 0xa,'Buf %x , IDX : %x',0xa

		jmp incrementFF
			
incrementInterval:
		add ebx,1
		jmp incrementFF

		
		

;	mov edx,0	;beggining of array
;	mov ecx,1   ;end of array (number of bytes required, for three 0xff , ecx=2)
	

	
;	mov edx,0  ; repeats last component of array [255....255...0] to set up the numbers
	;inc ecx 
;	call incrementFF
	
done:
 	mov eax, 1          ;system call number (sys_exit)
    int 0x80            ;call kernel
	
