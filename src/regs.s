section .text

GLOBAL pusha
GLOBAL popa
GLOBAL gcr2

gcr2:
    mov rax, cr2

pusha:
    push rsp
    pushfq
    push rip
	push rax
    push rbx
    push rcx
    push rdx
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

section .data
registers:
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
