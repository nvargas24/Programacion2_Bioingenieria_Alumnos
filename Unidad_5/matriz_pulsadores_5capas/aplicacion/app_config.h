#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#include "../drivers/driver_matriz.h"
#include "../registros/pin_mux.h"

typedef enum {
	LED1_PORT = BOARD_LED_BLUE_PORT,
	LED1_PIN = BOARD_LED_BLUE_PIN
} leds_t;

#define MATRIX_ROW_COUNT 4U
#define MATRIX_COLUMN_COUNT 4U

#if (MATRIX_ROW_COUNT == 3U) && (MATRIX_COLUMN_COUNT == 3U)
#define MATRIX_KEYMAP "123456789"
#elif (MATRIX_ROW_COUNT == 4U) && (MATRIX_COLUMN_COUNT == 3U)
#define MATRIX_KEYMAP "123456789*0#"
#elif (MATRIX_ROW_COUNT == 4U) && (MATRIX_COLUMN_COUNT == 4U)
#define MATRIX_KEYMAP "123A456B789C*0#D"
#else
#error "Supported keypads are 3x3, 4x3, and 4x4"
#endif

#define MATRIX_DEBOUNCE_MS 20U

#endif
