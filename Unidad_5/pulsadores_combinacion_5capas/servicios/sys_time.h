#ifndef SYS_TIME_H_
#define SYS_TIME_H_

#include <stdint.h>

/**
 * @brief Inicializa el servicio de tiempo del sistema.
 *
 * Reinicia a cero el contador interno de ticks. Depende directamente del tick
 * de 1 ms configurado previamente por BSP_Hardware_Init().
 */
void sysTime_init(void);

/**
 * @brief Incrementa el contador interno de tiempo.
 *
 * @warning Esta función debe ser invocada obligatoriamente dentro de la
 *          interrupción SysTick_Handler(), exactamente una vez por cada milisegundo.
 */
void sysTime_updateTick(void);

/**
 * @brief Obtiene el tiempo transcurrido desde el inicio del sistema.
 *
 * @return uint32_t Cantidad total de ticks acumulados (milisegundos).
 */
uint32_t sysTime_getTicks(void);
#endif
