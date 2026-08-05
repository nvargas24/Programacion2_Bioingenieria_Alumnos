/**
 * @file app_config.h
 * @brief Macros y prototipos para ejemplo led_blinky_azul
 * @details Ejemplo base de SDK blinky migrado a arquitectura de 5 capas, 
 *          priorizando uso de configTools y delay (bloqueante)
 * @author Ing. Vargas Nahuel (nvargas@frh.utn.edu.ar)
 * @copyright 2026 Bioingenieria - UTN-FRH - Todos los derechos reservados
 * @version 1.0.0
 * @note Capa de aplicación
 */
#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#define BLINK_PERIOD_MS 200 // Tiempo de pausa bloqueante
#define LED_PORT LED_BLUE_PORT // Puerto de pin LED AZUL
#define LED_PIN LED_BLUE_PIN // Pin de pin LED AZUL

#endif