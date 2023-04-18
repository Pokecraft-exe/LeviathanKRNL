KERNEL = boot.elf
 
$(eval $(call DEFAULT_VAR,CC,x86_64-elf-gcc))
$(eval $(call DEFAULT_VAR,DC,x86_64-elf-gdc))
$(eval $(call DEFAULT_VAR,LD,x86_64-elf-ld))
 
SRCDIR := src
OBJDIR := obj
HEADDIR := headers

DFLAGS = -h

CFLAGS += -g -ffreestanding -mno-red-zone -m64
 
LDFLAGS = -nostdlib -static -m elf_x86_64 -z max-page-size=0x1000 -T link.ld
 
NASMFLAGS = -Wall -f elf64

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d)) 

SRC = $(call rwildcard,$(SRCDIR), *.c)
CPPSRC += $(call rwildcard,$(SRCDIR), *.cpp)
SSRC += $(call rwildcard,$(SRCDIR), *.s)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
OBJ += $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(CPPSRC))
OBJ += $(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(SSRC))
 
all: $(KERNEL)
 
$(KERNEL): $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) -o $@
	cp -v boot.elf limine/iso_root/
 
	xorriso -as mkisofs -b limine-cd.bin \
        -no-emul-boot -boot-load-size 4 -boot-info-table \
        --efi-boot limine-cd-efi.bin \
        -efi-boot-part --efi-boot-image --protective-msdos-label \
        limine/iso_root -o image.iso
 
	./limine/limine-deploy image.iso
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -std=gnu11 -c $^ -o $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^ -o $@
	
$(OBJDIR)/%.o: $(SRCDIR)/%.d
	$(DC) $(DFLAGS) $(CPPFLAGS) -c $<
 
$(OBJDIR)/%.o: $(SRCDIR)/%.s
	nasm $(NASMFLAGS) $< -o $@

clear:
	rm image.iso limine/iso_root/boot.elf boot.elf $(OBJ)
