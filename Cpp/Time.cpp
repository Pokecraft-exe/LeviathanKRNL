//#include "time.h"

TIME *GLOBAL_TIME;
uint32 PIT_F = 0;
uint32 SPEAKER_F = 0;

struct TIME *get_time(void)
{

    struct TIME *time_now = (struct TIME *) calloc(sizeof(TIME));

    struct TIME *time_last = (struct TIME *) calloc(sizeof(TIME));

    while(1)
    {

        outb(CMOS_CONTROL, 1 << 7 | 0x00);
        delay(50000);
        time_now->seconds = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 | 0x02);
        delay(50000);
        time_now->minutes = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 | 0x04);
        delay(50000);
        time_now->hour = inb(CMOS_DATA) & (127); // get rid of the am-pm flag if set

        outb(CMOS_CONTROL, 1 << 7 | 0x06);
        delay(50000);
        time_now->weekday = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 | 0x07);
        delay(50000);
        time_now->monthday = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 | 0x08);
        delay(50000);
        time_now->month = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 | 0x09);
        delay(50000);
        time_now->year = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 | 0x32);
        delay(50000);
        time_now->century = inb(CMOS_DATA);

        time_last->seconds = time_now->seconds;
        time_last->minutes = time_now->minutes;
        time_last->hour = time_now->hour;
        time_last->weekday = time_now->weekday;
        time_last->monthday = time_now->monthday;
        time_last->month = time_now->month;
        time_last->year = time_now->year;
        time_last->century = time_now->century;

        outb(CMOS_CONTROL, 1 << 7 | 0x00);
        delay(50000);
        time_now->seconds = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 | 0x02);
        delay(50000);
        time_now->minutes = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 |0x04);
        delay(50000);
        time_now->hour = inb(CMOS_DATA) & (127); // get rid of the am-pm flag if set

        outb(CMOS_CONTROL, 1 << 7 | 0x06);
        delay(50000);
        time_now->weekday = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 |0x07);
        delay(50000);
        time_now->monthday = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 | 0x08);
        delay(50000);
        time_now->month = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 | 0x09);
        delay(50000);
        time_now->year = inb(CMOS_DATA);

        outb(CMOS_CONTROL, 1 << 7 | 0x32);
        delay(50000);
        time_now->century = inb(CMOS_DATA);

        if(time_last->seconds == time_now->seconds &&
                time_last->minutes == time_now->minutes &&
                time_last->hour == time_now->hour &&
                time_last->weekday == time_now->weekday &&
                time_last->monthday == time_now->monthday &&
                time_last->month == time_now->month &&
                time_last->year == time_now->year &&
                time_last->century == time_now->century )
            break;

    }

    outb(CMOS_CONTROL, 0x0B);
    uint8 Breg = inb(CMOS_DATA);

    if(!(Breg & 0x04))
    {
        time_now->seconds = (time_now->seconds & 0x0F) + ((time_now->seconds / 16) * 10);
        time_now->minutes = (time_now->minutes & 0x0F) + ((time_now->minutes / 16) * 10);
        time_now->hour = ( (time_now->hour & 0x0F) + (((time_now->hour & 0x70) / 16) * 10) ) | (time_now->hour & 0x80);
        time_now->monthday = (time_now->monthday & 0x0F) + ((time_now->monthday / 16) * 10);
        time_now->month = (time_now->month & 0x0F) + ((time_now->month / 16) * 10);
        time_now->year = (time_now->year & 0x0F) + ((time_now->year / 16) * 10);
        if(time_now->century != 0)
        {
            time_now->century = (time_now->century & 0x0F) + ((time_now->century / 16) * 10);
        }
    }

    free(time_last);

    return time_now;
}

void sleep(uint64 ms)
{

    uint64 ticks = PIT_F * ((float) ms / 1000);

    uint64 time_now = CLOCK;

    uint64 time_then = CLOCK+ticks;

    while(time_now < time_then){time_now = CLOCK; delay(1000);}

    return;
}

void printTime(struct TIME * time, uint8 color)
{
    puti(time->century, color); // y-m-d <> h-m-s
    puti(time->year, color);
    puts("-", color);
    puti(time->month, color);
    puts("-", color);
    puti(time->monthday, color);
    puts(" <> ", color);

    puti(time->hour+TIME_ZONE, color);
    puts(":", color);
    puti(time->minutes, color);
    puts(":", color);
    puti(time->seconds, color);
    puts("   ", color);

    return;
}

void incTime(TIME *t){

    t->seconds++;

    if(t->seconds >= 60)
    {
        t->seconds = 0;
        t->minutes++;
    }
    if(t->minutes >= 60)
    {
        t->minutes = 0;
        t->hour++;
    }
    if(t->hour >= 25)
    {
        t->hour = 0;
        t->monthday++;
    }
    if(t->monthday >= 31)
    {
        t->monthday = 0;
        t->month++;
    }
    if(t->month >= 13)
    {
        t->month = 0;
        t->year++;
    }

    return;
}

void delay(uint64 clocks)
{

    asm("push %rax");

    for(uint64 i = 0; i < clocks; i+=8)
        asm("xor %rax, %rax");

    asm("pop %rax");

    return;
}

void initRTC(uint8 rate)
{

    if(rate < 3)
        rate = 3;
    if(rate > 15)
        rate = 15;

    asm("cli");
    outb(CMOS_CONTROL, inb(CMOS_CONTROL) | 0x80);           // disable NMI

    outb(CMOS_CONTROL, 0x0A);                               // select the A register of the CMOS
    outb(CMOS_DATA, 0x20);                                  // write to CMOS/RTC RAM

    outb(CMOS_CONTROL, 0x0B);                               // set the index to the B register

    char B = inb(CMOS_DATA);                                // read the B register

    outb(CMOS_CONTROL, 0x0B);                               // set the index to the B register again

    outb(CMOS_DATA, B | 0x40);                              // write the previous value ORed with 0x40. This turns on bit 6 of register

    outb(CMOS_CONTROL, 0x0A);		                        // set index to register A
    char A = inb(CMOS_DATA);	                            // get initial value of register A
    outb(CMOS_CONTROL, 0x0A);		                        // reset index to A
    outb(CMOS_DATA, (A & 0xF0) | (rate & 15));              //write only our rate to A. Note, rate is the bottom 4 bits.

    outb(CMOS_CONTROL, inb(CMOS_CONTROL) & 0x7F);           // enable NMI
    asm("sti");

    char a1, a2;

    a1 = inb(PIC1_DATA);
    a2 = inb(PIC2_DATA);

    a1 &= 0b11111001;
    a2 &= 0b11111110;

    outb(PIC1_DATA, a1); // enable irqs 2, 1
    outb(PIC2_DATA, a2); // enable irq 8


    return;
}

void initPIT(uint32 freq, uint8 channel)
{

    asm("cli");

    if(channel == PIT_CHANNEL_0)
        PIT_F = freq;
    else if(channel == PIT_CHANNEL_2)
        SPEAKER_F = freq;

    float input_frequency = 3579545 / 3;

    if(freq < 18)
        freq = 18;
    if(freq > input_frequency)
        freq = input_frequency-1;

    uint16 counter = input_frequency / freq;

    if(counter == 0)
        counter++;

    char a1, a2;

    a1 = inb(PIC1_DATA);
    a2 = inb(PIC2_DATA);

    a1 &= 0b11111000;
    a2 &= 0b11111111;

    outb(PIC1_DATA, a1); // enable irqs 2, 1, 0
    outb(PIC2_DATA, a2); // disable all slave irqs

    if(channel == PIT_CHANNEL_0){

        outb(PIT_COMMAND_PORT, channel | PIT_ACCESS_HL | PIT_MODE_RGEN | PIT_MODE_BIN);
        outb(PIT_CHANNEL_0_PORT, counter & 0xff);
        outb(PIT_CHANNEL_0_PORT, (counter >> 8) & 0xff);

    }
    else if(channel == PIT_CHANNEL_2){

        outb(PIT_COMMAND_PORT, channel | PIT_ACCESS_HL | PIT_MODE_SQGEN | PIT_MODE_BIN);
        outb(PIT_CHANNEL_2_PORT, counter & 0xff);
        outb(PIT_CHANNEL_2_PORT, (counter >> 8) & 0xff);

    }


    asm("sti");

    return;
}

