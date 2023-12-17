#pragma once
#include "IO.h"
#include "stdio"

extern "C" void pit_handler();

namespace timer {
	namespace PIT {
		void init(uint32_t frequency);
		extern "C" uint64_t ticks;
	
		void addTicks();
		
		void resetTicks();
	
		uint64_t getTicks();
		void wait(uint64_t second);
	}
}
