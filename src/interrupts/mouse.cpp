#include "mouse.hpp"

namespace Mouse {

smouse pointer = {};

void wait(bool type) {
    uint32_t time_out = 100000;
    if (type == false) {
        // suspend until status is 1
        while (time_out--) {
            if ((inb(PS2_CMD_PORT) & 1) == 1) {
                return;
            }
        }
        return;
    } else {
        while (time_out--) {
            if ((inb(PS2_CMD_PORT) & 2) == 0) {
                return;
            }
        }
    }
}

void write(uint8_t data) {
    // sending write command
    wait(true);
    outb(PS2_CMD_PORT, 0xD4);
    wait(true);
    // finally write data to port
    outb(MOUSE_DATA_PORT, data);
}

uint8_t read() {
    wait(false);
    return inb(MOUSE_DATA_PORT);
}

void get_status(uint8_t status_byte) {
    if (status_byte & 0x01) pointer.leftClick = true;
    else pointer.leftClick = false;
    if (status_byte & 0x02) pointer.rightClick = true;
    else pointer.rightClick = false;
    if (status_byte & 0x04) pointer.middleClick = true;
    else pointer.middleClick = false;
    if (status_byte & 0x10) pointer.xSign = true;
    else pointer.xSign = false;
    if (status_byte & 0x20) pointer.ySign = true;
    else pointer.ySign = false;
}

bool set_rate(uint8_t rate) {
    using std::cout;
    uint8_t status;

    outb(MOUSE_DATA_PORT, MOUSE_CMD_SAMPLE_RATE);
    status = read();
    if(status != MOUSE_ACKNOWLEDGE) {
        cout << "error: failed to send mouse sample rate command\n";
        return false;
    }
    outb(MOUSE_DATA_PORT, rate);
    status = read();
    if(status != MOUSE_ACKNOWLEDGE) {
        cout << "error: failed to send mouse sample rate data\n";
        return false;
    }
  return true;
}

int install(){
    using std::cout;
    uint8_t status;

    pointer.x = 5;
    pointer.y = 2;

    wait(true);
    outb(PS2_CMD_PORT, 0xA8);
    outb(MOUSE_DATA_PORT, MOUSE_CMD_MOUSE_ID);
    status = read();
    cout << "mouse id: " << status << '\n';
    bool success = set_rate(100);

    wait(true);
    outb(PS2_CMD_PORT, 0x20);
    wait(false);
    status = (inb(MOUSE_DATA_PORT) | 2);
    // write status to port
    wait(true);
    outb(PS2_CMD_PORT, MOUSE_DATA_PORT);
    wait(true);
    outb(MOUSE_DATA_PORT, status);

    // set mouse to use default settings
    write(MOUSE_CMD_SET_DEFAULTS);
    status = read();
    if(status != MOUSE_ACKNOWLEDGE) {
        cout << "error: failed to set default mouse settings\n";
        return 1;
    }

    // enable packet streaming to receive
    write(MOUSE_CMD_ENABLE_PACKET_STREAMING);
    status = read();
    if(status != MOUSE_ACKNOWLEDGE) {
        cout << "error: failed to enable mouse packet streaming\n";
        return -1;
    }
    return 0;
}

}