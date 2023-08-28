
extern dataseg
extern codeseg

global disable_paging
global enable_pae
global set_long_mode
global enable_paging
global reloadCS


disable_paging:
  mov rbx, cr0
  and rbx, ~(1 << 31)
  mov cr0, rbx
 
enable_pae:
  mov rdx, cr4
  or  rdx, (1 << 5)
  mov cr4, rdx
 
set_long_mode:
  mov rcx, 0xC0000080
  rdmsr
  or  rax, (1 << 8)
  wrmsr
  pop rax
  ; Replace 'rax' with the appropriate physical address (and flags, if applicable)
  mov rax, rax
  mov cr3, rax
 
enable_paging:
  xor rbx, rbx
  or rbx, (1 << 31) | (1 << 0)
  mov cr0, rbx
 
  mov ax, dataseg
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  
  mov rax, reloadCS
  push qword 0x8
  push rax
  o64 retf
 
[BITS 64]
reloadCS:
  hlt   ; Done. Replace these lines with your own code
  jmp reloadCS
