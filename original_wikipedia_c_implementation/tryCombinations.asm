[BITS 32]
;nasm tryCombinations.asm -f elf -o tryCombinations.o
		.global tryCombinations
		extern writeToFile,aes_expandEncKey

		section .text
	tryCombinations:
		pushl %ebp
		movl  %esp, %ebp
		mov ecx,combinationsMaxValue
	loop:
		cmp ecx,0
		je tryCombinationsEnd
		push min
		push max
		call tryKeyRange

	afterRange:
		cmp ecx,auxVar
		je reachedInterval
	afterInterval:
		mov min,max
		add max,interval
		sub ecx,1
		jmp loop

tryKeyRange:
		pop edx  ; max
		pop eax  ; min

keyRangeLoop:	cmp edx,0
				je afterRange
				push [keyS]
				push [buf]
				call aes256_decrypt_ecb
				sub edx,1
        		jmp keyRangeLoop


	reachedInterval:
		push min
		push max
		call writeFile
		add aux,32768
		jmp afterInterval


AESInit:
		mov key,0x61616161
		mov enckey,0x61616161
		mov deckey,0x61616161
		mov edx,8
	Iterator:
		cmp edx,0
		je finishInitAES
		push [deckey]
		push [rcon]
		call aes_expandEncKey
		sub edx,1
		jmp Iterator

	finishInitAES:
		jmp after_AESInit



tryCombinationsEnd:




	section .data
rcon: db 1
combinationsMaxValue: dd 131072
auxVar: dd 0
min: dd 0
max: dd 65536
interval: dd 65536

	section .bss
		buf RESD 48


ctx:
		key times 32 db 0
		enckey times 32 db 0
		deckey times 32 db 0
