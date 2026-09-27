/**
 * @file app_config.h
 * @brief Configuracion de la aplicacion blinky para el LED rojo.
 * @details BLINK_PERIOD_MS define la duracion de cada fase encendida/apagada.
 *          El pin se obtiene de pin_mux.h y el retardo es bloqueante.
 * @author Ing. Vargas Nahuel (nvargas@frh.utn.edu.ar)
 * @copyright 2026 Bioingenieria - UTN-FRH - Todos los derechos reservados
 * @version 1.0.0
 * @note Capa de aplicación
 */
#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#include "pin_mux.h"

typedef enum {
	LED1_PORT = BOARD_LED_RED_PORT,
	LED1_PIN = BOARD_LED_RED_PIN
} leds_t;

#define BLINK_PERIOD_MS 2700U // Duracion de cada fase del parpadeo, en ms.

#endif
