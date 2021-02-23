[org 0x7c00]


BPB:
    jmp init
    nop
    .OEMName db "BOOT"
    .BytsPerSec dw 0x0200
    .SecPerClus db 0x01
    .RsvdSecCnt dw 0x0001
    .NumFATs db 0x02
    .RootEntCnt dw 0x0000
    .TotSec16 dw 0x0000
    .Media db 0xf8
    .FATSz16 dw 0x0000
    .SecPerTrk dw 0xffff
    .NumHeads dw 0x0001
    .HiDDSec dd 0x00000000
    .TotSec32 dd 0x00ee5000
    .FATSz32 dd 0x000000ed
    .ExtFlags dw 0x0000
    .FSVer dw 0x0000
    .RootClus dd 0x00000000
    .FSInfo dw 0x0001
    .BkBootSec dw 0x0000
    times 12 db 0  

BS:
    .DrvNum       db 0x80
    .Reserved1    db 0x00
    .BootSig      db 0x29
    .VolID        dd 0xa0a615c
    .VolLab       db "LeviathanBoot"
    .FileSysType  db "FAT32   "

init:
   
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov gs, ax
    mov fs, ax
    mov ss, ax
    jmp 0x0000:start

start:
    mov [BOOT_DISK], dl
    ; TODO: Relocate the sector to place it @ 0x0000:0x0500 instead
    mov sp, 0x7bff
    
    call ReadDisk
    jmp PROGRAM_SPACE

%include "ASM/print.s"
%include "ASM/file.s"

    times 510-($-$$) db 0
    dw 0xaa55
