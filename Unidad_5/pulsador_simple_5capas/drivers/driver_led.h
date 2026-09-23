/**
 * Prototipos de funciones que estan disponibles
 * por defecto para el LED
 */
#ifndef DRIVER_LED_H_
#define DRIVER_LED_H_

#include <stdint.h>
#include "hal_defs.h"

typedef enum{
    LED_OFF = HAL_GPIO_LOW,
    LED_ON = HAL_GPIO_HIGH
}LED_state_t;

void Driver_LED_Init(uint8_t port, uint8_t pin);
void Driver_LED_Set(uint8_t port, uint8_t pin, LED_state_t);
void Driver_LED_Toggle(uint8_t port, uint8_t pin);

#endif
