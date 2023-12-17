KERNEL = boot.elf
 
$(eval $(call DEFAULT_VAR,CC,x86_64-elf-gcc))
$(eval $(call DEFAULT_VAR,DC,x86_64-elf-gdc))
$(eval $(call DEFAULT_VAR,LD,x86_64-elf-ld))
 
SRCDIR := src
OBJDIR := obj
HEADDIR := headers

DFLAGS = -h

CFLAGS += -g -ffreestanding -mno-red-zone -m64 -I $(HEADDIR)
 
LDFLAGS = -nostdlib -static -m elf_x86_64 -z max-page-size=0x1000 -T link.ld
 
NASMFLAGS = -Wall -f elf64

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d)) 

SRC = $(call rwildcard,$(SRCDIR), *.c)
CPPSRC += $(call rwildcard,$(SRCDIR), *.cpp)
SSRC += $(call rwildcard,$(SRCDIR), *.s)
LSSRC += $(call rwildcard,$(SRCDIR), *.ls)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
OBJ += $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(CPPSRC))
OBJ += $(patsubst $(SRCDIR)/%.ls, $(OBJDIR)/%.obj, $(LSSRC))
OBJ += $(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(SSRC))
 
all: $(KERNEL)
 
$(KERNEL): $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) -o $@
	cp -v boot.elf iso_root/
	if rm image.iso; then \
		xorriso -as mkisofs -b limine-bios-cd.bin \
        	-no-emul-boot -boot-load-size 4 -boot-info-table \
        	--efi-boot limine-uefi-cd.bin \
        	-efi-boot-part --efi-boot-image --protective-msdos-label \
        	iso_root -o image.iso; \
	else \
		echo "\033[38;2;255;0;0m image.iso does not exist or was already removed\033[0m "; \
		xorriso -as mkisofs -b limine-bios-cd.bin \
        	-no-emul-boot -boot-load-size 4 -boot-info-table \
        	--efi-boot limine-uefi-cd.bin \
        	-efi-boot-part --efi-boot-image --protective-msdos-label \
        	iso_root -o image.iso; \
 	fi
	./limine/limine bios-install image.iso
	rm iso_root/boot.elf boot.elf
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -std=gnu11 -c $^ -o $@
	
$(OBJDIR)/allocator.o: $(SRCDIR)/allocator.cpp
	$(CC) $(CFLAGS) -mcmodel=large -c "$(SRCDIR)/allocator.cpp" -o "$(OBJDIR)/allocator.o"

$(OBJDIR)/IDT.o: $(SRCDIR)/IDT.cpp
	$(CC) $(CFLAGS) -mgeneral-regs-only -c "$(SRCDIR)/IDT.cpp" -o "$(OBJDIR)/IDT.o"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^ -o $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.d
	$(DC) $(DFLAGS) $(CPPFLAGS) -c $<
 
$(OBJDIR)/%.o: $(SRCDIR)/%.s
	nasm $(NASMFLAGS) $< -o $@
	
$(OBJDIR)/%.obj: $(SRCDIR)/%.ls
	lscc $< -o $@ -f elf64 -cc SysV

clear:
	rm iso_root/boot.elf boot.elf $(OBJ)
