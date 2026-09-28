/**
 * Driver de LED: ofrece estados semanticos y delega el acceso GPIO a la HAL.
 */
#ifndef DRIVER_LED_H_
#define DRIVER_LED_H_

#include <stdint.h>

/**
 * Estados visuales, independientes de los niveles electricos del GPIO.
 * En esta placa los LED son activos en bajo: LED_ON aplica LOW y LED_OFF HIGH.
 */
typedef enum {
    LED_OFF = 0,
    LED_ON = 1
} LED_state_t;
/* Inicializa como salida el pin indicado por los macros BOARD_* de pin_mux.h. */
void Driver_LED_Init(uint8_t port, uint8_t pin);
/* Traduce LED_ON/OFF al nivel electrico segun la polaridad del LED. */
void Driver_LED_Set(uint8_t port, uint8_t pin, LED_state_t state);
/* Invierte el nivel actual del pin. */
void Driver_LED_Toggle(uint8_t port, uint8_t pin);

#endif