
PROGRAM_SPACE equ 0x8000

ReadDisk:

	mov ah, 0x02
	mov bx, PROGRAM_SPACE
	mov al, 64
	mov dl, [BOOT_DISK]
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 0x02

	int 0x13
	;jc DiskReadFailed
	ret

BOOT_DISK:
	db 0

DiskReadErrorString:
	%include "ASM/BSOD.s"
	call RescueASM

DiskReadFailed:
	mov bx, DiskReadErrorString
	call PrintString

	jmp $
