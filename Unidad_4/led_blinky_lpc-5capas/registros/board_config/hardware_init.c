#include "pin_mux.h"
#include "board.h"
#include "hardware_init.h"
#include "clock_config.h"
#include "fsl_common.h"
#include "sys_time.h"


void BSP_Hardware_Init(void)
{
    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    SysTick_Config(SystemCoreClock / 1000U);
    sysTime_init();
}

void SysTick_Handler(){
    sysTime_updateTick();
}