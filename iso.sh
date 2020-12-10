rm *.iso
nasm ASM/boot.s -f bin -o ASM/boot.bin
nasm ASM/ExtendedProgram.s -f elf64 -o ASM/ExtendedProgram.o
nasm ASM/binaries.s -f elf64 -o ASM/binaries.o

x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/Kernel.cpp" -o "Cpp/Kernel.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/IDT.cpp" -o "Cpp/IDT.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/IO.cpp" -o "Cpp/IO.o"

x86_64-elf-ld -T"link.ld"

cat ASM/boot.bin Kernel.bin > Kernel.flp
dd if=Kernel.flp of=Kernel.iso bs=512 conv=notrunc
rm *.flp
rm ASM/*.bin
rm *.bin
rm ASM/*.o
rm Cpp/*.o
qemu-system-x86_64 -soundhw pcspk Kernel.iso


