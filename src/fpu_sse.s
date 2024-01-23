section .text
global detectFPU
global detectSSE
[bits 64]

detectFPU:
    mov rdx, cr0
    and rdx, (-1) - 12
    mov cr0, rdx
    FNINIT
    FNSTSW word [fpuPresent]
    ret

detectSSE:
    mov eax, 0x1
    cpuid
    test edx, 1<<25
    jz noSSE
    jmp enableSSE
enableSSE:
    mov rax, cr0
    and ax, 0xFFFB
    or ax, 0x2
    mov cr0, rax
    mov rax, cr4
    or rax, 3<<9
    mov cr4, rax
    mov ax, 1
    ret
noSSE:
    ret
    
global fpuPresent
global ssePresent

section .data
  fpuPresent: dw 0x55AA
  ssePresent: db 0
