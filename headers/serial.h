#pragma once

#define PORT 0x3f8          // COM1
#define SERIALWHITE (char*)"\033[1;37m"
#define SERIALBLACK (char*)"\033[1;30m"
#define SERIALRED (char*)"\033[1;31m"
#define SERIALGREEN (char*)"\033[1;32m"
#define SERIALYELLOW (char*)"\033[1;33m"
#define SERIALBLUE (char*)"\033[1;34m"
#define SERIALPINK (char*)"\033[1;35m"
#define SERIALCYAN (char*)"\033[1;36m"

int init_serial();
int is_transmit_empty();
int serial_received();
char read_serial();
void write_serial(char a);
void puts(const char* a);
