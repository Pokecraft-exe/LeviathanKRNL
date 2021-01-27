
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
	ret

BOOT_DISK:
	db 0

DiskReadErrorString:
	db 'Kernel panic an error occured',0

DiskReadFailed:
	mov bx, DiskReadErrorString
	call PrintString

	jmp $
