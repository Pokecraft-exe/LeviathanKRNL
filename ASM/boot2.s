[org 0x7c00]


BPB:
    jmp start
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
    .DrvNum       dd 0x80
    .Reserved1    db 0x00
    .BootSig      db 0x29
    .VolID        dd 0xa0a615c
    .VolLab       db "LeviathanBoot"
    .FileSysType  db "FAT32   "

start:
mov [BOOT_DISK], dl

mov bp, 0x7c00
mov sp, bp

call ReadDisk
jmp PROGRAM_SPACE

%include "ASM/print.s"
%include "ASM/file.s"

times 510-($-$$) db 0

dw 0xaa55
