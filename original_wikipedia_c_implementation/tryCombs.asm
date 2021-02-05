[BITS 32]

;nasm tryCombinations.asm -f elf -o tryCombinations.o
; gcc demo.o tryCombs.o -o d
	extern aes_expandEncKey,aes256_decrypt_ecb

	SECTION .DATA
		rcon: db 1
		auxVar: dd 0
		min: dd 0
		max: dd 65536
		interval: dd 65536

		key: times 32 db 0
		enckey: times 32 db 0
		deckey:  times 32 db 0
		buf: times 48 dd 0x62


		SECTION .TEXT
			GLOBAL tryCombsASM

tryCombsASM:
		push ebp
		mov  esp, ebp

		mov ecx,131072

	loop:
		cmp ecx,0
		je tryCombinationsEnd
		mov eax,min
		mov ebx,max
		push eax
		push ebx
		call tryKeyRange

		mov eax,ebx ; 		mov min,max
		add ebx,interval ; max+interval
		sub ecx,1 ; counter
		jmp loop

decrementECX:
	sub ecx,1
	jmp loop

tryKeyRange:
		pop eax ; min
		pop ebx ; max

keyRangeLoop:
				cmp ebx,max
				je decrementECX


	AESInit:
		mov [key],ebx
		mov [enckey],ebx
		mov [deckey],ebx
		mov edx,8
	Iterator:
		cmp edx,0
		je after_AESInit
		mov esi,deckey
		mov edi,rcon
		push esi
		push edi
		call aes_expandEncKey
		sub edx,1
		jmp Iterator

	after_AESInit:
				push key
				push buf
				call aes256_decrypt_ecb
				add ebx,1
        		jmp keyRangeLoop

	tryCombinationsEnd:
		ret



