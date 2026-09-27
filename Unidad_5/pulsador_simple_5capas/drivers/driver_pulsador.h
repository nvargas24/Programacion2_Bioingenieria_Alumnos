/**
 * Driver de pulsador: convierte lecturas HAL a estados semanticos de boton.
 */
#ifndef DRIVER_PULSADOR_H_
#define DRIVER_PULSADOR_H_

#include <stdint.h>
#include "hal_defs.h"

/**
 * @brief Estados lógicos posibles de un pulsador.
 *
 * Vincula el estado físico del botón con la lectura digital del hardware.
 */
typedef enum{
    BTN_RELEASED = HAL_GPIO_LOW,
    BTN_PRESSED = HAL_GPIO_HIGH
}pulsador_state_t;

/**
 * @brief Configura un pin como entrada digital para un pulsador.
 * @param port Identificador del puerto GPIO (ej. PORT_A).
 * @param pin  Número de pin del puerto seleccionado.
 */
void Driver_Pulsador_Init(uint8_t port, uint8_t pin);

/**
 * @brief Lee el estado lógico actual del pulsador. Sin antirebote.
 * @param port Identificador del puerto GPIO (ej. PORT_A).
 * @param pin  Número de pin del puerto seleccionado.
 *
 * @return pulsador_state_t Estado actual del botón (BTN_PRESSED o BTN_RELEASED).
 */
pulsador_state_t Driver_Pulsador_Read(uint8_t port, uint8_t pin);
#endif
