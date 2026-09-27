/**
 * @file main.c
 * @brief Ejemplo de lectura de K3 y control del LED rojo.
 * @details Para LPC845BRK y arquitectura de cinco capas. Inicializa la BSP y los
 *          drivers, luego lee K3 y enciende/apaga el LED segun el estado reportado.
 * @note Uso: importar en MCUXpresso, compilar para LPC845BRK y debuggear en la placa.
 * @warning No implementa antirrebote; procesa directamente cada lectura del pulsador.
 * @author Ing. Vargas Nahuel (nvargas@frh.utn.edu.ar)
 * @copyright 2026 Bioingenieria - UTN-FRH. Todos los derechos reservados.
 * @note Licencia: este ejemplo no declara una licencia independiente. Los archivos de NXP/CMSIS
 *       conservan sus avisos y licencias originales; consultarlos antes de redistribuir.
 */

#include "hardware_init.h"
#include "pin_mux.h"
#include "driver_led.h"
#include "driver_pulsador.h"
#include "app_config.h"
#include "driver_led.h"
#include "driver_pulsador.h"


int main() {
    app_state_t currentState = STATE_READ_BTN;
    pulsador_state_t state_btn = BTN_RELEASED;

    /* Inicializa pines, clocks y SysTick de la placa; este ejercicio no usa el tick. */
    BSP_Hardware_Init();

    Driver_LED_Init(BOARD_LED_RED_PORT, BOARD_LED_RED_PIN);
    Driver_Pulsador_Init(BOARD_K3_PORT, BOARD_K3_PIN);

    Driver_LED_Set(BOARD_LED_RED_PORT, BOARD_LED_RED_PIN, LED_OFF);
    
    while(1) {
        switch (currentState) 
        {
        	case STATE_READ_BTN:
        		state_btn = Driver_Pulsador_Read(BOARD_K3_PORT, BOARD_K3_PIN);

        		if(state_btn == BTN_PRESSED){
        			currentState = STATE_LED_ON;
        		}
        		else if(state_btn == BTN_RELEASED){
        			currentState = STATE_LED_OFF;
        		}
        		break;
            case STATE_LED_OFF:
                	Driver_LED_Set(BOARD_LED_RED_PORT, BOARD_LED_RED_PIN, LED_OFF);
                    currentState = STATE_READ_BTN;
                break;
            case STATE_LED_ON:
                    Driver_LED_Set(BOARD_LED_RED_PORT, BOARD_LED_RED_PIN, LED_ON);
                    currentState = STATE_READ_BTN;
                break;
            
            default:
                Driver_LED_Set(BOARD_LED_RED_PORT, BOARD_LED_RED_PIN, LED_OFF);
                currentState = STATE_READ_BTN;
                break;
        }
    }
}
