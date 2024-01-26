section .text
bits 64

GLOBAL getState
GLOBAL setState
GLOBAL endTextSection
GLOBAL jmpNextTask
GLOBAL Schedule
extern NextTask

getState:
    mov [GlobalCPUState.r15], r15
    mov [GlobalCPUState.r14], r14
    mov [GlobalCPUState.r13], r13
    mov [GlobalCPUState.r12], r12
    mov [GlobalCPUState.r11], r11
    mov [GlobalCPUState.r10], r10
    mov [GlobalCPUState.r9], r9
    mov [GlobalCPUState.r8], r8
    mov [GlobalCPUState.rsi], rsi
    mov [GlobalCPUState.rdi], rdi
    mov [GlobalCPUState.rbp], rbp
    mov [GlobalCPUState.rdx], rdx
    mov [GlobalCPUState.rcx], rcx
    mov [GlobalCPUState.rbx], rbx
    mov [GlobalCPUState.rax], rax
    ret
    
jmpNextTask:

	push word 0x10
	push qword [GlobalCPUState.rsp]
	pushfq
	push word 0x08
	push qword [GlobalCPUState.rip]
	iret

setState:
    ; the last task's save is already saved
    ; load the next task

    mov r15, [GlobalCPUState.r15]
    mov r14, [GlobalCPUState.r14]
    mov r13, [GlobalCPUState.r13]
    mov r12, [GlobalCPUState.r12]
    mov r11, [GlobalCPUState.r11]
    mov r10, [GlobalCPUState.r10]
    mov r9,  [GlobalCPUState.r9]
    mov r8,  [GlobalCPUState.r8]
    mov rsi, [GlobalCPUState.rsi]
    mov rdi, [GlobalCPUState.rdi]
    mov rbp, [GlobalCPUState.rbp]
    mov rdx, [GlobalCPUState.rdx]
    mov rcx, [GlobalCPUState.rcx]
    mov rbx, [GlobalCPUState.rbx]
    mov rax, [GlobalCPUState.rax]
    ret

endTextSection:
    and rax, rax

Schedule:
    push rax
    push rbx
    push rcx
    push rdx

    push gs
    push fs
    mov ax, es
    push ax
    mov ax, ds
    push ax

    push rbp
    push rdi
    push rsi
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    inc qword [ticks]

    mov rdi, rsp
    call NextTask 
    mov rsp, rax

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rsi
    pop rdi
    pop rbp

    pop ax
    mov ds, ax
    pop ax
    mov es, ax
    pop fs
    pop gs

    pop rdx
    pop rcx
    pop rbx
    pop rax

    iretq

section .data
extern ticks
global GlobalCPUState
GlobalCPUState:
  .r15 dq 0
  .r14 dq 0
  .r13 dq 0
  .r12 dq 0
  .r11 dq 0
  .r10 dq 0
  .r9 dq 0
  .r8 dq 0

  .rsi dq 0
  .rdi dq 0
  .rbp dq 0

  .ds dw 0
  .es dw 0
  .fs dw 0
  .gs dw 0

  .rdx dq 0
  .rcx dq 0
  .rbx dq 0
  .rax dq 0

  .rip dq 0
  .cs  dw 0
  .rflags dq 0
  .rsp dq 0
  .ss  dw 0
