#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#include "pin_mux.h"

typedef enum {
    LED1_PORT = BOARD_LED_BLUE_PORT,
	LED1_PIN = BOARD_LED_BLUE_PIN,
} leds_t;

typedef enum {
    PULSADOR1_PORT = BOARD_K3_PORT,
	PULSADOR1_PIN = BOARD_K3_PIN
} pulsadores_t;

typedef enum{
    ST_READ_PULSADOR1,
    ST_LED_ON,
    ST_LED_OFF
} app_state_t;

#endif
