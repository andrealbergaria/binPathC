[BITS 32]

;nasm tryCombinations.asm -f elf -o tryCombinations.o
; gcc demo.o tryCombs.o -o d
	EXTERN aes_expandEncKey,aes256_decrypt_ecb


	SECTION .DATA
		rcon: db 1
		auxVar: dd 0
		min: dd 0
		max: dd 65536

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
		mov eax,[min]
		mov ebx,[max]
		call tryKeyRange
		mov eax,ebx		 ; 		mov min,max
		add ebx,65536 ; adds interval
		sub ecx,1 ; counter
		jmp loop

tryKeyRange:			;for (long i=min; i < max; i++)
				cmp eax,ebx ; eax -> min, ebx -> max
				je loop ; finished tryKeyRange


	AESInit:   ;aes256_init(&ctx, key);
	;
	;
	; uint8_t rcon = 1;
    ;register uint8_t i;

    ;for (i = 0; i < sizeof(ctx->key); i++) ctx->enckey[i] = ctx->deckey[i] = k[i];

	;

		mov [key],eax
		mov [enckey],eax
		mov [deckey],eax
		mov edx,8
	Iterator:   ;for (i = 8; --i;) aes_expandEncKey(ctx->deckey, &rcon);
		cmp edx,0
		je decrypt
		push deckey
		push rcon
		call aes_expandEncKey
		sub edx,1
		jmp Iterator

	decrypt:
				push eax
				push buf
				call aes256_decrypt_ecb
				add eax,1
        		jmp tryKeyRange


	tryCombinationsEnd:
		ret



