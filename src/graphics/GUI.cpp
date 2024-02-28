#include "GUI.hpp"
#include "allocator.hpp"



namespace GUI
{
framebuffer screen;
framebuffer buffer;

framebuffer::framebuffer(void* pointer, int w, int h) {
    previousBuffer = nullptr;
    data = pointer;
   _width = w;
    _height = h;
}
framebuffer::framebuffer(void* pointer, int w, int h, framebuffer* buffer) {
    previousBuffer = buffer;
    data = pointer;
   _width = w;
    _height = h;
}
framebuffer::framebuffer(int w, int h, framebuffer* buffer) {
    previousBuffer = nullptr;
    data = alloc(w*h*4);
   _width = w;
    _height = h;
}
void* framebuffer::address() {
    return data;
}
int framebuffer::width() {
    return _width;
}
int framebuffer::height() {
    return _height;
}
bool framebuffer::requestFrameBuffer(size_t PID) {
    return false;
}
bool framebuffer::requestSwap(size_t PID) {
    return false;
}
void framebuffer::swap() {
    uint32_t* addr = (uint32_t*)previousBuffer->address();
    for (int x = 0; x < _width; x++) {
        for (int y = 0; y < _height; y++) {
            addr[x+y*_width] = ((uint32_t*)data)[x+y*_width];
        }
    }
}
void framebuffer::blit(int x, int y) {
    return;
}
    
}
