#include "hardware_init.h"
#include "driver_led.h"
#include "driver_pulsador.h"
#include "app_config.h"

int main() {
    app_state_t currentState = STATE_LED_OFF;

    // 1. Inicialización de los periféricos mediante los drivers
    Driver_LED_Init(LED_RED_PORT, LED_RED_PIN);
    Driver_LED_Off(LED_RED_PORT, LED_RED_PIN); // Asegurar inicio apagado
    
    Driver_Pulsador_Init(PULSADOR_PORT, PULSADOR_PIN);

    while(1) {
        switch (currentState) 
        {
            case STATE_LED_OFF:
                // Polling: Si el pulsador es presionado
                if (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN)) {     
                    Driver_LED_On(LED_RED_PORT, LED_RED_PIN); // Encendemos el LED
                    // Al soltar el pulsador, cambiamos de estado
                    currentState = STATE_LED_ON;
                }
                break;

            case STATE_LED_ON:
                // Polling: Si se vuelve a presionar el pulsador
                if (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN)) {
                    Driver_LED_Off(LED_RED_PORT, LED_RED_PIN); // Apagamos el LED
                    // Al soltar el pulsador, regresamos al estado inicial
                    currentState = STATE_LED_OFF;
                }
                break;
            
            default:
                Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
                currentState = STATE_LED_OFF;
                break;
        }
    }
}
