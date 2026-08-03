#include "hardware_init.h" 
#include "sys_time.h"
#include "driver_led.h"
#include "app_config.h"

int main(void) {
    app_state_t currentState = LEDS_OFF;

    /* Inicializacion de hardware */
    BSP_Hardware_Init();

    Driver_LED_Init(LED_BLUE_PORT,  LED_BLUE_PIN);
    Driver_LED_Init(LED_RED_PORT,   LED_RED_PIN);
    Driver_LED_Init(LED_GREEN_PORT, LED_GREEN_PIN);

    /* Bucle */
    while (1) {
        switch (currentState) {
            case LEDS_OFF:
                Driver_LED_Off(LED_BLUE_PORT,  LED_BLUE_PIN);
                Driver_LED_Off(LED_RED_PORT,   LED_RED_PIN);
                Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);      
                currentState = COLOR_ROJO;         
                break;

            case COLOR_ROJO:
                Driver_LED_On(LED_RED_PORT, LED_RED_PIN);
                sysTime_delay_ms(COLOR_ROTATION_PERIOD_MS);
                Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
                currentState = COLOR_VERDE;
                break;

            case COLOR_VERDE:
                Driver_LED_On(LED_GREEN_PORT, LED_GREEN_PIN);
                sysTime_delay_ms(COLOR_ROTATION_PERIOD_MS);
                Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
                currentState = COLOR_AZUL;
                break;

            case COLOR_AZUL:
                Driver_LED_On(LED_BLUE_PORT, LED_BLUE_PIN);
                sysTime_delay_ms(COLOR_ROTATION_PERIOD_MS);
                Driver_LED_Off(LED_BLUE_PORT, LED_BLUE_PIN);
                currentState = COLOR_ROJO;
                break;

            default:
                currentState = LEDS_OFF;
                break;
        }
    }
}
