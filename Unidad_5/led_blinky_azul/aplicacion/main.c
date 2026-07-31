#include "hardware_init.h"
#include "sys_time.h"
#include "sys_timer.h"
#include "driver_led.h"
#include "app_config.h"

int main(){
    sw_timer_t blinkTimer;
    app_state_t currentState = LED_OFF;

    BSP_Hardware_Init();

    Driver_LED_Init(LED_PORT, LED_PIN);
    Driver_LED_Off(LED_PORT, LED_PIN);

    timerStart(&blinkTimer, BLINK_PERIOD_MS);

    while(1){
        switch (currentState)
        {
        case LED_OFF:
            if(timer_isExpired(&blinkTimer)){
                Driver_LED_On(LED_PORT, LED_PIN);
                currentState = LED_ON;
            }
            break;
        case LED_ON:
            if(timer_isExpired(&blinkTimer)){
                Driver_LED_Off(LED_PORT, LED_PIN);
                currentState = LED_OFF;
            }
            break;
        
        default:
            currentState = LED_OFF;
            break;
        }
    }

}