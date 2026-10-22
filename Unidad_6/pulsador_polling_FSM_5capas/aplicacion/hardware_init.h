#ifndef HARDWARE_INIT_H_
#define HARDWARE_INIT_H_

/**
 * @brief Inicializa el hardware base de la placa (BSP).
 *
 * Configura los pines generados por ConfigTools, los árboles de relojes (clocks)
 * y el temporizador del sistema SysTick con una periodicidad de 1 ms.
 *
 * @warning Esta función debe ser invocada obligatoriamente al inicio del main(),
 *          antes de inicializar cualquier otro driver de periférico o servicio.
 */
void BSP_Hardware_Init(void);

#endif