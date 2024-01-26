#include "IDT.h"
using std::cout;

IDTR idtTable;

__attribute__((aligned(0x10)))
IDT64 IDTs[256] = {};
  
void InitIDT(){
    idtTable.address = (uint64_t)&IDTs[0];
    idtTable.size = 0x0fff;

    asm("lidt %0" :: "m"(idtTable));
    asm ("sti");

    RemapPic(0b00100000,0b00000011);
}

void add_IRQ(uint8_t IRQ, void* function, uint8_t gate) {
  	//IRQ_clear_mask(IRQ);	
	IDTs[IRQ].offset_low  = (uint16_t)(((uint64_t)function & 0x000000000000ffff));
	IDTs[IRQ].offset_mid  = (uint16_t)(((uint64_t)function & 0x00000000ffff0000) >> 16);
	IDTs[IRQ].offset_high = (uint32_t)(((uint64_t)function & 0xffffffff00000000) >> 32);
	IDTs[IRQ].types_attr = 0b10000000 | gate;
	IDTs[IRQ].codeseg = 0x8;
}

int mouseX = 0;
int mouseY = 50;

__attribute__((interrupt)) void keyboardHandler(interrupt_frame* frame) {
	uint8_t scanCode = inb(0x60);
	uint8_t chr = 0;

	if (KEY == 0) {
		Keyboardhandler(scanCode);
		if (scanCode == 0x1C) KEY = 10;
		else if (scanCode == 0x0E) KEY = 127;
	}
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}

__attribute__((interrupt)) void mouseHandler(interrupt_frame* frame) {
	bool isMouse = true;//(inb(0x64) & 0x20) >> 5;
	/*if (isMouse) {
		uint8_t byte1 = inb(0x60);
		uint8_t byte2 = inb(0x60);
		uint8_t byte3 = inb(0x60);
		if (byte1 & 0b00100000) {
			mouseX -= byte2;
		} else {
			mouseX += byte2;
		}
	}*/
	DrawChar('^', mouseX, mouseY, 0xffffff, 1);
	outb(0x20, 0x20);
	outb(0xa0, 0x20);
}

char pollKey(char* e) {
	*e = KEY;
	KEY = 0;
	return *e;
}

void print(char* str) {
    uint32_t c = cout.color();
    cout.color(0xff0000);
	cout << str;
	cout.color(c);
}

__attribute__((interrupt)) void isr0(interrupt_frame* frame) {print("division by 0");};
__attribute__((interrupt)) void isr1(interrupt_frame* frame) {print("debug");};
__attribute__((interrupt)) void isr2(interrupt_frame* frame) {print("nmi");;};
__attribute__((interrupt)) void isr3(interrupt_frame* frame) {print("breakpoint");};
__attribute__((interrupt)) void isr4(interrupt_frame* frame) {print("overflow");};
__attribute__((interrupt)) void isr5(interrupt_frame* frame) {print("table overload");};
__attribute__((interrupt)) void isr6(interrupt_frame* frame) {print("fake instruction");};
__attribute__((interrupt)) void isr7(interrupt_frame* frame) {print("FPU don't exist");};
__attribute__((interrupt)) void isr8(interrupt_frame* frame) {print("double fault");};
__attribute__((interrupt)) void isr9(interrupt_frame* frame) {print("coprocessor segment overrun");};
__attribute__((interrupt)) void isr10(interrupt_frame* frame) {print("invalid TSS");};
__attribute__((interrupt)) void isr11(interrupt_frame* frame) {print("segment not present");};
__attribute__((interrupt)) void isr12(interrupt_frame* frame) {print("stack-segment fault");};
__attribute__((interrupt)) void isr13(interrupt_frame* frame, unsigned long errorcode) {
	//cls(0x0000FF);
	register uint64_t* rsp asm("rsp");
	cout.color(0xffffff);
	cout << "General protection fault!\nError code: 0x" << std::hex(errorcode) << std::endl;
	if (rsp != 0) {
		limine_memmap_entry* last = memmap::memmap.entries[0];
		for (size_t i = 1; i < memmap::memmap.entry_count; i++) {
			if ((uint64_t*)last->base < rsp && (uint64_t*)memmap::memmap.entries[i]->base > rsp) {
				DrawStringBackground(memmap::get_memory_type(last), 0, 48, 2, 0xFFFFFF, 0x0000FF, 1);
				break;
			}
		}
	}
	if(*rsp & 1) {
		DrawStringBackground("This error is external to the processor", 0, 40, 2, 0xFFFFFF, 0x0000FF, 1);
	} else {
	    DrawStringBackground("This error is internal to the processor", 0, 40, 2, 0xFFFFFF, 0x0000FF, 1);
	}
	while(inb(0x60) != 0x5E);
	restart();
};
extern "C" void endTextSection();
__attribute__((interrupt)) void isr14(interrupt_frame* frame) {
	getState();
	CPUState errorState = GlobalCPUState;
	//cls(0x0000FF);
	cout << "\0m[\xff\xff\xff]PageFault!" << std::endl;
	asm("mov %rax, %cr2");
	gregister(rax);
	uint64_t* memory = (uint64_t*)rax;
	if (memory != nullptr) {
	    cout << "memory dump at CR2 = " << (void*)memory << std::endl;
	    cout << std::hex(*(memory-8)) << " " << std::hex(*memory) << " " << std::hex(*(memory+8)) << std::endl;
		cout << "\ninterpret string:\n";
		for (char* address = (char*)(memory-9); address < (char*)(memory+8); cout << (char)*(address++));
		cout << "\n\nrflags=" << std::hex(errorState.rflags) << std::endl;
		cout << "rip=" << std::hex(frame->rip) << std::endl;
		cout << "rax=" << std::hex(errorState.rax) << std::endl;
		if ((uint64_t)memory > (uint64_t)&endTextSection) {
			cout << "\n \0m[\xff\xff\0\0]exception in data section\n";
		} else if ((uint64_t)memory < (uint64_t)0xffffffff80000000) {
			cout << "\n \0m[\xff\xff\0\0]exception below text section\n";
		} else {
			cout << "\n \0m[\xff\xff\0\0]exception in text section\n";
		}

	} else {
	    cout << "no memory dump for software interrupts" << std::endl;
	}
	while(1);
};
__attribute__((interrupt)) void isr16(interrupt_frame* frame) {print("float exception");};
__attribute__((interrupt)) void isr17(interrupt_frame* frame) {print("alignement check");};
__attribute__((interrupt)) void isr18(interrupt_frame* frame) {print("machine check");};
__attribute__((interrupt)) void isr19(interrupt_frame* frame) {print("SMID float exception");};
__attribute__((interrupt)) void isr20(interrupt_frame* frame) {print("virtualization exception");};
__attribute__((interrupt)) void isr21(interrupt_frame* frame) {print("control protection exception");};
__attribute__((interrupt)) void isr28(interrupt_frame* frame) {print("hypervisor injection exception");};
__attribute__((interrupt)) void isr29(interrupt_frame* frame) {print("VMM communication error");};
__attribute__((interrupt)) void isr30(interrupt_frame* frame) {print("Security exception");};
