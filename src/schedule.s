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
    mov [GlobalCPUState.r11], r11
    mov [GlobalCPUState.r10], r10
    mov [GlobalCPUState.r9], r9
    mov [GlobalCPUState.r8], r8
    mov [GlobalCPUState.rsi], rsi
    mov [GlobalCPUState.rdi], rdi
    mov [GlobalCPUState.rbp], rbp
    mov [GlobalCPUState.rdx], rdx
    mov [GlobalCPUState.rcx], rcx
    mov [GlobalCPUState.rax], rax
    ret
    
setState:
    ; the last task's save is already saved
    ; load the next task

    mov r11, [GlobalCPUState.r11]
    mov r10, [GlobalCPUState.r10]
    mov r9,  [GlobalCPUState.r9]
    mov r8,  [GlobalCPUState.r8]
    mov rsi, [GlobalCPUState.rsi]
    mov rdi, [GlobalCPUState.rdi]
    mov rbp, [GlobalCPUState.rbp]
    mov rdx, [GlobalCPUState.rdx]
    mov rcx, [GlobalCPUState.rcx]
    mov rax, [GlobalCPUState.rax]
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
  .r11 dq 0
  .r10 dq 0
  .r9 dq 0
  .r8 dq 0

  .rsi dq 0
  .rdi dq 0
  .rbp dq 0

  .rip dq 0
  .cs  dw 0
  .rflags dq 0
  .rsp dq 0
  .ss  dw 0
