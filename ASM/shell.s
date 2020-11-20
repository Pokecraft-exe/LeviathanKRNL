[extern Shell]
get_inputs: mov di, cmdStr
keyloop:
        mov ah, 0x00
        int 0x16
        mov ah, 0x0e
        cmp al, 0xD
        je doneScanf
        mov [di], al
        inc [di]
        jmp keyloop
doneScanf:
        mov byte [di], 0
        mov al, [cmdStr]
        call Shell
        cli
        hlt
cmdStr: db '',0