/**
 * @file hal_gpio.h
 * @brief Adaptación de las operaciones GPIO de la HAL sobre el SDK de NXP.
 *
 * Este módulo actúa como una capa de abstracción que adapta las funciones del SDK de NXP
 * a la interfaz unificada del proyecto.
 *
 * @note La configuración del multiplexor de pines (Pin Mux) y sus propiedades
 *       eléctricas específicas se gestionan externamente en el archivo pin_mux.h.
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

#include "hal_defs.h"

/**
 * @brief Inicializa y configura la dirección de un pin GPIO.
 *
 * @param port      Identificador del puerto GPIO (ej. PORT_1).
 * @param pin       Número de pin del puerto seleccionado.
 * @param direction Dirección deseada para el pin (HAL_GPIO_INPUT o HAL_GPIO_OUTPUT).
 */
void HAL_GPIO_InitPin(
    uint8_t port, 
    uint8_t pin, 
    hal_gpio_dir_t direction
);

/**
 * @brief Escribe un nivel lógico en un pin configurado como salida.
 *
 * @param port  Identificador del puerto GPIO.
 * @param pin   Número de pin del puerto seleccionado.
 * @param state Nivel lógico a aplicar en el pin (HAL_GPIO_LOW o HAL_GPIO_HIGH).
 */
void HAL_GPIO_WritePin(
    uint8_t port, 
    uint8_t pin, 
    hal_gpio_state_t state
);

/**
 * @brief Invierte el nivel lógico actual de un pin GPIO de salida.
 *
 * @param port Identificador del puerto GPIO.
 * @param pin  Número de pin del puerto seleccionado.
 */
void HAL_GPIO_TogglePin(
    uint8_t port, 
    uint8_t pin
);

/**
 * @brief Lee el nivel lógico actual de un pin GPIO de entrada.
 *
 * @param port Identificador del puerto GPIO.
 * @param pin  Número de pin del puerto seleccionado.
 *
 * @return hal_gpio_state_t Nivel logico leido, sin invertir.
 */
hal_gpio_state_t HAL_GPIO_ReadPin(
    uint8_t port,
    uint8_t pin
);

#endif /* HAL_GPIO_H_ */
