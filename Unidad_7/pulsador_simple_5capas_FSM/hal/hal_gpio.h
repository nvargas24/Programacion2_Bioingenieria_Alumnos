/**
 * HAL GPIO: adapta las operaciones del SDK NXP a la interfaz del proyecto.
 * La lectura de este proyecto invierte el nivel crudo devuelto por el SDK.
 */
#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

/* HAL de GPIO sobre el SDK NXP. El pin mux y sus propiedades electricas van en pin_mux. */

#include "hal_defs.h"

void HAL_GPIO_InitPin(
    uint8_t port, 
    uint8_t pin, 
    hal_gpio_dir_t direction
);

void HAL_GPIO_WritePin(
    uint8_t port, 
    uint8_t pin, 
    hal_gpio_state_t state
);

void HAL_GPIO_TogglePin(
    uint8_t port, 
    uint8_t pin
);

hal_gpio_state_t HAL_GPIO_ReadPin(
    uint8_t port,
    uint8_t pin
);

#endif
