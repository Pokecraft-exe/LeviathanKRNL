section .data:
  extern ticks
section .text:

extern Schedule
%macro pushaq 0
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
%endmacro

%macro popaq 0
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
    pop rdx
    pop rcx
    pop rbx
    pop rax
%endmacro

global pit_handler
pit_handler:
    pushaq
    mov rax, [ticks]
    inc rax
    mov [ticks], rax
    call Schedule
    mov al,20h
    out 20h,al
    popaq
    iretq
    
extern fprint

global isr0xe
isr0xe:
  pushaq
  mov rcx, [LC1]
  call fprint
  .loop
  jmp .loop
  
  
  
section .data:
  LC1: db "PageFault", 0
