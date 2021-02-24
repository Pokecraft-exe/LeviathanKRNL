rm *.iso
rm *.flp
nasm ASM/boot2.s -f bin -o ASM/boot2.bin
nasm ASM/ExtendedProgram.s -f elf64 -o ASM/ExtendedProgram.o
nasm ASM/binaries.s -f elf64 -o ASM/binaries.o

x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/Kernel.cpp" -o "Cpp/Kernel.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/IDT.cpp" -o "Cpp/IDT.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/IO.cpp" -o "Cpp/IO.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/KBscancodes.cpp" -o "Cpp/KBscancodes.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/Memory.cpp" -o "Cpp/Memory.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/printf.cpp" -o "Cpp/printf.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/sound.cpp" -o "Cpp/sound.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/Heap.cpp" -o "Cpp/Heap.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/vga.cpp" -o "Cpp/vga.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/Font.cpp" -o "Cpp/Font.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/mouse.cpp" -o "Cpp/Mouse.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/3D.cpp" -o "Cpp/3D.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/math.cpp" -o "Cpp/math.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/serial.cpp" -o "Cpp/serial.o"

x86_64-elf-ld -T"link2.ld"

cat ASM/boot2.bin Kernel.bin > boot.flp
cat ASM/boot2.bin Kernel.bin > boot.iso
rm ASM/*.bin
rm Cpp/*.o
rm ASM/*.o

nasm ASM/compaq.s -f bin -o ASM/boot2.bin
nasm ASM/ExtendedProgram.s -f elf64 -o ASM/ExtendedProgram.o
nasm ASM/binaries.s -f elf64 -o ASM/binaries.o

x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/Kernel.cpp" -o "Cpp/Kernel.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/IDT.cpp" -o "Cpp/IDT.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/IO.cpp" -o "Cpp/IO.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/KBscancodes.cpp" -o "Cpp/KBscancodes.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/Memory.cpp" -o "Cpp/Memory.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/printf.cpp" -o "Cpp/printf.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/sound.cpp" -o "Cpp/sound.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/Heap.cpp" -o "Cpp/Heap.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/vga.cpp" -o "Cpp/vga.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/Font.cpp" -o "Cpp/Font.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/mouse.cpp" -o "Cpp/Mouse.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/3D.cpp" -o "Cpp/3D.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/math.cpp" -o "Cpp/math.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/serial.cpp" -o "Cpp/serial.o"
x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Cpp/cstring.cpp" -o "Cpp/cstring.o"

x86_64-elf-ld -T"link2.ld"

cat ASM/boot2.bin Kernel.bin > compaq.flp
cat ASM/boot2.bin Kernel.bin > compaq.iso
rm ASM/*.bin
rm Cpp/*.o
rm ASM/*.o
git add *
git commit -m"automatik pu$h"
git push
