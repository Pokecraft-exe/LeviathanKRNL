#include "pci.hpp"

namespace pci {

pciPresent PCIs[255 * 32 * 8];
int pciNumber = 0;

uint16_t ReadWord(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset) {
    uint32_t address;
    uint32_t lbus  = (uint32_t)bus;
    uint32_t lslot = (uint32_t)slot;
    uint32_t lfunc = (uint32_t)func;
    
    uint16_t tmp = 0;
    address = (uint32_t)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | (offset & 0xFC) | ((uint32_t)0x80000000));
    Port32Bit(0xCF8).Write(address);
    tmp = (uint16_t)((Port32Bit(0xCFC).Read() >> ((offset & 2) * 8)) & 0xFFFF);
    return tmp;
}

commonHeader readCommonHeader(uint8_t bus, uint8_t slot, uint8_t function) {
    commonHeader header;
    uint8_t byte1;
    uint8_t byte2;

    header.deviceID = ReadWord(bus, slot, function, 0x0);
    header.vendorID = ReadWord(bus, slot, function, 0x2);
    header.status = std::raw_cast<statusRegister>(ReadWord(bus, slot, function, 0x4));
    header.command = std::raw_cast<commandRegister>(ReadWord(bus, slot, function, 0x6));

    byte1 = (ReadWord(bus, slot, function, 0x8) & 0xff00) >> 8;
    byte2 = (ReadWord(bus, slot, function, 0x8) & 0x00ff);
    header.classCode = byte1;
    header.subClass = byte2;

    byte1 = (ReadWord(bus, slot, function, 0xA) & 0xff00) >> 8;
    byte2 = (ReadWord(bus, slot, function, 0xA) & 0x00ff);
    header.progIF = byte1;
    header.revisionID = byte2;

    byte1 = (ReadWord(bus, slot, function, 0xA) & 0xff00) >> 8;
    byte2 = (ReadWord(bus, slot, function, 0xA) & 0x00ff);
    header.BIST = std::raw_cast<BIST_register>(byte1);
    header.headerType = byte2;

    byte1 = (ReadWord(bus, slot, function, 0xE) & 0xff00) >> 8;
    byte2 = (ReadWord(bus, slot, function, 0xE) & 0x00ff);
    header.latencyTimer = byte1;
    header.cacheLineSize = byte2;

    return header;
}
 
uint16_t CheckVendor(uint8_t bus, uint8_t slot) {
    return ReadWord(bus, slot, 0, 0x2);
}

int GetPresent() {
    int i = 0;
    for (int y = 0; y < busesPerPCI; y++) {
        for (int x = 0; x < slotPerBuses; x++) {
            for (int z = 0; z < 8; z++) {
                if (ReadWord(y, x, z, 0x2) != 0xFFFF) {
                    PCIs[i].bus = y;
                    PCIs[i].slot = x;
                    PCIs[i].function = z;
                    i++;
                }
            }
        }
    }
    pciNumber = i;
    return i;
}

}
