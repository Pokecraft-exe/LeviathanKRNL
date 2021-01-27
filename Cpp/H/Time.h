#pragma once
#include "typedefs.h"
#include "IO.h"
#include "Heap.h"

#define CMOS_CONTROL 0x70
#define CMOS_DATA 0x71

#define PIT_CHANNEL_0_PORT 0x40
#define PIT_CHANNEL_2_PORT 0x42
#define PIT_COMMAND_PORT 0x43

#define PIT_CHANNEL_2   0b10000000
#define PIT_CHANNEL_0   0b00000000

#define PIT_ACCESS_HL   0b00110000
#define PIT_LATCH_COUNT 0b00000000

#define PIT_MODE_SQGEN  0b00000110
#define PIT_MODE_RGEN   0b00000100
#define PIT_MODE_HROS   0b00000010
#define PIT_MODE_IOTC   0b00000000

#define PIT_MODE_BIN    0b00000000

#define TIME_ZONE +0

struct TIME{

    uint8 seconds;
    uint8 minutes;
    uint8 hour;
    uint8 weekday;
    uint8 monthday;
    uint8 month;
    uint8 year;
    uint8 century;

};

struct TIME *get_time(void);
void sleep(uint32);
void printTime(struct TIME *, uint8);
void delay(int clocks);