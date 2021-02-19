section .text

SetUpPaging:
	GLOBAL Total_paged
	mov ax, Total_paged
	add ax, 4
	mov Total_paged, ax
	mov eax, PageTableL3
	or eax, 0b11
	mov [PageTableL4], eax

	mov ax, Total_paged
	add ax, 4
	mov Total_paged, ax
	mov eax, PageTableL2
	or eax, 0b11
	mov [PageTableL3], eax

	mov ecx, 0

.looop:
	mov ax, Total_paged
	add ax, 16000
	mov Total_paged, ax
	mov eax, 0x200000
	mul ecx
	or eax, 0b10000011
	mov [PageTableL2 + ecx * 8], eax

	inc ecx
	cmp ecx, 512
	jne .looop
	ret

enable_paging:
	mov eax, PageTableL4
	mov cr3, eax

	mov eax, cr4
	or eax, 1 << 5
	mov cr4, eax

	mov ecx, 0xC0000080
	rdmsr
	or eax, 1 << 8
	wrmsr

	mov eax, cr0
	or eax, 1 << 31
	mov cr0, eax
	
	ret

section .bss
align 4096
PageTableL4:
	resb 4096
PageTableL3:
	resb 4096
PageTableL2:
	resb 4096

section .data
Total_paged:
	dw 0
