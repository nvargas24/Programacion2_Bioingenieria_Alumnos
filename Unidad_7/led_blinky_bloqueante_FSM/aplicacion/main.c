#include "hardware_init.h"
#include "sys_time.h"
#include "driver_led.h"
#include "app_config.h"

int main(){
    app_state_t currentState = ST_LED_OFF; // Variable para cambio de estados

    /* Inicializacion de hardware */
    BSP_Hardware_Init();

    /* Bucle */
    while(1){
        switch (currentState)
        {
        case ST_LED_OFF:
        		Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
                sysTime_delay_ms(BLINK_PERIOD_MS);
                currentState = LED_ON;
            break;
        case ST_LED_ON:
        		Driver_LED_Set(LED1_PORT, LED1_PIN, LED_ON);
                sysTime_delay_ms(BLINK_PERIOD_MS);
                currentState = LED_OFF;
            break;
        
        default:
            currentState = LED_OFF;
            break;
        }
    }

}
