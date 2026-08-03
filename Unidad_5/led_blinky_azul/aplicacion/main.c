#include "hardware_init.h"
#include "sys_time.h"
#include "sys_timer.h"
#include "driver_led.h"
#include "app_config.h"

int main(){
    /* Inicializa hardware */
    BSP_Hardware_Init(); 

    Driver_LED_Init(LED_PORT, LED_PIN);
    Driver_LED_Off(LED_PORT, LED_PIN);

    /* Bucle */
    while(1){
        Driver_LED_On(LED_PORT, LED_PIN); // No se procesa datos solo se llamada driver para ENCENDIDO
        sysTime_delay_ms(BLINK_PERIOD_MS); // Se recurre a servicio de delay bloqueante
        Driver_LED_Off(LED_PORT, LED_PIN);
        sysTime_delay_ms(BLINK_PERIOD_MS);
    }
}