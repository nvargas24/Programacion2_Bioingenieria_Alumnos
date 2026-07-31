#include "sys_time.h"

static volatile uint32_t g_systemTickCount = 0;

void sysTime_init(){
    g_systemTickCount = 0;
}

void sysTime_updateTick(){
    g_systemTickCount++;
}

uint32_t sysTime_getTicks(){
    return g_systemTickCount;
}

void sysTime_delay_ms(uint32_t delay_ms){
    uint32_t startTick = sysTime_getTicks;

    while((sysTime_getTicks() - startTick) < delay_ms){}
}