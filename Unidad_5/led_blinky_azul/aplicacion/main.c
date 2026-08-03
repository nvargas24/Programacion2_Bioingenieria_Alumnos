#include "hardware_init.h"
#include "sys_time.h"
#include "sys_timer.h"
#include "driver_led.h"
#include "app_config.h"

int main(){
    BSP_Hardware_Init();

    Driver_LED_Init(LED_PORT, LED_PIN);
    Driver_LED_Off(LED_PORT, LED_PIN);

    while(1){
        Driver_LED_On(LED_PORT, LED_PIN);
        sysTime_delay_ms(BLINK_PERIOD_MS);
        Driver_LED_Off(LED_PORT, LED_PIN);
        sysTime_delay_ms(BLINK_PERIOD_MS);
    }

}