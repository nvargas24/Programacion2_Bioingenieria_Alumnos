/**
 * Prototipos de funciones que estan disponibles
 * por defecto para el LED
 */
#ifndef DRIVER_LED_H_
#define DRIVER_LED_H_

#include <stdint.h>
#include "hal_defs.h"

/**
 * @brief Estados lógicos y semánticos posibles de un LED.
 *
 * Vincula el comportamiento visual del componente con el nivel físico del hardware.
 */
typedef enum {
    LED_OFF = HAL_GPIO_LOW,  /**< El LED está apagado. Equivale a nivel lógico bajo. */
    LED_ON  = HAL_GPIO_HIGH  /**< El LED está encendido. Equivale a nivel lógico alto. */
} LED_state_t;

/**
 * @brief Configura como salida digital el pin del LED.
 * @param port Identificador del puerto GPIO (ej. BOARD_LED_PORT).
 * @param pin  Número de pin del puerto seleccionado (ej. BOARD_LED_PIN).
 */
void Driver_LED_Init(uint8_t port, uint8_t pin);

/**
 * @brief Asigna estado logico para el LED.
 * @param port  Identificador del puerto GPIO.
 * @param pin   Número de pin del puerto seleccionado.
 * @param state Estado deseado para el LED (LED_ON o LED_OFF).
 */
void Driver_LED_Set(uint8_t port, uint8_t pin, LED_state_t state);

/**
 * @brief Invierte el nivel lógico actual del pin del LED.
 * @param port Identificador del puerto GPIO.
 * @param pin  Número de pin del puerto seleccionado.
 */
void Driver_LED_Toggle(uint8_t port, uint8_t pin);

#endif
