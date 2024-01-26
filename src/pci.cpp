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

    offset+=2;

    address = (uint32_t)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | ((offset) & 0xFC) | ((uint32_t)0x80000000));

    Port32Bit(0xCF8).Write(address);

    tmp = (uint16_t)((Port32Bit(0xCFC).Read() >> ((offset & 2) * 8)) & 0xFFFF);
    return tmp;
}

uint32_t ReadDoubleWord(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset) {
    uint32_t address;
    uint32_t lbus  = (uint32_t)bus;
    uint32_t lslot = (uint32_t)slot;
    uint32_t lfunc = (uint32_t)func;
    uint32_t tmp = 0;

    offset+=2;

    address = (uint32_t)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | ((offset) & 0xFC) | ((uint32_t)0x80000000));

    Port32Bit(0xCF8).Write(address);

    tmp = (Port32Bit(0xCFC).Read() >> ((offset & 2) * 8));
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

    byte1 = (ReadWord(bus, slot, function, 0xC) & 0xff00) >> 8;
    byte2 = (ReadWord(bus, slot, function, 0xC) & 0x00ff);
    header.BIST = std::raw_cast<BIST_register>(byte1);
    header.headerType = byte2;

    byte1 = (ReadWord(bus, slot, function, 0xE) & 0xff00) >> 8;
    byte2 = (ReadWord(bus, slot, function, 0xE) & 0x00ff);
    header.latencyTimer = byte1;
    header.cacheLineSize = byte2;

    return header;
}

header0 readHeader0(uint8_t bus, uint8_t slot, uint8_t function, commonHeader common) {
    header0 header;
    uint8_t byte1;
    uint8_t byte2;

    header = std::raw_cast<header0>(common);
    header.BAR0 = std::raw_cast<BARlayout>(ReadDoubleWord(bus, slot, function, 0x10));
    header.BAR1 = std::raw_cast<BARlayout>(ReadDoubleWord(bus, slot, function, 0x14));
    header.BAR2 = std::raw_cast<BARlayout>(ReadDoubleWord(bus, slot, function, 0x18));
    header.BAR3 = std::raw_cast<BARlayout>(ReadDoubleWord(bus, slot, function, 0x1C));
    header.BAR4 = std::raw_cast<BARlayout>(ReadDoubleWord(bus, slot, function, 0x20));
    header.BAR5 = std::raw_cast<BARlayout>(ReadDoubleWord(bus, slot, function, 0x24));
    header.cadbusCISpointer = ReadDoubleWord(bus, slot, function, 0x26);
    header.subsystemID = ReadWord(bus, slot, function, 0x2C);
    header.subsystemVendorID = ReadWord(bus, slot, function, 0x2E);
    header.expansionROMbaseAddress = ReadDoubleWord(bus, slot, function, 0x30);

    byte2 = (ReadWord(bus, slot, function, 0x38) & 0x00ff);
    header.capabilitiesPointer = byte2;

    byte1 = (ReadWord(bus, slot, function, 0x3C) & 0xff00) >> 8;
    byte2 = (ReadWord(bus, slot, function, 0x3C) & 0x00ff);
    header.maxLatency = byte1;
    header.minGrant = byte2;

    byte1 = (ReadWord(bus, slot, function, 0x3E) & 0xff00) >> 8;
    byte2 = (ReadWord(bus, slot, function, 0x3E) & 0x00ff);
    header.interruptPIN = byte1;
    header.interruptLine = byte2;

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
