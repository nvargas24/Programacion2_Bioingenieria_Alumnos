/**
 * Prototipos de funciones que estan disponibles
 * por defecto para el LED
 */
#ifndef DRIVER_PULSADOR_H_
#define DRIVER_PULSADOR_H_

#include <stdint.h>
#include "hal_defs.h"

typedef enum{
    BTN_RELEASED = HAL_GPIO_LOW,
    BTN_PRESSED = HAL_GPIO_HIGH
}pulsador_state_t;

void Driver_Pulsador_Init(uint8_t port, uint8_t pin);
pulsador_state_t Driver_Pulsador_Read(uint8_t port, uint8_t pin);

#endif
