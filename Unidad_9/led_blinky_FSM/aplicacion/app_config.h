/**
 * @file app_config.h
 * @brief Macros y prototipos para ejemplo led_blinky_rojo
 * @details Ejemplo base de SDK blinky migrado a arquitectura de 5 capas, 
 *          priorizando uso de configTools y delay (bloqueante)
 * @author Ing. Vargas Nahuel (nvargas@frh.utn.edu.ar)
 * @copyright 2026 Bioingenieria - UTN-FRH - Todos los derechos reservados
 * @version 1.0.0
 * @note Capa de aplicación
 */
#include "pin_mux.h"

#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#define BLINK_PERIOD_MS 3000 // Tiempo de pausa en ms

// Estados posibles
typedef enum {
    ST_LED_OFF,
    ST_LED_ON
} app_state_t;

typedef enum {
    LED1_PORT = BOARD_LED_RED_PORT,
	LED1_PIN = BOARD_LED_RED_PIN,
} leds_t;
#endif
