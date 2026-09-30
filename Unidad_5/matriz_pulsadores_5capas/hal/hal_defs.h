/**
 * @file hal_defs.h
 * @brief Definiciones generales de estado y dirección para la capa HAL.
 *
 * Contiene las abstracciones básicas para interpretar los niveles eléctricos
 * (HIGH/LOW) y la dirección de los pines (INPUT/OUTPUT).
 *
 * @note Estas definiciones representan el comportamiento físico del hardware
 *       y no deben confundirse con los estados semánticos de componentes
 *       específicos (como LED_ON/OFF o BTN_PRESSED/RELEASED).
 */

#ifndef HAL_DEFS_H_
#define HAL_DEFS_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Niveles lógicos de voltaje en los pines GPIO.
 */
typedef enum {
    HAL_GPIO_LOW  = 0,  /**< Nivel lógico bajo (0 lógico, típicamente 0V). */
    HAL_GPIO_HIGH = 1   /**< Nivel lógico alto (1 lógico, típicamente VCC). */
} hal_gpio_state_t;

/**
 * @brief Dirección de configuración operacional de un pin GPIO.
 */
typedef enum {
    HAL_GPIO_INPUT  = 0,  /**< Configuración del pin como entrada digital. */
    HAL_GPIO_OUTPUT = 1   /**< Configuración del pin como salida digital. */
} hal_gpio_dir_t;

#endif /* HAL_DEFS_H_ */
