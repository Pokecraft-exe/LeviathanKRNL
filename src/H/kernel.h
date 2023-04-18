#pragma once

#include <stdint.h>
#include <stddef.h>
#include "limine.h"
#include "font.h"

extern struct limine_framebuffer *framebuffer;
uint32_t RGB(uint8_t R, uint8_t G, uint8_t B);
