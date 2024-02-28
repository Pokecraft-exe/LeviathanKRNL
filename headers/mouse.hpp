#pragma once
#include "IO.h"
#include "stdio"
#define MOUSE_CMD_RESET                         0xFF
#define MOUSE_CMD_RESEND                        0xFE
#define MOUSE_CMD_SET_DEFAULTS                  0xF6
#define MOUSE_CMD_DISABLE_PACKET_STREAMING      0xF5
#define MOUSE_CMD_ENABLE_PACKET_STREAMING       0xF4
#define MOUSE_CMD_SAMPLE_RATE                   0xF3
#define MOUSE_CMD_MOUSE_ID                      0xF2
#define MOUSE_CMD_REQUEST_SINGLE_PACKET         0xEB
#define MOUSE_CMD_STATUS                        0xE9
#define MOUSE_CMD_RESOLUTION                    0xE8
#define MOUSE_ACKNOWLEDGE                       0xFA
#define PS2_CMD_PORT                            0x64
#define MOUSE_DATA_PORT                         0x60

struct smouse {
    uint8_t cycle : 2;
    bool leftClick : 1;
    bool middleClick : 1;
    bool rightClick : 1;
    bool xSign : 1;
    bool ySign : 1;
    uint16_t x;
    uint16_t y;
    uint8_t bytes[3];
};

namespace Mouse {
    extern smouse pointer;

    inline void wait(uint8_t a_type);
    inline void write(uint8_t a_write);
    void get_status(uint8_t status_byte);
    uint8_t read();
    int install();
}