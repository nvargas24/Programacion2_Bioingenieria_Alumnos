#ifndef SYS_TIMER_H_
#define SYS_TIMER_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct{
    uint32_t start_tick;
    uint32_t period_ms;
    bool is_running;
} sw_timer_t;

void timerStart(sw_timer_t* timer, uint32_t period_ms);
void timerStop(sw_timer_t* timer);
bool timer_isExpired(sw_timer_t* timer);

#endif
