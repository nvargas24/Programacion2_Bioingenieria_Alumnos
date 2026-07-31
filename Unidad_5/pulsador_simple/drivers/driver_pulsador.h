/**
 * Prototipos de funciones que estan disponibles
 * por defecto para el LED
 */
#ifndef DRIVER_PULSADOR_H_
#define DRIVER_PULSADOR_H_

#include <stdint.h>
#include "hal_defs.h"

void Driver_Pulsador_Init(uint8_t port, uint8_t pin);
hal_gpio_state_t Driver_Pulsador_Read(uint8_t port, uint8_t pin);

#endif