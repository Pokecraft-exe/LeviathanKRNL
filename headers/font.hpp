#pragma once
#include <stdint.h>

extern "C" int fontInitFrameBuffer(struct limine_framebuffer* fb);
extern "C" void DrawChar(char c, uint16_t x, uint16_t y, uint32_t color, uint8_t size);
extern "C" void DrawCharBackground(char c, uint16_t x, uint16_t y, uint32_t color, uint32_t back_color, uint8_t size);
extern "C" void DrawString(const char* str, uint16_t x, uint16_t y, uint32_t color, uint8_t size);
extern "C" void DrawStringBackground(const char* str, uint16_t x, uint16_t y, uint8_t size, uint32_t color, uint32_t bg_color, bool background);
