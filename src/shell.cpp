#include "shell.hpp"
#include "font.hpp"
#include "ahci.hpp"
#include "pci.hpp"
using std::cout, std::cin;

extern "C" void DrawSquare(int x, int y, int size_x, int size_y, uint32_t color);

uint64_t formatbytes(uint64_t bytes) {
    if (bytes < 1024) {
        return bytes;
    }
    else {
        size_t size = 1024;
        for (size_t i = 0; bytes / size > 1024; i++) {
            size *= 1024;
        }
        return bytes / size;
    };
}

char* getByteFormat(uint64_t bytes) {
    char* arr[7] = { " B", " KB", " MB", "GB", " TB", " PB", " HB"};
    if (bytes < 1024) {
        return arr[0];
    }
    else {
        size_t size = 1024;
        size_t i = 1;
        for (i; bytes / size > 1024; i++) {
            size *= 1024;
        }
        return arr[i];
    };
}

extern bool CursorShown;

void drawTextCursor(){
    while (1) {
        printchr('_');
        CursorShown = true;
        timer::PIT::wait(1000);
        deletechr();
        CursorShown = false;
        timer::PIT::wait(1000);
    }
}

string command = "";
void colorchange() {
    uint32_t c = 0x000000ff;
    while(1) 
        DrawSquare(200, 400, 200, 300, c++);
}

void reboot()
{
    uint8_t good = 0x02;
    while (good & 0x02)
        good = inb(0x64);
    outb(0x64, 0xFE);
    asm("hlt");
}

void shell() {

    TaskManager::Task* colorThread = TaskManager::Thread((void*)&colorchange, nullptr, 0);
    TaskManager::Task* cursorThread = TaskManager::Thread((void*)&drawTextCursor, nullptr, 0);

    colorThread->start();

    cout << pci::GetPresent() << " PCI slots present\n";
    int ahcinum = findAHCI();
    cout << "there is " << ahcinum << " ahci sata / ide controller present\n";

    cout << "\n\ntype \"help\" to get the list of avaliable commands\n";

    cout << '>';

    breakpoint();

    while(1) {
        cursorThread->start();
        cin >> command;
        breakpoint();
        cursorThread->stop();
        cout << '\n';
        if (command == "cls") cls(0);
        if (command == "memmap") {
            cout.color(0xffff00);
            cout << "free memory: " << formatbytes(paging::getFreeMemory()) << getByteFormat(paging::getFreeMemory()) << std::endl;
            cout << "used memory: " << formatbytes(paging::getUsedMemory()) << getByteFormat(paging::getUsedMemory()) << std::endl;
            cout << "system memory: " << formatbytes(paging::getSystemMemory()) << getByteFormat(paging::getSystemMemory()) << std::endl;
            cout.color(0xffffff);
        }
        if (command == "credit") {
            cout << "\0m[\xff\xff\xaa]Leviathan Kernel(c) is a property of Pokecraft-exe AKA \nPokechaNyaa, Julian Lavis--Fabbri\n";
            cout.color(0xffffff);
        }
        if (command == "reboot") reboot();
        if (command == "qshutdown") Port16Bit(0x604).Write(0x2000);
        if (command == "usb") {
            int i = 0;
            for (int j = 0; j < pci::pciNumber; j++) {
		        uint16_t word = pci::ReadWord(pci::PCIs[j].bus, pci::PCIs[j].slot, pci::PCIs[j].function, 0x8);
		        uint8_t baseClass = (word & 0xff00) >> 8;
		        uint8_t subClass = (word & 0x00ff);
                if (baseClass == 0xC) { // is serial bus class?
	                if (subClass == 0x3) { // is USB?
				        i++;
                    }
		        }
            }
            cout << "there is " << i << " USB controller present\n";
        }
        if (command == "help") {
            cout << "cls        - clear the shell\n";
            cout << "memmap     - display the memory usage\n";
            cout << "credit     - display the author\n";
            cout << "reboot     - do i have to explain?\n";
            cout << "qshutsowd  - shutdown for qemu\n";
            cout << "usb        - display the number of usb devices\n";
            cout << "colorstart - start a new thread\n";
            cout << "colorstop  - stop that thread\n";
        }
        if (command == "color start") colorThread->start();
        if (command == "color stop") colorThread->stop();
        if (command == "taskmgr dump") TaskManager::dump();
        cout << '>';
    };
}