GLOBAL pusha
GLOBAL popa
global grax
global grbx
global grcx
global grdx
global grax
global gbx
global gcx
global gdx
global grsi
global grdi
global gfs
global ggs
global grsp
global mrax
global mrbx
global mrcx
global mrdx
global max
global mbx
global mcx
global mdx
global mrsi
global mrdi
global mfs
global mgs
global mrsp
grax:
	push rax;
grbx:
	push rbx;
grcx:
	push rcx;
grdx:
	push rdx;
gax:
	push ax;
gbx:
	push bx;
gcx:
	push cx;
gdx:
	push dx;
grsi:
	push rsi;
grdi:
	push rdi;
gfs:
	push FS;
ggs:
	push GS;
grsp:
	push rsp;
mrax:
	pop rax;
mrbx:
	pop rbx;
mrcx:
	pop rcx;
mrdx:
	pop rdx;
max:
	pop ax;
mbx:
	pop bx;
mcx:
	pop cx;
mdx:
	pop dx;
mrsi:
	pop rsi;
mrdi:
	pop rdi;
mfs:
	pop FS;
mgs:
	pop GS;
mrsp:
	pop rsp;
	
pusha:
	push rax;
	push rbx;
	push rcx;
	push rdx;
	push ax;
	push bx;
	push cx;
	push dx;
	push rsi;
	push rdi;
	push rbp;
	mov rax, CS;
	push rax;
	mov rax, DS;
	push rax;
	mov rax, ES;
	push rax;
	push FS;
	push GS;
	push rsp;
	mov rax, cr0;
	push rax;
	mov rax, cr2;
    push rax;
    mov rax, cr3;
    push rax;
    mov rax, cr4;
    push rax;
    mov rax, cr8;
    push rax;
    mov rax, rsp
    push rax;
    mov rax, ss
    push rax;

popa:
	pop rax;
	mov ss, rax
	pop rsp;
	pop rax
	mov cr8, rax
    pop rax
    mov cr4, rax
    pop rax
    mov cr3, rax
    pop rax
    mov cr2, rax
    pop rax
    mov cr0, rax
	pop rsp;
	pop GS;
	pop FS;
	pop rax;
	mov ES, rax
	pop rax;
	mov DS, rax
	pop rax;
	mov CS, rax
	pop rbp;
	pop rdi;
	pop rsi;
	pop dx;
	pop cx;
	pop bx;
	pop ax;
	pop rdx;
	pop rcx;
	pop rbx;
	pop rax;
