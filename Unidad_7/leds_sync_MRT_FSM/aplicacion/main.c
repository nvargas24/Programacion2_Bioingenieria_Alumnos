#include "hardware_init.h"
#include "sys_time.h"
#include "driver_led.h"
#include "app_config.h"
#include <stdbool.h>
#include "fsl_mrt.h"


volatile bool mrt_ch0 = false; // cada 200ms
volatile bool mrt_ch1 = false; // cada 500ms

int main(void)
{
    app_state_t currentState = ST_OFF;

    BSP_Hardware_Init();


    while (1)
    {
        switch (currentState)
        {
        case ST_OFF:
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);

            currentState = ST_BLINKY;

            break;

        case ST_BLINKY:
        	if(mrt_ch0 == true && mrt_ch1 == true){
        		currentState = ST_SYNC;
        	}
        	else{
            	if(mrt_ch0 == true){
            		mrt_ch0 = false;
                    Driver_LED_Toggle(LED1_PORT, LED1_PIN);
            	}
            	if(mrt_ch1 == true){
            		mrt_ch1 = false;
            		Driver_LED_Toggle(LED2_PORT, LED2_PIN);
            	}
        	}
            break;
        case ST_SYNC:
        	mrt_ch0 = false;
        	mrt_ch1 = false;
            Driver_LED_Toggle(LED_SYNC_PORT, LED_SYNC_PIN);

        	currentState = ST_BLINKY;
        	break;

        default:
            break;
        }
    }
}

void MRT0_IRQHandler(void)
{
    if ((MRT_GetStatusFlags(MRT0, kMRT_Channel_0) & kMRT_TimerInterruptFlag) != 0) // Estado de flag del MRT0
    {
        MRT_ClearStatusFlags(MRT0, kMRT_Channel_0, kMRT_TimerInterruptFlag);
        mrt_ch0 = true;
    }

    if ((MRT_GetStatusFlags(MRT0, kMRT_Channel_1) & kMRT_TimerInterruptFlag) != 0) // Estado de flag del MRT1
    {
        MRT_ClearStatusFlags(MRT0, kMRT_Channel_1, kMRT_TimerInterruptFlag);
        mrt_ch1 = true;
    }
}
