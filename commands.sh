nasm boot.s -f bin -o boot.bin
nasm ExtendedProgram.s -f elf64 -o ExtendedProgram.o
nasm binaries.s -f elf64 -o binaries.o

x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Kernel.cpp" -o "Kernel.o"

x86_64-elf-ld -T"link.ld"

cat boot.bin Kernel.bin > boot.flp
qemu-system-x86_64 -soundhw pcspk boot.flp
rm *.bin
rm *.o

