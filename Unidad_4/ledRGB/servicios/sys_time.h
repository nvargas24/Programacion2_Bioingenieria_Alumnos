#ifndef SYS_TIME_H_
#define SYS_TIME_H_

#include <stdint.h>
#include <stdbool.h>

void sysTime_init();
void sysTime_updateTick();
uint32_t sysTime_getTicks();
bool sysTime_hasElapsed(uint32_t startTick, uint32_t periodMs);

#endif