#ifndef SYS_TIME_H_
#define SYS_TIME_H_

#include <stdint.h>

/* Tick de 1 ms configurado por BSP_Hardware_Init. */
void sysTime_init(void); /* Reinicia el contador. */
void sysTime_updateTick(void); /* Incrementar desde SysTick_Handler, una vez por tick. */
uint32_t sysTime_getTicks(void); /* Devuelve el total acumulado de ticks. */
/* Espera ocupada: bloquea la CPU hasta que transcurran delay_ms ticks. */
void sysTime_delay_ms(uint32_t delay_ms);

#endif