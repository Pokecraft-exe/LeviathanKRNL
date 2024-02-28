#pragma once
#include <stddef.h>
#include "vector.hpp"
#include "color.hpp"
#include "string.hpp"

namespace GUI {
    class framebuffer {
    private:
        framebuffer* previousBuffer;
        vector<size_t> requests;
        vector<size_t> requested;
        void* data;
        int _width;
        int _height;
    public:
        framebuffer(){ data = nullptr; }
        framebuffer(void* address, int w, int h);
        framebuffer(void* address, int w, int h, framebuffer* buffer);
        framebuffer(int w, int h, framebuffer* buffer);
        void* address();
        /** 
         * return the address of the framebuffer
         */
        int width();
        /**
         * return the width of the framebuffer
        */
        int height();
        /**
         * return the height of the framebuffer
        */
        bool requestFrameBuffer(size_t PID);
        /**
         * ask for an interprocessing framebuffer permission
         * return 1 if the framebuffer is ready;
        */
        bool requestSwap(size_t PID);
        /**
         * ask for a safe interprocessing framebuffer swap
         * return 1 if swapped
        */
        void swap();
        /**
         * force the framebuffer to swap
         * unsafe for interprocessing framebuffers
        */
        void blit(int x, int y);
        /**
         * copy the framebuffer to x and y position
         * not for interprocessing framebuffers
        */

    };
    void putPixel(unsigned int x, unsigned int y, color::Color c);
    void drawRect(unsigned int x, unsigned int y, unsigned int size_x, unsigned int size_y, color::Color c) {
    void drawText(string text, unsigned int x, unsigned int y, color::Color c);
    extern framebuffer screen;
    extern framebuffer buffer;
}