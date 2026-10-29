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
#include <stdbool.h>

#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_


// Estados posibles
typedef enum {
    ST_OFF,
    ST_BLINKY,
} app_state_t;

typedef enum {
    LED1_PORT = BOARD_LED1_PORT,
	LED1_PIN = BOARD_LED1_PIN,
    LED2_PORT = BOARD_LED2_PORT,
	LED2_PIN = BOARD_LED2_PIN,
} leds_t;

#endif
