[BITS 32]

	extern aes256_decrypt_ecb
	extern aes_expandEncKey
	extern aes256_init
	extern printf
	extern readFile

	

section .bss


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
struc   contextType
	key:	resd 8
	enckey:	resd 8
	deckey:	resd 8
endstruc

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	bufT: resd 4


section .data


structTestKey:
    istruc contextType
    	at key,     dd  0x61616161,0,0,0,0,0,0,0
        at enckey,  dd  0x61616161,0,0,0,0,0,0,0
        at deckey,  dd  0x61616161,0,0,0,0,0,0,0
    iend

		rcon: dd 1
		fmt: db 0xa,'Buf %s',0xa
		cipherTextFile: db "files/cipherTextECB"
		

;MOV  destination, source

		section .text

	
		global begin
;391e f6a8 c614 7d64 f196 f804 ad6b e7a1


begin:
		push ebp
		mov  ebp, esp

		push bufT
		push cipherTextFile
		call readFile
	

	AESinit:
	
		
		mov edi,7
	Iterator:   ;for (i = 8; --i;) aes_expandEncKey(ctx->deckey, &rcon);
		cmp edi,0
		je decrypt
		push rcon
		push DWORD structTestKey+64
		call aes_expandEncKey 
		sub edi,1
		jmp Iterator

	decrypt:
				push bufT
				push structTestKey
				call aes256_decrypt_ecb ; void aes256_decrypt_ecb(aes256_context *ctx, uint8_t *buf)

	printDecrypted:
			
			push bufT
			push fmt
			call printf

	end:
		leave
		ret







