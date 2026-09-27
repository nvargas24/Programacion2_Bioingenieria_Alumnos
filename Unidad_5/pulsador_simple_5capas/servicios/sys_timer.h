#ifndef SYS_TIMER_H_
#define SYS_TIMER_H_

#include <stdint.h>
#include <stdbool.h>

/* Temporizador software periodico basado en los ticks de sys_time. */

typedef struct{
    uint32_t start_tick; /* Tick de referencia; se actualiza al vencer. */
    uint32_t period_ms;  /* Duracion de cada intervalo, en milisegundos. */
    bool is_running;     /* Indica si el temporizador esta activo. */
} sw_timer_t;
/* Inicia o reinicia el intervalo; requiere que el tick de sys_time este activo. */
void timerStart(sw_timer_t* timer, uint32_t period_ms);
/* Detiene el timer; si es NULL no hace nada. */
void timerStop(sw_timer_t* timer);
/* Al vencer devuelve true y reinicia el intervalo; false si esta detenido o es NULL. */
bool timer_isExpired(sw_timer_t* timer);

#endif
