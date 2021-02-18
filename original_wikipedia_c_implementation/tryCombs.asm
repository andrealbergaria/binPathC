[BITS 32]

	extern aes_expandEncKey
	extern aes256_decrypt_ecb
	extern printf
	extern writeToFile

	extern idx;  //when idx==256, means next byte
		global tryCombsASM
		global min
		global max


section .bss


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
struc   contextType
	key:	resd 8
	enckey:	resd 8
	deckey:	resd 8
endstruc

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	buf: resd 4


section .data

fmt:
	str: db '\n Buf %s\n'


nextByte: dd 0 ;used for summing the next bytes of keys

idx: dd 0

structTestKey:
    istruc contextType
    	at key,    dd 0,0,0,0,0,0,0,0
        at enckey, dd 0,0,0,0,0,0,0,0
        at deckey, dd 0,0,0,0,0,0,0,0
    iend

			kInteger: dd 0  ; index of formula of multiple
			min: dd 0
			max: dd 0x0000ffff
			rcon: dd 1



;MOV  destination, source

		section .text

;391e f6a8 c614 7d64 f196 f804 ad6b e7a1


tryCombsASM:
		push ebp
		mov  ebp, esp

		mov eax, [ebp + 8] ;buf
		mov [buf] ,eax
		;mov ebx ,eax  ;copy orginal buf to ebx

	;*buf = &buf

	tryCombinations: ; min, max {

		cmp [max],0x7528670 ; (0x7528670 == 65536*128)
		je finished



	tryKeyRange:
		mov esi,[max] ; esi now has max value
		cmp [min],esi ; min < max ?
		je afterKeyRange ; jump to

		add [min],1

   		call addOneToKeys
		cmp [nextByte],2 ; Set to 8 when serious

		je finished


   		jmp AESInit

   		;
   		;for (long i=min; i < max; i++) {
			//DUMP("key: ", key, 32,0);

		    ;aes256_init(&ctx, key);
		    ;aes256_decrypt_ecb(&ctx,buf_t);


   		;
   		;

afterKeyRange:
		mov [min],esi ; min = max
		add dword [max],0xffff ; max = max + 0xffff (65536)
		add kInteger,1
		cmp [KInteger],10 ; 10 number of iterations on writeToFile
		je setKZero
		jmp tryCombinations

AESInit:

	;set keys equal

	mov edi,7 ;

	AESInitExpandEncKey:   ;for (i = 8; --i;) aes_expandEncKey(ctx->deckey, &rcon);

		cmp edi,0
		je decrypt
		push rcon
		push structI+64
		call aes_expandEncKey
		sub edi,1
		jmp AESInitExpandEncKey

	decrypt:

				push buf
				push structTestKey
				call aes256_decrypt_ecb ; void aes256_decrypt_ecb(aes256_context *ctx, uint8_t *buf)
				jmp tryCombinations



	finished:
		call writeToFileASM
		leave
		ret

	writeToFileASM:
		push [max]
		push [min]
		call writeToFile
		ret

	setKZero:
		mov [KInteger], 0
		call writeToFileASM
		jmp tryCombinations

	addOneToKeys:
		cmp [idx],256
		je nextByteIt

	setKeySum:
		add [structTestKey+nextByte],1
		add [structTestKey+32+nextByte],1
		add [structTestKey+64+nextByte],1
		add [idx],1

		ret

	nextByteIt:
		add [nextByte],1
		mov [idx], 0
		jmp setKeySum
