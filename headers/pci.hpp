#pragma once
#include "IO.h"
#include "lalgorythm"
#define functionPerSlots 8
#define slotPerBuses 32
#define busesPerPCI 256

namespace pci {

struct pciPresent {
	uint8_t bus : 8;
	uint8_t slot : 5;
	uint8_t function : 3;
};

struct BARlayout {
    bool zero : 1;
    uint8_t type : 2;
    bool prefetchable : 1;
    uint32_t alignedBaseAddress : 28;
};

struct IOBARlayout {
    bool one : 1;
    bool : 1;
    uint32_t alignedBaseAddress : 30;
};

struct commandRegister {
    bool IOspace : 1;
    bool memorySpace : 1;
    bool busMaster : 1;
    bool specialCyclesRO : 1;
    bool memoryWriteInvalidEnableRO : 1;
    bool VGApaletteSnoopRO : 1;
    bool parityErrorResponse : 1;
    bool reserved : 1;
    bool ERSSenabled : 1;
    bool fastBackToBackEnableRO : 1;
    bool InterruptDisable : 1;
    uint8_t reserved_ : 5;
};

struct statusRegister {
    uint8_t reserved : 3;
    bool interruptStatusRO : 1;
    bool capabilitiesListRO : 1;
    bool capable66MhzRO : 1;
    bool reserved_ : 1;
    bool fastBackToBackCapableRO : 1;
    bool masterDataParityError : 1;
    uint8_t DEVSELtimingRO : 1;
    bool signaledTargetAbort : 1;
    bool receivedTargetAbort : 1;
    bool receivedMasterAbort : 1;
    bool signaledSystemError : 1;
    bool detectedParityError : 1;
};

struct BIST_register {
    uint8_t completionCode : 4;
    uint8_t reserved : 2;
    bool start : 1;
    bool capable : 1;
};

struct commonHeader {
    uint16_t deviceID;
    uint16_t vendorID;
    statusRegister status;
    commandRegister command;
    uint8_t classCode;
    uint8_t subClass;
    uint8_t progIF;
    uint8_t revisionID;
    BIST_register BIST;
    uint8_t headerType;
    uint8_t latencyTimer;
    uint8_t cacheLineSize;
};

struct header0 : commonHeader {
    BARlayout BAR0;
    BARlayout BAR1;
    BARlayout BAR2;
    BARlayout BAR3;
    BARlayout BAR4;
    BARlayout BAR5;
    uint32_t cadbusCISpointer;
    uint16_t subsystemID;
    uint16_t subsystemVendorID;
    uint32_t expansionROMbaseAddress;
    uint16_t reserved;
    uint8_t reserved_;
    uint8_t capabilitiesPointer;
    uint32_t reserved__;
    uint8_t maxLatency;
    uint8_t minGrant;
    uint8_t interruptPIN;
    uint8_t interruptLine;
};

struct header1 : commonHeader {
    BARlayout BAR0;
    BARlayout BAR1;
    uint8_t secondaryLatencyTimer;
    uint8_t sudordinateBusNumber;
    uint8_t secondaryBusNumber;
    uint8_t primaryBusNumber;
    uint16_t secondaryStatus;
    uint8_t IOlimit;
    uint8_t IObase;
    uint16_t memoryLimit;
    uint16_t memoryBase;
    uint16_t prefetchableMemoryLimit;
    uint16_t prefetchableMemoryBase;
    uint32_t prefetchableBaseUpper32;
    uint32_t prefetchableLimitUpper32;
    uint16_t IOlimitUpper32;
    uint16_t IObaseUpper32;
    uint16_t reserved;
    uint8_t reserved_;
    uint8_t capabilitiesPointer;
    uint32_t expansionROMbaseAddress;
    uint16_t bridgeControl;
    uint8_t interruptPIN;
    uint8_t interruptLine;
};

struct header2 : commonHeader {
    uint32_t cadbusExCAbaseAddress;
    uint16_t secondaryStatus;
    uint8_t reserved;
    uint8_t offsetCapabilitiesList;
    uint8_t cardbusLatencyTimer;
    uint8_t SubordinateBusNumber;
    uint8_t cardbusBusNumber;
    uint8_t PCIbusNumber;
    uint32_t memoryBaseAddress0;
    uint32_t memoryLimit0;
    uint32_t memoryBaseAddress1;
    uint32_t memoryLimit1;
    uint32_t IObaseAddress0;
    uint32_t IOlimit0;
    uint32_t IObaseAddress1;
    uint32_t IOlimit1;
    uint16_t bridgeControl;
    uint8_t interruptPIN;
    uint8_t interruptLine;
    uint16_t subsystemVendorID;
    uint16_t subsystemID;
    uint32_t PCcardLegacyModeBaseAddress;
};

extern pciPresent PCIs[];
extern int pciNumber;
uint16_t ReadWord(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset);
commonHeader readCommonHeader(uint8_t bus, uint8_t slot, uint8_t function);
uint16_t CheckVendor(uint8_t bus, uint8_t slot);
int GetPresent();
}
