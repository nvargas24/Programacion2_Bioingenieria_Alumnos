/**
 * Prototipos de funciones que estan disponibles
 * por defecto para el LED
 */
#ifndef DRIVER_LED_H_
#define DRIVER_LED_H_

#include <stdint.h>

/**
 * @brief Estados visuales posibles de un LED.
 *
 * Estos valores son semanticos, no niveles GPIO. En esta placa los LED son
 * activos en bajo: el driver traduce LED_ON a HAL_GPIO_LOW y LED_OFF a HIGH.
 */
typedef enum {
    LED_OFF = 0,
    LED_ON = 1
} LED_state_t;

/**
 * @brief Configura como salida digital el pin del LED.
 * @param port Identificador del puerto GPIO (ej. BOARD_LED_PORT).
 * @param pin  Número de pin del puerto seleccionado (ej. BOARD_LED_PIN).
 */
void Driver_LED_Init(uint8_t port, uint8_t pin);

/**
 * @brief Aplica el estado visual solicitado al LED.
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
