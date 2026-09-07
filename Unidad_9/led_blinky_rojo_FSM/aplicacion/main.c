#include "hardware_init.h"
#include "sys_time.h"
#include "driver_led.h"
#include "app_config.h"

int main(){
    app_state_t currentState = LED_OFF; // Variable para cambio de estados

    /* Inicializacion de hardware */
    BSP_Hardware_Init();

    Driver_LED_Init(LED_RED_PORT, LED_RED_PIN);
    Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);

    /* Bucle */
    while(1){
        switch (currentState)
        {
        case LED_OFF:
                Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
                sysTime_delay_ms(BLINK_PERIOD_MS);
                currentState = LED_ON;
            break;
        case LED_ON:
                Driver_LED_On(LED_RED_PORT, LED_RED_PIN);
                sysTime_delay_ms(BLINK_PERIOD_MS);
                currentState = LED_OFF;
            break;
        
        default:
            currentState = LED_OFF;
            break;
        }
    }

}