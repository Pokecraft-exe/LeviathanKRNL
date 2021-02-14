#pragma once
#include "typedefs.h"
#include "IO.h"
#include "IDT.h"

extern char MasterVolume;
void PlaySound(uint32 nFrequence,char Volume);
void noSound();
void beep();