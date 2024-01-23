section .text

GLOBAL getState
GLOBAL jumpNextTask
GLOBAL jumpToAddress
GLOBAL gcr2

gcr2:
    mov rax, cr2
    ret

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
    
    mov rax, $
    mov [GlobalCPUState.rip], rax
    
    pushfq
    pop rax
    mov [GlobalCPUState.rflags], rax
    
    mov rax, rsp
    mov [GlobalCPUState.rsp], rax
    ret

jumpToAddress:
    push rdi
    iret
    
jumpNextTask:
    push rbx
    push rsi
    push rdi
    push rbp
    
    ; the last task's save is already saved
    ; load the next task

    mov r15, [GlobalCPUState.r15]
    mov r14, [GlobalCPUState.r14]
    mov r13, [GlobalCPUState.r13]
    mov r12, [GlobalCPUState.r12]
    mov r11, [GlobalCPUState.r11]
    mov r10, [GlobalCPUState.r10]
    mov r9, [GlobalCPUState.r9]
    mov r8, [GlobalCPUState.r8]
    mov rsi, [GlobalCPUState.rsi]
    mov rdi, [GlobalCPUState.rdi]
    mov rbp, [GlobalCPUState.rbp]
    mov rdx, [GlobalCPUState.rdx]
    mov rcx, [GlobalCPUState.rcx]
    mov rbx, [GlobalCPUState.rbx]
    mov rax, [GlobalCPUState.rax]


section .data
extern currentTask
extern tasks
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
  .rdx dq 0
  .rcx dq 0
  .rbx dq 0
  .rax dq 0
  .rip dq 0
  .rflags dq 0
  .rsp dq 0
