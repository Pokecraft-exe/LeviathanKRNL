#include "ahci.hpp"
using std::cout;
#define ATA_MASTER 0x00
#define ATA_SLAVE 0x01
#define ATA_PRIMARY_IO 0x1F0
#define ATA_SECONDARY_IO 0x170
#define ATA_PRIMARY 0x00
#define ATA_SECONDARY 0x01
#define ATA_READ 0x00
#define ATA_WRITE 0x013

void ide_select_drive(uint8_t bus, uint8_t i)
{
	if(bus == ATA_PRIMARY)
		if(i == ATA_MASTER)
			Port8Bit(ATA_PRIMARY_IO + 0x06).Write(0xA0);
		else Port8Bit(ATA_PRIMARY_IO + 0x06).Write(0xB0);
	else
		if(i == ATA_MASTER)
			Port8Bit(ATA_SECONDARY_IO + 0x06).Write(0xA0);
		else Port8Bit(ATA_SECONDARY_IO + 0x06).Write(0xB0);
}

uint8_t ide_identify(uint8_t bus, uint8_t slot)
{
	uint16_t io = 0;
	ide_select_drive(bus, slot);
	if(bus == ATA_PRIMARY) io = ATA_PRIMARY_IO;
	else io = ATA_SECONDARY_IO;

	Port8Bit(io + 0x02).Write(0);
	Port8Bit(io + 0x03).Write(0);
	Port8Bit(io + 0x04).Write(0);
	Port8Bit(io + 0x05).Write(0);
	Port8Bit(io + 0x07).Write(0xEC);

	uint8_t status = Port8Bit(io + 0x07).Read();
	if(status)
	{
		while(Port8Bit(io + 0x07).Read() & 0x80 != 0);
		ahci_read:
		status = Port8Bit(io + 0x07).Read();
		if(status & 0x80)
		{
			cout << "AHCI " << ((bus==ATA_PRIMARY)?"Primary":"Secondary") << ' ' << ((slot==ATA_PRIMARY)?" master":" slave") << " has ERR set\n";
			return 0;
		}
		while(!(status & 0x08)) goto ahci_read;
		cout << "AHCI " << ((bus==ATA_PRIMARY)?"Primary":"Secondary") << ' ' << ((slot==ATA_PRIMARY)?" master":" slave") << " is OK\n";

		// read the data : io + ATA_REG_DATA
	}
}

ahci ahciController[10] = {0};
pci::commonHeader ahciControllerHeaders[10] = {0};
uint8_t ahciNumber = 0;

pci::header0* readAHCI(int ahcinum) {
	pci::header0* header = nullptr;
	pci::commonHeader common = ahciControllerHeaders[ahcinum];
	if (common.headerType == 0x0) {
		cout << "ahci " << ahcinum << " headertype of 0x0\n";
		pci::header0 header0 = pci::readHeader0(ahciController[ahcinum].bus, ahciController[ahcinum].slot, ahciController[ahcinum].function, ahciControllerHeaders[ahcinum]);
		cout << "ahci " << ahcinum << " .AHCIBaseMemory " << (void*)header0.BAR5.alignedBaseAddress << "\n";
	}
	else {
		cout << "[\0m[\xff\0\0]Error\0m[\xff\xff\xff\0]]\n";
		cout.color(0xffffff);
		cout << "ahci " << ahcinum << " invalid header type:" << std::hex(common.headerType) << '\n';
		asm("hlt");
		while(1);
	}
	return header;
}

int findAHCI() {
	int i = 0;
    for (int j = 0; j < pci::pciNumber; j++) {
		pci::commonHeader header = pci::readCommonHeader(pci::PCIs[j].bus, pci::PCIs[j].slot, pci::PCIs[j].function);
		
        if (header.classCode == 0x1) { // is controller storage class?
	        if (header.subClass == 0x6 || header.subClass == 0x1) { // is sata or IDE?
				ahciController[i].bus = pci::PCIs[j].bus;
				ahciController[i].slot = pci::PCIs[j].slot;
				ahciController[i].function = pci::PCIs[j].function;
				ahciControllerHeaders[i] = header;
				readAHCI(i);
				i++;
            }
		}
    }
	ahciNumber = i;
	return i;
}
