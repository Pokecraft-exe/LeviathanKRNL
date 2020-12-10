OUTPUT_FORMAT(binary)

ENTRY (_start)

INPUT
(
    ASM/ExtendedProgram.o
    Cpp/Kernel.o
    Cpp/IDT.o
    Cpp/IO.o
    ASM/binaries.o
)

OUTPUT
(
  Kernel.bin
)

SECTIONS
{
    . = 0x8000;

    .text : ALIGN(0x1000)
    {
      *(.text)
    }
    .idt BLOCK(0x1000) : ALIGN(0x1000)
    {
      _idt = .;
      . = . + 0x1000;
    }
    .data : ALIGN(0x1000)
    {
      *(.data)
    }

    .rodata : ALIGN(0x1000)
    {
      *(.rodata)
    }

    .bss : ALIGN(0x1000)
    {
    *(COMMON)
    *(.bss)
    }


}
