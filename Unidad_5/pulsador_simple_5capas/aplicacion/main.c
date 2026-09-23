#include "hardware_init.h"
#include "driver_led.h"
#include "driver_pulsador.h"
#include "app_config.h"
#include "driver_led.h"
#include "driver_pulsador.h"

int main() {
    app_state_t currentState = STATE_READ_BTN;
    pulsador_state_t state_btn = BTN_RELEASED;

    Driver_LED_Init(LED_RED_PORT, LED_RED_PIN);
    Driver_Pulsador_Init(PULSADOR_PORT, PULSADOR_PIN);

    Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
    
    while(1) {
        switch (currentState) 
        {
        	case STATE_READ_BTN:
        		state_btn = Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN);

        		if(state_btn == BTN_PRESSED){
        			currentState = STATE_LED_ON;
        		}
        		else if(state_btn == BTN_RELEASED){
        			currentState = STATE_LED_OFF;
        		}
        		break;
            case STATE_LED_OFF:
                	Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
                    currentState = STATE_READ_BTN;
                break;
            case STATE_LED_ON:
                    Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_ON);
                    currentState = STATE_READ_BTN;
                break;
            
            default:
                Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
                currentState = STATE_READ_BTN;
                break;
        }
    }
}
