#include "color.hpp"

namespace color {

uint32_t Color::Ablend(Color fg, Color bg) {
	Color c;
	uint8_t iA = (255 - fg.A());
	if (fg.A() == 0) { return bg; }
	c.A(fg.A() + bg.A() * (255 - fg.A()));
	c.R((fg.R() * fg.A() + bg.R() * bg.A() * iA) / c.A());
	c.G((fg.G() * fg.A() + bg.G() * bg.A() * iA) / c.A());
	c.B((fg.B() * fg.A() + bg.B() * bg.A() * iA) / c.A());
	return c;
}

uint8_t Color::A() {
	return data[0];
}
uint8_t Color::B() {
	return data[1];
}
uint8_t Color::G() {
	return data[2];
}
uint8_t Color::R() {
	return data[3];
}

Color::Color(uint32_t color) { memcpy(&data, &color, sizeof(uint32_t)); }
Color::Color(Color& color) { uint32_t c = color; memcpy(&data, &color, sizeof(uint32_t)); }

Color::operator uint32_t() {
	uint32_t c;
	memcpy(&c, &data, sizeof(uint32_t));
	return c;
}

}