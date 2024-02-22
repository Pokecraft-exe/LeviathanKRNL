section .text
bits 64

GLOBAL getState
GLOBAL setState
GLOBAL endTextSection
GLOBAL Schedule
GLOBAL _Z16SchedulerHandlerP15interrupt_frame
extern NextTask
extern ScheduleReturn

getState:
    mov [GlobalCPUState.rax], rax
    mov [GlobalCPUState.rdx], rdx
    mov [GlobalCPUState.rcx], rcx
    mov [GlobalCPUState.rsi], rsi
    mov [GlobalCPUState.rdi], rdi
    mov [GlobalCPUState.r8], r8
    mov [GlobalCPUState.r9], r9
    mov [GlobalCPUState.r10], r10
    mov [GlobalCPUState.r11], r11
    mov [GlobalCPUState.rbp], rbp
    ret

endTextSection:
    and rax, rax

_Z16SchedulerHandlerP15interrupt_frame:
    endbr64 
    push   rbp
    push   r11
    push   r10
    push   r9
    push   r8
    push   rdi
    push   rsi
    push   rcx
    push   rdx
    push   rax

    inc qword [ticks]
    mov rdi, rsp
    call NextTask 
    mov rsp, rax
    mov rax, 0x20
    out 0x20, ax
    out 0xa0, ax

    pop    rax
    pop    rdx
    pop    rcx
    pop    rsi
    pop    rdi
    pop    r8
    pop    r9
    pop    r10
    pop    r11
    pop    rbp
    iretq

section .data
extern ticks
global GlobalCPUState

GlobalCPUState:
  .rax dq 0
  .rdx dq 0
  .rcx dq 0
  .rsi dq 0
  .rdi dq 0
  .r8 dq 0
  .r9 dq 0
  .r10 dq 0
  .r11 dq 0
  .rbp dq 0
