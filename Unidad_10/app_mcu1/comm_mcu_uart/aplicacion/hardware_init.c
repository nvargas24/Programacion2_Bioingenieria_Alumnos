#include "hardware_init.h"
#include "clock_config.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "fsl_common.h"
#include "sys_time.h"

void BSP_Hardware_Init(void)
{
    /* Inicializacion generada por MCUXpresso Config Tools. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    /* Base de tiempo del sistema con periodo de 1 ms. */
    SysTick_Config(SystemCoreClock / 1000U);
    sysTime_init();
}

void SysTick_Handler(void)
{
    sysTime_updateTick();
}
