#include <stdint.h>

class bitmap {
private:
	uint8_t buffer;
public:
	bitmap();
	bitmap(char chr);
	operator char();
	bool operator()(uint8_t position, bool bit);
	bool operator[](uint8_t position);
};
