; ===========================================================================
; 
; print_args.asm --
; prints command line arguments to stdout
; (simplified version of use_args.asm for script)
;
; Ralf Moeller
; 
;    Copyright (C) 2007
;    Computer Engineering Group
;    Faculty of Technology
;    University of Bielefeld
;    www.ti.uni-bielefeld.de
; 
; 1.0 / 22. Mar 07 (rm)
; - from use_args.asm
; 1.1 / 11. Jun 08 (rm)
; - output of 0x00 char not required
; - label finish removed
; 1.2 / 24. Sep 13 (rm)
;	
; ===========================================================================

bits 32
	
;;; system calls
%define SYS_WRITE	4
%define SYS_EXIT	1
;;; file ids
%define STDOUT		1
	
;;; start of data section
section .data
;;; a newline character
newline:
 	db 0x0a

;;; start of code section
section	.text
	;; this symbol has to be defined as entry point of the program
	global _start

;;;--------------------------------------------------------------------------
;;; subroutine write_newline
;;;--------------------------------------------------------------------------
;;; writes a newline character to stdout
	
write_newline:
	;; save registers that are used in the code
	push	eax
	push	ebx
	push	ecx
	push	edx
	;; prepare arguments for write syscall
	mov	eax, SYS_WRITE	; write syscall
	mov	ebx, STDOUT	; fd = 1 (stdout)
	mov	ecx, newline	; string
	mov	edx, 1		; length
	int	80h		; kernel interrupt: system call
	;; restore registers (in opposite order)
	pop	edx
	pop	ecx
	pop	ebx
	pop	eax
	ret
	
;;;--------------------------------------------------------------------------
;;; subroutine write_string
;;;--------------------------------------------------------------------------
;;; address of 0-terminated string passed in ecx
;;; operation: determines length of string and writes it in ONE write
;;; (plus a second write that appends a new-line character)

write_string:
	;; save registers that are used in the code
	push	eax
	push	ebx
	push	edx
	;; prepare arguments for write syscall
	mov	eax, SYS_WRITE	; write syscall
	mov	ebx, STDOUT	; fd = 1 (stdout)
	mov	edx, 0		; count bytes
	push	ecx		; keep starting address of string
search_eos:
	;; here we have to specify the string size (byte) 
	cmp	[ecx], byte 0	; end of string (0) reached?
	je	eos_found	; yes, end of loop
	inc	edx		; count
	inc	ecx		; next position in string
	jmp	search_eos	; loop
eos_found:
	pop	ecx		; restore starting address of string
	;; here edx contains the string length
	int	80h		; kernel interrupt: system call
	;; restore registers (in opposite order)
	pop	edx
	pop	ebx
	pop	eax
	ret
	
;;;--------------------------------------------------------------------------
;;; main entry
;;;--------------------------------------------------------------------------

_start:
	pop	ebx		; argc (>= 1 guaranteed)
read_args:
	;; print command line arguments
	pop	ecx		; argv[j]
	call	write_string	; string in ecx is written to stdout
	call	write_newline	; a newline character is written to stdout
	dec	ebx		; dec arg-index
	jnz	read_args	; continue until last argument was printed

	;; exit program via syscall exit (necessary!)
	mov	eax, SYS_EXIT	; exit syscall
	mov	ebx, 0		; exit code 0 (= "ok")
	int	80h		; kernel interrupt: system call
