
#include "pit.hpp"

extern void puts(const char*);

namespace timer {
	namespace PIT {
		uint32_t frequencies;
		void init(uint32_t frequency)
		{
		    uint32_t divisor = 1193182 / frequency;
		    frequencies = frequency;
	
		    outb(0x43, 0x36);
		    outb(0x40, (uint8_t)divisor & 0xFF);
		    outb(0x40, (uint8_t)(divisor >> 8) & 0xFF);
		}
		uint64_t ticks = 0;
	
		void addTicks()
		{
		    ticks++;
		    outb(0x20, 0x20);
		}
	
		uint64_t getTicks()
		{
		    return ticks;
		}
		
		void resetTicks() {
			ticks = 0;
		};
		
		void wait(uint64_t second){
		    uint64_t current_ticks = getTicks();
		    uint64_t delay = (second * frequencies);
		    while (1)
		    {
		        if (current_ticks + delay < getTicks())
		            break;
		    }
		}
	}
}
