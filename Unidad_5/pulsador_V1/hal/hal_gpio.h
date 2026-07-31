/**
 * Prototipos de funciones disponibles 
 * para interactuar con registros
 */
#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

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