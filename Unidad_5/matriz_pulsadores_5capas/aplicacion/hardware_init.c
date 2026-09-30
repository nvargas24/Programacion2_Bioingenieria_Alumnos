#include "app_config.h"
#include "hardware_init.h"
#include "../drivers/driver_led.h"
#include "../drivers/driver_matriz.h"
#include "../hal/fsl_common.h"
#include "../registros/clock_config.h"
#include "../registros/pin_mux.h"
#include "../servicios/sys_time.h"

static const char matrix_keymap[] = MATRIX_KEYMAP;

static const matriz_config_t matrix_config = {
    .filas = {
        {BOARD_MATRIX_ROW_0_PORT, BOARD_MATRIX_ROW_0_PIN},
        {BOARD_MATRIX_ROW_1_PORT, BOARD_MATRIX_ROW_1_PIN},
        {BOARD_MATRIX_ROW_2_PORT, BOARD_MATRIX_ROW_2_PIN},
        {BOARD_MATRIX_ROW_3_PORT, BOARD_MATRIX_ROW_3_PIN}
    },
    .columnas = {
        {BOARD_MATRIX_COLUMN_0_PORT, BOARD_MATRIX_COLUMN_0_PIN},
        {BOARD_MATRIX_COLUMN_1_PORT, BOARD_MATRIX_COLUMN_1_PIN},
        {BOARD_MATRIX_COLUMN_2_PORT, BOARD_MATRIX_COLUMN_2_PIN},
        {BOARD_MATRIX_COLUMN_3_PORT, BOARD_MATRIX_COLUMN_3_PIN}
    },
    .cantidad_filas = MATRIX_ROW_COUNT,
    .cantidad_columnas = MATRIX_COLUMN_COUNT,
    .mapa_teclas = matrix_keymap
};

void BSP_Hardware_Init(void)
{
	/* sysTick*/
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    SysTick_Config(SystemCoreClock / 1000U);
    sysTime_init();

    /* LED de confirmacion y matriz de teclas */
    Driver_LED_Init(LED1_PORT, LED1_PIN);
    if (!Driver_Matriz_Init(&matrix_config)) {
        while (1) {
        }
    }
}

void SysTick_Handler(){
    sysTime_updateTick();
}
