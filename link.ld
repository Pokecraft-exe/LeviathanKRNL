OUTPUT_FORMAT(elf64-x86-64)
OUTPUT_ARCH(i386:x86-64)
 
ENTRY(_start)
 
PHDRS
{
    text    PT_LOAD    FLAGS((1 << 0) | (1 << 1) | (1 << 2)) ; /* Execute + Read */
    rodata  PT_LOAD    FLAGS((1 << 2)) ;            /* Read only */
    data    PT_LOAD    FLAGS((1 << 1) | (1 << 2)) ; /* Write + Read */
    idt     PT_LOAD    FLAGS((1 << 1) | (1 << 2));
}
 
SECTIONS
{
    . = 0xffffffff80000000;
 	
    .text : {
        pit_handler = .;
        isr0 = .;
	isr1 = .;
	isr2 = .;
	isr3 = .;
	isr4 = .;
	isr5 = .;
	isr6 = .;
	isr7 = .;
	isr8 = .;
	isr9 = .;
	isr10 = .;
	isr11 = .;
	isr12 = .;
	isr13 = .;
	isr14 = .;
	isr16 = .;
	isr17 = .;
	isr18 = .;
	isr19 = .;
	isr20 = .;
	isr21 = .;
	isr28 = .;
	isr29 = .;
	isr30 = .;
        *(.text .text.*)
    } :text
    
    . += CONSTANT(MAXPAGESIZE);
 
    .rodata : {
        *(.rodata .rodata.*)
    } :rodata
 
    . += CONSTANT(MAXPAGESIZE);
 
    .data : {
        *(.data .data.*)
    } :data
 
    .bss : {
        *(COMMON)
        *(.bss .bss.*)
        . = ALIGN(8);
    } :data
 
    /DISCARD/ : {
        *(.eh_frame)
        *(.note .note.*)
    }
    HEAP = . ;
}
