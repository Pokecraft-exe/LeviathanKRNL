#include "H/kernel.h"
 
static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};
 
void *memcpy(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;
 
    for (size_t i = 0; i < n; i++) {
        pdest[i] = psrc[i];
    }
 
    return dest;
}
 
void *memset(void *s, int c, size_t n) {
    uint8_t *p = (uint8_t *)s;
 
    for (size_t i = 0; i < n; i++) {
        p[i] = (uint8_t)c;
    }
 
    return s;
}
 
void *memmove(void *dest, const void *src, size_t n) {
    uint8_t *pdest = (uint8_t *)dest;
    const uint8_t *psrc = (const uint8_t *)src;
 
    if (src > dest) {
        for (size_t i = 0; i < n; i++) {
            pdest[i] = psrc[i];
        }
    } else if (src < dest) {
        for (size_t i = n; i > 0; i--) {
            pdest[i-1] = psrc[i-1];
        }
    }
 
    return dest;
}
 
int memcmp(const void *s1, const void *s2, size_t n) {
    const uint8_t *p1 = (const uint8_t *)s1;
    const uint8_t *p2 = (const uint8_t *)s2;
 
    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] < p2[i] ? -1 : 1;
        }
    }
 
    return 0;
}
 
static void hcf(void) {
    asm ("cli");
    for (;;) {
        asm ("hlt");
    }
}

uint32_t RGB(uint8_t R, uint8_t G, uint8_t B){
	uint32_t color;
	color = R;
	color << 8;
	color += G;
	color << 8;
	color += B;
	return color;
}

struct limine_framebuffer *framebuffer;

extern void far_jump_to_kernel();

void _start(void) {
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        hcf();
    }
 
    framebuffer = framebuffer_request.response->framebuffers[0];
    
    fontInitFrameBuffer(framebuffer);
 
 	DrawString("Hello World!", 200, 25, RGB(34, 150, 249), 1);
 	DrawString("Hello World!", 100, 50, RGB(34, 150, 249), 2);
    DrawString("Hello World!", 100, 100, RGB(34, 150, 249), 3);
    
    far_jump_to_kernel();
    
 	while(1);
    //far_jump_to_kernel();
}
