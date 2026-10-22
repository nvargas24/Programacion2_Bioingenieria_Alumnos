#include "app_config.h"
#include "hardware_init.h"
#include "clock_config.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "fsl_common.h"
#include "sys_time.h"

void BSP_Hardware_Init(void)
{
	/* configTools*/
    BOARD_InitBootPins(); //PinTools
    BOARD_InitBootClocks(); //ClocksTools
    BOARD_InitBootPeripherals(); //PeriphericalTools

    SysTick_Config(SystemCoreClock / 1000U);
    sysTime_init();
}

void SysTick_Handler(){
    sysTime_updateTick();
}
