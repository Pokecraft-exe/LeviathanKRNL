RescueASM:
  mov ah, 0x0b
  mov bh, 0x00
  mov bl, 0x01
  int 0x10

cls:
  pusha
  mov bx, LINE_STR
  call PrintString
  popa
  ret
  mov ah, 0x09 ; print 500 blue spaces to the screen
  mov al, 0x20
  mov bh, 0x03
  mov bl, 0x1f
  mov cx, 500
  int 0x10

LINE_STR:
  db "                                                                                                                      ",0

	