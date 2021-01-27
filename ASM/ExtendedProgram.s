
[bits 16]

mov ah, 0h
mov al, 13h
int 0x10

jmp EnterProtectedMode

%include "ASM/gdt.s"
%include "ASM/print.s"
%include "ASM/DetectMemory.s"
%include "ASM/font.s"

EnterProtectedMode:
	call DetectMemory
	;call FONT
    call EnableA20
	cli
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp codeseg:StartProtectedMode

EnableA20:
	in al, 0x92
	or al, 2
	out 0x92, al
	ret

[bits 32]

%include "ASM/CPUID.s"
%include "ASM/SimplePaging.s"

StartProtectedMode:

	mov ax, dataseg
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov [0xb8000], byte 'H'
	mov [0xb8002], byte 'e'
	mov [0xb8004], byte 'l'
	mov [0xb8006], byte 'l'
	mov [0xb8008], byte 'o'
	mov [0xb800a], byte ' '
	mov [0xb800c], byte 'W'
	mov [0xb800e], byte 'o'
	mov [0xb8010], byte 'r'
	mov [0xb8012], byte 'l'
	mov [0xb8014], byte 'd'

	call DetectCPUID
	call DetectLongMode
  	call SetUpIdentityPaging
	call EditGDT
    jmp codeseg:Start64Bit

[bits 64]
[extern _start]

%include "ASM/IDT.s"

Start64Bit:
	mov edi, 0xb8000
	mov rax, 0x1f201f201f201f20
	mov ecx, 500
	rep stosq
	call _start
	jmp $


