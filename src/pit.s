section .text:

extern breakpoint

 global init_PIT
 init_PIT:
    push rax
    push rbx
    push rdx

    call breakpoint
 
    ; Do some checking
 
    mov rax,0x10000                   ;eax = reload value for slowest possible frequency (65536)
    cmp rbx,18                        ;Is the requested frequency too low?
    jbe .gotReloadValue               ; yes, use slowest possible frequency
 
    mov rax,1                         ;ax = reload value for fastest possible frequency (1)
    cmp rbx,1193181                   ;Is the requested frequency too high?
    jae .gotReloadValue               ; yes, use fastest possible frequency
 
    ; Calculate the reload value

    mov rax,3579545
    mov rdx,0                         ;edx:eax = 3579545
    div rbx                           ;eax = 3579545 / frequency, edx = remainder
    cmp rdx,3579545 / 2               ;Is the remainder more than half?
    jb .l1                            ; no, round down
    inc rax                           ; yes, round up
 .l1:
    mov rbx,3
    mov rdx,0                         ;edx:eax = 3579545 * 256 / frequency
    div rbx                           ;eax = (3579545 * 256 / 3 * 256) / frequency
    cmp rdx,3 / 2                     ;Is the remainder more than half?
    jb .l2                            ; no, round down
    inc rax                           ; yes, round up
 .l2:
 
 
 ; Store the reload value and calculate the actual frequency
 
 .gotReloadValue:
    push rax                          ;Store reload_value for later
    mov [PIT_reload_value],ax         ;Store the reload value for later
    mov rbx,rax                       ;ebx = reload value
 
    mov rax,3579545
    mov rdx,0                         ;edx:eax = 3579545
    div rbx                           ;eax = 3579545 / reload_value, edx = remainder
    cmp rdx,3579545 / 2               ;Is the remainder more than half?
    jb .l3                            ; no, round down
    inc rax                           ; yes, round up
 .l3:
    mov rbx,3
    mov rdx,0                         ;edx:eax = 3579545 / reload_value
    div rbx                           ;eax = (3579545 / 3) / frequency
    cmp rdx,3 / 2                     ;Is the remainder more than half?
    jb .l4                            ; no, round down
    inc rax                           ; yes, round up
 .l4:
    mov [IRQ0_frequency],rax          ;Store the actual frequency for displaying later
 
 
 ; Calculate the amount of time between IRQs in 32.32 fixed point
 ;
 ; Note: The basic formula is:
 ;           time in ms = reload_value / (3579545 / 3) * 1000
 ;       This can be rearranged in the following way:
 ;           time in ms = reload_value * 3000 / 3579545
 ;           time in ms = reload_value * 3000 / 3579545 * (2^42)/(2^42)
 ;           time in ms = reload_value * 3000 * (2^42) / 3579545 / (2^42)
 ;           time in ms * 2^32 = reload_value * 3000 * (2^42) / 3579545 / (2^42) * (2^32)
 ;           time in ms * 2^32 = reload_value * 3000 * (2^42) / 3579545 / (2^10)
 
    pop rbx                           ;ebx = reload_value
    mov rax,0xDBB3A062                ;eax = 3000 * (2^42) / 3579545
    mul rbx                           ;edx:eax = reload_value * 3000 * (2^42) / 3579545
    shrd rax,rdx,10
    shr rdx,10                        ;edx:eax = reload_value * 3000 * (2^42) / 3579545 / (2^10)
 
    mov [IRQ0_ms],rdx                 ;Set whole ms between IRQs
    mov [IRQ0_fractions],rax          ;Set fractions of 1 ms between IRQs
 
 
 ; Program the PIT channel
 
    push ax

    cli                               ;Disabled interrupts (just in case)
 
    mov al,00110100b                  ;channel 0, lobyte/hibyte, rate generator
    out 0x43, al
 
    mov ax,[PIT_reload_value]         ;ax = 16 bit reload value
    out 0x40,al                       ;Set low byte of PIT reload value
    mov al,ah                         ;ax = high 8 bits of reload value
    out 0x40,al                       ;Set high byte of PIT reload value
 
    pop ax
 
    pop rdx
    pop rbx
    pop rax
    ret

section .bss:
extern IRQ0_fractions
extern IRQ0_ms
extern system_timer_fractions
extern system_timer_ms
extern CountDown
extern PIT_reload_value
extern IRQ0_frequency