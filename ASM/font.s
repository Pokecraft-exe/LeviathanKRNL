FONT:
;in: es:di=4k buffer
;out: buffer filled with font
    push		ds
    push		es
;ask BIOS to return VGA bitmap fonts
    mov			ax, 1130h
    mov			bh, 6
    int			10h 
;copy charmap
    push		es
    pop			ds
    pop			es
    mov			si, bp
    mov			cx, 256*16/4
    rep			movsd
    pop			ds
    GLOBAL FONT