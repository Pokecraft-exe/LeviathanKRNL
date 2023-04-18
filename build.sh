rm *.flp
rm ASM/*.bin
rm Cpp/o/*.o
rm ASM/*.o

nasm ASM/boot2.s -f bin -o ASM/boot2.bin
nasm ASM/ExtendedProgram.s -f elf64 -o ASM/ExtendedProgram.o
nasm ASM/binaries.s -f elf64 -o ASM/binaries.o

cd Cpp/o/
x86_64-elf-gcc -g -ffreestanding -mno-red-zone -m64 -c ../IDT.cpp ../errors.cpp -O0 -mgeneral-regs-only 
x86_64-elf-gcc -g -ffreestanding -mno-red-zone -m64 -c ../Kernel.cpp ../string.cpp ../IO.cpp ../KBscancodes.cpp ../printf.cpp ../sound.cpp ../mouse.cpp ../serial.cpp ../lalloc.cpp
cd ../..

x86_64-elf-ld -T"link2.ld"

echo =====================
echo creating a floppy file
echo =====================
cat ASM/boot2.bin Kernel.bin > boot.flp
