/**
 * Driver de pulsador: convierte lecturas HAL a estados semanticos de boton.
 */
#ifndef DRIVER_PULSADOR_H_
#define DRIVER_PULSADOR_H_

#include <stdint.h>
#include "hal_defs.h"

typedef enum{
    BTN_RELEASED = HAL_GPIO_LOW,
    BTN_PRESSED = HAL_GPIO_HIGH
}pulsador_state_t;

/* Configura el pin como entrada; el mux y las propiedades electricas son de la placa. */
void Driver_Pulsador_Init(uint8_t port, uint8_t pin);
/* Lee el estado actual, sin aplicar filtro ni antirrebote. */
pulsador_state_t Driver_Pulsador_Read(uint8_t port, uint8_t pin);

#endif
