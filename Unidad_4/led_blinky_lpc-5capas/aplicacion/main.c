#include "hardware_init.h"
#include "sys_time.h"
#include "driver_led.h"
#include "app_config.h"

int main(){
    uint32_t lastToggleTick = 0;
    app_state_t currentState = LED_OFF;

    BSP_Hardware_Init();

    Driver_LED_Init(LED_RED_PORT, LED_RED_PIN);
    Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);

    lastToggleTick = sysTime_getTicks();

    while(1){
        switch (currentState)
        {
        case LED_OFF:
            if(sysTime_hasElapsed(lastToggleTick, BLINK_PERIOD_MS)){
                Driver_LED_On(LED_RED_PORT, LED_RED_PIN);
                lastToggleTick = sysTime_getTicks();
                currentState = LED_ON;
            }
            break;
        case LED_ON:
            if(sysTime_hasElapsed(lastToggleTick, BLINK_PERIOD_MS)){
                Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
                lastToggleTick = sysTime_getTicks();
                currentState = LED_OFF;
            }
            break;
        
        default:
            currentState = LED_OFF;
            break;
        }
    }

}