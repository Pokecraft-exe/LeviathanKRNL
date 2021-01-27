bits    32
	
section         .text
        align   4
        dd      0x1BADB002
        dd      0x00
        dd      - (0x1BADB002+0x00)

global kmain
%include file.s

jmp kmain

kmain:
	xor ax, ax
	mov ds, ax
	mov ss, ax
	mov ebp, 0x100000 ; the kernel is loaded at 0x100000
	mov esp, ebp
	cli 
    call ReadDisk
    hlt