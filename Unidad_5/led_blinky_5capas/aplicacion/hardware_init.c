#include "app_config.h"
#include "hardware_init.h"
#include "clock_config.h"
#include "fsl_common.h"
#include "sys_time.h"
#include "driver_led.h"

void BSP_Hardware_Init(void)
{
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    SysTick_Config(SystemCoreClock / 1000U);
    sysTime_init();

    Driver_LED_Init(LED1_PORT, LED1_PIN);
}

void SysTick_Handler(void)
{
    sysTime_updateTick();
}