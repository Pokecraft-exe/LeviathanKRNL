#include "stdio"

std::stdin::stdin() {
    color(0xffffff);
}

std::stdin::stdin(color::Color color__) {
    color(color__);
}

char std::endl = '\n';

void std::stdin::color(color::Color color__) {
    color_ = color__;
};

color::Color std::stdin::color() {
    return color_;
};

std::stdin std::stdin::operator <<(const char* data) {
    if (*(data) == 0) {
        do{
            if (*(data+1) == 'm') {
                printchr(*data, color_);
                color_.R(*(data+5));
                color_.G(*(data+4));
                color_.B(*(data+3));
                if (*(data+8) == ']') {
                    color_.A(*(data+7));
                    data += 8;
                } else {
                    data += 7;
                }
            }
            else {
                printchr(*data, color_);
                data++;
            }
        } while (*data != 0);
    } else {
        do{
            if (*(data+1) == 0
            && *(data+2) == 'm') {
                printchr(*data, color_);
                color_.R(*(data+6));
                color_.G(*(data+5));
                color_.B(*(data+4));
                if (*(data+8) == ']') {
                    color_.A(*(data+8));
                    data += 9;
                } else {
                    data += 8;
                }
            }
            else {
                printchr(*data, color_);
                data++;
            }
        } while (*data != 0);
    }

    return stdin(color_);
}

std::stdin std::stdin::operator <<(char data) {
    printchr(data, color_);
    return stdin(color_);
}

std::stdin std::stdin::operator <<(void* data) {
    printNoReturn(hex(data), color_);
    return stdin(color_);
}

std::stdin std::stdin::operator <<(int data) {
    printNoReturn(IntToStr(data), color_);
    return stdin(color_);
}
std::stdin std::stdin::operator <<(uint8_t data) {
    printNoReturn(IntToStr(data), color_);
    return stdin(color_);
}
std::stdin std::stdin::operator <<(uint16_t data) {
    printNoReturn(IntToStr(data), color_);
    return stdin(color_);
}
std::stdin std::stdin::operator <<(uint32_t data) {
    printNoReturn(IntToStr(data), color_);
    return stdin(color_);
}
std::stdin std::stdin::operator <<(uint64_t data) {
    printNoReturn(IntToStr(data), color_);
    return stdin(color_);
}
