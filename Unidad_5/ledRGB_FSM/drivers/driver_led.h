/**
 * Prototipos de funciones que estan disponibles
 * por defecto para el LED
 */
#ifndef DRIVER_LED_H_
#define DRIVER_LED_H_

#include <stdint.h>

void Driver_LED_Init(uint8_t port, uint8_t pin);
void Driver_LED_On(uint8_t port, uint8_t pin);
void Driver_LED_Off(uint8_t port, uint8_t pin);
void Driver_LED_Toggle(uint8_t port, uint8_t pin);

#endif