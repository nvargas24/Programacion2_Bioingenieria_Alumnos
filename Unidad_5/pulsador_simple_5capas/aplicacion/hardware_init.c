#include "app_config.h"
#include "hardware_init.h"
#include "clock_config.h"
#include "fsl_common.h"
#include "sys_time.h"
#include "driver_led.h"
#include "driver_pulsador.h"

void BSP_Hardware_Init(void)
{
	/* sysTick*/
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    SysTick_Config(SystemCoreClock / 1000U);
    sysTime_init();

    /* LEDs y pulsadores */
    Driver_LED_Init(LED1_PORT, LED1_PIN);
    Driver_Pulsador_Init(PULSADOR1_PORT, PULSADOR1_PIN);
}

void SysTick_Handler(){
    sysTime_updateTick();
}
