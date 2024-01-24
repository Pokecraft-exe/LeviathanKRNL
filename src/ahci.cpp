#include "ahci.hpp"
using std::cout;

int check_type(HBA_PORT *port)
{
	uint32_t ssts = port->ssts;
 
	uint8_t ipm = (ssts >> 8) & 0x0F;
	uint8_t det = ssts & 0x0F;
 
	if (det != HBA_PORT_DET_PRESENT)	// Check drive status
		return AHCI_DEV_NULL;
	if (ipm != HBA_PORT_IPM_ACTIVE)
		return AHCI_DEV_NULL;
 
	switch (port->sig)
	{
	case SATA_SIG_ATAPI:
		return AHCI_DEV_SATAPI;
	case SATA_SIG_SEMB:
		return AHCI_DEV_SEMB;
	case SATA_SIG_PM:
		return AHCI_DEV_PM;
	default:
		return AHCI_DEV_SATA;
	}
}

void probe_port(HBA_MEM *abar)
{
	// Search disk in implemented ports
	uint32_t pi = abar->pi;
	int i = 0;
	while (i<32)
	{
		if (pi & 1)
		{
			int dt = check_type(&abar->ports[i]);
			if (dt == AHCI_DEV_SATA)
			{
				cout << "SATA drive found at port" << i << std::endl;
			}
			else if (dt == AHCI_DEV_SATAPI)
			{
				cout << "SATAPI drive found at port" << i << std::endl;
			}
			else if (dt == AHCI_DEV_SEMB)
			{
				cout << "SEMB drive found at port" << i << std::endl;
			}
			else if (dt == AHCI_DEV_PM)
			{
				cout << "PM drive found at port" << i << std::endl;
			}
			else
			{
				cout << "";
			}
		}
 
		pi >>= 1;
		i ++;
	}
}

ahci ahciController[10] = {0};
uint8_t ahciNumber = 0;

pci::commonHeader* readAHCI(int ahcinum) {
	pci::commonHeader* header = nullptr;
	if (ahcinum <= ahciNumber) {
		uint8_t bus = ahciController[ahcinum].bus;
		uint8_t slot = ahciController[ahcinum].slot;
		uint8_t function = ahciController[ahcinum].function;
		
		pci::commonHeader common = pci::readCommonHeader(bus, slot, function);
		if (common.headerType == 0x0) {
			cout << "ahci " << ahcinum << " headertype of 0x0\n";
			//pci::header0
		}
		if (common.headerType == 0x1) {
			cout << "ahci " << ahcinum << " headertype of 0x1\n";
			//pci::header1
		}
		if (common.headerType == 0x2) {
			cout << "ahci " << ahcinum << " headertype of 0x2\n";
			//pci::header2
		}
	}
	return header;
}

int findAHCI() {
	int i = 0;
    for (int j = 0; j < pci::pciNumber; j++) {
		uint16_t word = pci::ReadWord(pci::PCIs[j].bus, pci::PCIs[j].slot, pci::PCIs[j].function, 0x8);
		uint8_t baseClass = (word & 0xff00) >> 8;
		uint8_t subClass = (word & 0x00ff);
        if (baseClass == 0x1) { // is controller storage class?
			cout << "subclass: " << std::hex(subClass) << std::endl;
	        if (subClass == 0x6 || subClass == 0x1) { // is sata or IDE?
				ahciController[i].bus = pci::PCIs[j].bus;
				ahciController[i].slot = pci::PCIs[j].slot;
				ahciController[i].function = pci::PCIs[j].function;
				//readAHCI(i);
				i++;
            }
		}
    }
	ahciNumber = i;
	return i;
}
