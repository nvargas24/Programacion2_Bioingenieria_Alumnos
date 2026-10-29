#include "hardware_init.h"
#include "sys_time.h"
#include "driver_led.h"
#include "app_config.h"
#include <stdbool.h>
#include "fsl_mrt.h"

#define MRT_TICK_MS          100
#define LED_INTERVAL_MS     2000
#define LED_INTERVAL_TICKS  (LED_INTERVAL_MS / MRT_TICK_MS)

volatile uint32_t mrt_tick_count = 0;


int main(void)
{
    app_state_t currentState = ST_LED_OFF;
    uint32_t state_start_tick = 0;
    uint32_t now = 0;

    BSP_Hardware_Init();


    while (1)
    {
        now = mrt_tick_count;

        switch (currentState)
        {
        case ST_LED_OFF:
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);

            if ((now - state_start_tick) >= LED_INTERVAL_TICKS)
            {
                state_start_tick = now;
                currentState = ST_LED_ON;
            }
            break;

        case ST_LED_ON:
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_ON);

            if ((now - state_start_tick) >= LED_INTERVAL_TICKS)
            {
                state_start_tick = now;
                currentState = ST_LED_OFF;
            }
            break;

        default:
            currentState = ST_LED_OFF;
            state_start_tick = now;
            break;
        }
    }
}

void MRT0_IRQHandler(void)
{
    if ((MRT_GetStatusFlags(MRT0, kMRT_Channel_0) & kMRT_TimerInterruptFlag) != 0) // Estado de flag del MRT0
    {
        MRT_ClearStatusFlags(MRT0, kMRT_Channel_0, kMRT_TimerInterruptFlag);
        mrt_tick_count++;
    }
}
