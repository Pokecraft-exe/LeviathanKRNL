#include "pci.hpp"

namespace pci {

bool present[busesPerPCI * slotPerBuses] = {};

uint16_t ReadWord(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset) {
    uint32_t address;
    uint32_t lbus  = (uint32_t)bus;
    uint32_t lslot = (uint32_t)slot;
    uint32_t lfunc = (uint32_t)func;
    uint16_t tmp = 0;
    address = (uint32_t)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | (offset & 0xFC) | ((uint32_t)0x80000000));
    Port32Bit port(0xCF8);
    port.Write(address);
    tmp = (uint16_t)((port.Read() >> ((offset & 2) * 8)) & 0xFFFF);
    return tmp;
}
 
uint16_t CheckVendor(uint8_t bus, uint8_t slot) {
    return ReadWord(bus, slot, 0, 2);
}

int GetPresent() {
    int i = 0;
    for (int y = 0; y < busesPerPCI - 1; y++) {
        for (int x = 0; x < slotPerBuses - 1; x++) {
            if (ReadWord(y, x, 0, 2) != 0xFFFF) {
                //present[y * busesPerPCI + x] = true;
                i++;
            }
        }
    }
    
    return i;
}

}
