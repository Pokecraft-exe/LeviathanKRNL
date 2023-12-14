section .bss

global IRQ0_fractions
global IRQ0_ms
global system_timer_fractions
global system_timer_ms
global PIT_reload_value
global IRQ0_frequency

system_timer_fractions:  resd 1          ; Fractions of 1 ms since timer initialized
system_timer_ms:         resd 1          ; Number of whole ms since timer initialized
IRQ0_fractions:          resd 1          ; Fractions of 1 ms between IRQs
IRQ0_ms:                 resd 1          ; Number of whole ms between IRQs
IRQ0_frequency:          resd 1          ; Actual frequency of PIT
PIT_reload_value:        resw 1          ; Current PIT reload value

SECTION .text:
    
extern Schedule
global IRQ0_handler
IRQ0_handler:
	push rax
	push rbx
 
	mov rax, [IRQ0_fractions]
	mov rbx, [IRQ0_ms]                    ; eax.ebx = amount of time between IRQs
	add [system_timer_fractions], rax     ; Update system timer tick fractions
	adc [system_timer_ms], rbx            ; Update system timer tick milli-seconds

    call TimerIRQ
    call Schedule
 
	mov al, 0x20
	out 0x20, al                          ; Send the EOI to the PIC
 
	pop rbx
	pop rax
	iretd


global TimerIRQ
TimerIRQ:
    push rax
    mov rax, [CountDown]
    test rax, rax
    jz TimerDone
    dec rax
    mov [CountDown], rax
TimerDone:
    pop rax
    iretd

section .data:
global CountDown
    CountDown: dq 0