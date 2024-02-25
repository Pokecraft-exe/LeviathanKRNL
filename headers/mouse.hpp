#pragma once
#include "IO.h"

struct smouse {
    uint8_t cycle : 2;
    uint16_t x : 15;
    uint16_t y : 15;
    uint8_t bytes[3];
};

namespace Mouse {
    extern smouse pointer;

    inline void wait(uint8_t a_type);
    inline void write(uint8_t a_write);
    uint8_t read();
    void install();
}