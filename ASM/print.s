PrintString:
    push ax
    push bx

    mov ah, 0x0e
    .loop:
    cmp [bx], byte 0
    je .Exit
        mov al, [bx]
        int 0x10
        inc bx
        jmp .loop
    .Exit:

    pop ax
    pop bx
    ret
