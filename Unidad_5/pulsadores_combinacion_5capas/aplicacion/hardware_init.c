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
    /* Inicialización de los drivers para los Pines de salida (LEDs) */
    Driver_LED_Init(LED1_PORT, LED1_PIN);
    Driver_LED_Init(LED2_PORT, LED2_PIN);
    Driver_LED_Init(LED3_PORT, LED3_PIN);

    /* Inicialización de los drivers para los Pines de entrada (Pulsadores) */
    Driver_Pulsador_Init(PULSADOR2_PORT, PULSADOR2_PIN);
    Driver_Pulsador_Init(PULSADOR3_PORT, PULSADOR3_PIN);
}

void SysTick_Handler(){
    sysTime_updateTick();
}
