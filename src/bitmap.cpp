#include "bitmap.hpp"
#include <stdint.h>

bitmap::bitmap() {buffer = 0;}
bitmap::bitmap(char chr) {buffer = chr;}
bitmap::operator char(){
	return buffer;
}
bool bitmap::operator()(uint8_t position, bool bit){
	bool currentBit = operator[](position);
	if (currentBit != bit) {
		if (bit) {
			buffer ^= (0x80>>position);
			
			return 1;
		}
		uint8_t minus = 0x80 >> (position);
		buffer ^= minus;
		return 1;
	}
	return 0;
}
bool bitmap::operator[](uint8_t position){
	return (buffer & (0x80>>position));
}

