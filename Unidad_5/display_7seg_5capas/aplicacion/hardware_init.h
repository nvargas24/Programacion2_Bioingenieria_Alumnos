#ifndef HARDWARE_INIT_H_
#define HARDWARE_INIT_H_

#include "../drivers/driver_display.h"

extern const display_config_t g_display_config;

/**
 * @brief Inicializa los recursos de hardware requeridos por la aplicacion.
 *
 * Configura pines, clocks, SysTick y los drivers de los perifericos usados.
 */
void BSP_Hardware_Init(void);

#endif