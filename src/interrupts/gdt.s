[bits 64]
gdt_nulldesc:
	dd 0
	dd 0	
gdt_codedesc:
	dw 0xFFFF			; Limit
	dw 0x0000			; Base (low)
	db 0x00				; Base (medium)
	db 10011010b		; Flags
	db 11001111b		; Flags + Upper Limit
	db 0x00				; Base (high)
	GLOBAL gdt_codedesc
gdt_datadesc:
	dw 0xFFFF
	dw 0x0000
	db 0x00
	db 10010010b
	db 11001111b
	db 0x00
	GLOBAL gdt_datadesc
gdt_user_codedesc:
	dw 0xFFFF			; Limit
	dw 0x0000			; Base (low)
	db 0x00				; Base (medium)
	db 10011110b		; Flags
	db 11001111b		; Flags + Upper Limit
	db 0x00				; Base (high)
	GLOBAL gdt_user_codedesc
gdt_user_datadesc:
	dw 0xFFFF
	dw 0x0000
	db 0x00
	db 10010110b
	db 11001111b
	db 0x00
	GLOBAL gdt_user_datadesc
gdt_end:

gdt_descriptor:
	gdt_size: 
		dw gdt_end - gdt_nulldesc - 1
		dq gdt_nulldesc

codeseg equ gdt_codedesc - gdt_nulldesc
GLOBAL codeseg
dataseg equ gdt_datadesc - gdt_nulldesc
GLOBAL dataseg


extern start_K

EditGDT:
	mov al, 10101111b
	mov [gdt_codedesc + 6], al
	mov [gdt_datadesc + 6], al
	mov [gdt_user_codedesc + 6], al
	mov [gdt_user_datadesc + 6], al
	ret
	

global far_jump_to_kernel

far_jump_to_kernel:
	call EditGDT
	lgdt [gdt_descriptor]
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	mov rax, start_K
    push qword 0x8
    push rax
    o64 retf
[BITS 32]