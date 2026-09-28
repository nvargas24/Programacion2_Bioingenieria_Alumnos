/**
 * Driver de pulsador: convierte lecturas HAL a estados semanticos de boton.
 */
#ifndef DRIVER_PULSADOR_H_
#define DRIVER_PULSADOR_H_

#include <stdint.h>

/**
 * @brief Estados semanticos posibles de un pulsador.
 *
 * No representan niveles GPIO. En esta placa, LOW indica pulsado y HIGH
 * indica liberado.
 */
typedef enum {
    BTN_RELEASED = 0,
    BTN_PRESSED = 1
} pulsador_state_t;

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
