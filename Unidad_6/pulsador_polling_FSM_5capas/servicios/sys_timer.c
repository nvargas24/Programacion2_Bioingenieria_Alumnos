#include "sys_time.h"
#include "sys_timer.h"
#include <stddef.h>

void timerStart(sw_timer_t* timer, uint32_t period_ms){
    if (timer == NULL)  return;
    timer->period_ms = period_ms;
    timer->start_tick = sysTime_getTicks();
    timer->is_running = true;
}

void timerStop(sw_timer_t* timer){
    if (timer == NULL)  return;
    timer->is_running = false;
}

bool timer_isExpired(sw_timer_t *timer) {
    uint32_t current_ticks = 0;

    if (timer == NULL || !timer->is_running) {
        return false;
    }
    current_ticks = sysTime_getTicks();
    if ((current_ticks - timer->start_tick) >= timer->period_ms) {
        timer->start_tick = current_ticks;
        return true;
    }

    return false;
}
