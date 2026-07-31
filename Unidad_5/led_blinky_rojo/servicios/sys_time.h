#ifndef SYS_TIME_H_
#define SYS_TIME_H_

#include <stdint.h>

void sysTime_init();
void sysTime_updateTick();
uint32_t sysTime_getTicks();

#endif