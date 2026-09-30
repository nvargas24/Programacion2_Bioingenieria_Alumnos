#include "app_config.h"
#include "hardware_init.h"
#include "clock_config.h"
#include "fsl_common.h"
#include "pin_mux.h"
#include "sys_time.h"

const display_config_t g_display_config = {
    .segment_pins = {
        {BOARD_DISPLAY_SEGMENT_A_PORT, BOARD_DISPLAY_SEGMENT_A_PIN},
        {BOARD_DISPLAY_SEGMENT_B_PORT, BOARD_DISPLAY_SEGMENT_B_PIN},
        {BOARD_DISPLAY_SEGMENT_C_PORT, BOARD_DISPLAY_SEGMENT_C_PIN},
        {BOARD_DISPLAY_SEGMENT_D_PORT, BOARD_DISPLAY_SEGMENT_D_PIN},
        {BOARD_DISPLAY_SEGMENT_E_PORT, BOARD_DISPLAY_SEGMENT_E_PIN},
        {BOARD_DISPLAY_SEGMENT_F_PORT, BOARD_DISPLAY_SEGMENT_F_PIN},
        {BOARD_DISPLAY_SEGMENT_G_PORT, BOARD_DISPLAY_SEGMENT_G_PIN}
    },
    .digit_pins = {
        {BOARD_DISPLAY_DIGIT_UNITS_PORT, BOARD_DISPLAY_DIGIT_UNITS_PIN},
        {BOARD_DISPLAY_DIGIT_TENS_PORT, BOARD_DISPLAY_DIGIT_TENS_PIN}
    },
    .digit_count = DISPLAY_DIGIT_COUNT,
    .type = DISPLAY_TYPE,
    .digit_select = DISPLAY_DIGIT_SELECT
};

void BSP_Hardware_Init(void)
{
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    SysTick_Config(SystemCoreClock / 1000U);
    sysTime_init();
    Driver_Display_Init(&g_display_config);
}

void SysTick_Handler(void)
{
    sysTime_updateTick();
}
