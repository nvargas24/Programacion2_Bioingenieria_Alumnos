#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#include "pin_mux.h"

typedef enum {
	LED_RED_PORT = BOARD_LED_RED_PORT,
	LED_RED_PIN = BOARD_LED_RED_PIN,
	LED_GREEN_PORT = BOARD_LED_GREEN_PORT,
	LED_GREEN_PIN = BOARD_LED_GREEN_PIN,
	LED_BLUE_PORT = BOARD_LED_BLUE_PORT,
	LED_BLUE_PIN = BOARD_LED_BLUE_PIN,
} leds_t;

typedef enum {
    PULSADOR_PORT = BOARD_K3_PORT,
	PULSADOR_PIN = BOARD_K3_PIN
} pulsadores_t;

typedef enum {
    ST_ROJO,
	ST_VERDE,
	ST_AZUL,
} estado_fsm_t;

#endif
