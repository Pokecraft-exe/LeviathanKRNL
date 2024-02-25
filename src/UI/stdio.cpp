#include "stdio"

std::ostream std::cout;
std::istream std::cin;
char std::endl = '\n';

std::ostream::ostream() {
    color(0xffffff);
}
std::ostream::ostream(color::Color color__) {
    color(color__);
}
void std::ostream::color(color::Color color__) {
    color_ = color__;
};
color::Color std::ostream::color() {
    return color_;
};
std::ostream std::ostream::operator <<(const char* data) {
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

    return ostream(color_);
}
std::ostream std::ostream::operator <<(string str) {
    ostream o(color_);
    o << str.c_str();
    return o;
}
std::ostream std::ostream::operator <<(char data) {
    printchr(data, color_);
    return ostream(color_);
}
std::ostream std::ostream::operator <<(void* data) {
    printNoReturn(hex(data), color_);
    return ostream(color_);
}
std::ostream std::ostream::operator <<(int data) {
    printNoReturn(IntToStr(data), color_);
    return ostream(color_);
}
std::ostream std::ostream::operator <<(uint8_t data) {
    printNoReturn(IntToStr(data), color_);
    return ostream(color_);
}
std::ostream std::ostream::operator <<(uint16_t data) {
    printNoReturn(IntToStr(data), color_);
    return ostream(color_);
}
std::ostream std::ostream::operator <<(uint32_t data) {
    printNoReturn(IntToStr(data), color_);
    return ostream(color_);
}
std::ostream std::ostream::operator <<(uint64_t data) {
    printNoReturn(IntToStr(data), color_);
    return ostream(color_);
}
std::ostream std::ostream::operator <<(float data) {
    printNoReturn(FloatToString(data, 2), color_);
    return ostream(color_);
}
std::ostream std::ostream::operator <<(double data) {
    printNoReturn(FloatToString(data, 2), color_);
    return ostream(color_);
}

extern int strlen(const char* str);

std::istream::istream() {}
std::istream std::istream::operator >>(string& out) {
    char str[100] = {0};
    int i = 0;

    while(1) {
        char k = pollKey(nullptr);
        str[i] = k;

        switch (k) {
            case 127:
                if (i <= 0) break;
                str[i--] = 0;
                deletechr();
                if (CursorShown) {
                    deletechr();
                    cout << '_';
                }
                break;
            case 10:
                str[i] = 0;
                memcpy(out.c_str(), &str, strlen(str));
                return istream();
                break;
            case 0:
                break;
            default:
                if (CursorShown) {
                    deletechr();
                    cout << str[i];
                    i++;
                    cout << '_';
                }
                else {
                    cout << str[i];
                    i++;
                }
        }
    }
}
std::istream std::istream::operator >>(uint64_t&) {return istream();}
std::istream std::istream::operator >>(int&) {return istream();}
std::istream std::istream::operator >>(uint8_t&) {return istream();}
std::istream std::istream::operator >>(uint16_t&) {return istream();}
std::istream std::istream::operator >>(uint32_t&) {return istream();}
std::istream std::istream::operator >>(float&) {return istream();}
std::istream std::istream::operator >>(double&) {return istream();}
