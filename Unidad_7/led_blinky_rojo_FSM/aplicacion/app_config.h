/**
 * @file app_config.h
 * @brief Macros y prototipos para ejemplo led_blinky_rojo
 * @details Ejemplo base de SDK blinky migrado a arquitectura de 5 capas, 
 *          priorizando uso de configTools y temporizador Tick (no bloqueante)
 * @author Ing. Vargas Nahuel (nvargas@frh.utn.edu.ar)
 * @copyright 2026 Bioingenieria - UTN-FRH - Todos los derechos reservados
 * @version 1.0.0
 * @note Capa de aplicación
 */
#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#define BLINK_PERIOD_MS 3000

typedef enum {
    LED_OFF,
    LED_ON
} app_state_t;

#endif