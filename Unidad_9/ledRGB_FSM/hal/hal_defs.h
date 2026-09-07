/*
    Definiciones generales de estado
    Por ejemplo, como se interpreta estado HIGH/LOW u entrada/salida.
*/
#ifndef HAL_DEFS_H_
#define HAL_DEFS_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum{
    HAL_GPIO_LOW = 0,
    HAL_GPIO_HIGH = 1
}hal_gpio_state_t;

typedef enum{
    HAL_GPIO_INPUT = 0,
    HAL_GPIO_OUTPUT = 1
}hal_gpio_dir_t;

#endif 