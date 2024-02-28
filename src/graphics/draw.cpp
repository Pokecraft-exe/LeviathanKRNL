#include "GUI.hpp"
#include "font.hpp"

namespace GUI {
    void putPixel(unsigned int x, unsigned int y, color::Color c) {
        int width = screen.width();
        int height = screen.height();
        if (x > width) return;
        if (y > height) return;
        uint32_t* address = (uint32_t*)screen.address();
        address[x+y*width] = c;
    }
    void drawRect(unsigned int x, unsigned int y, unsigned int size_x, unsigned int size_y, color::Color c) {
        uint32_t *fb_ptr = (uint32_t*)screen.address();
        int i,j;
        for (j=0; j<size_y; j++) {
            for (i=0; i<size_x; i++) {
    		    fb_ptr[screen.width()*(y+j)+(x+i)] = c;
        	}
        }
    }
    extern "C" const unsigned char __font_bitmap__[];
    extern "C" unsigned char reverse_byte(unsigned char x);
    void drawChar(char c, int x, int y, color::Color color) {
        uint8_t i,j;
        // Draw pixels
        for (j=0; j<8; j++) {
            for (i=0; i<8; i++) {
                if (reverse_byte(__font_bitmap__[c*8+j]) & (1<<i)) {
        		    putPixel(x+i, y+j, color);
                }
            }
        }
    }
    void drawRawText(char* text, unsigned int x, unsigned int y, color::Color c) {
        while (*text) {
            drawChar(*text++, x, y, c);
             x += 8;
    }
    }
}