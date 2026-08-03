#include "hardware_init.h" 
#include "sys_time.h"
#include "sys_timer.h"
#include "driver_led.h"
#include "app_config.h"

int main(void) {
    sw_timer_t colorTimer;
    app_state_t currentState = STATE_COLOR_RED;

    BSP_Hardware_Init();

    // Inicializa los tres GPIO independiente 
    Driver_LED_Init(LED_BLUE_PORT,  LED_BLUE_PIN);
    Driver_LED_Init(LED_RED_PORT,   LED_RED_PIN);
    Driver_LED_Init(LED_GREEN_PORT, LED_GREEN_PIN);

    // Asegura un estado inicial apagado para todo el conjunto RGB
    Driver_LED_Off(LED_BLUE_PORT,  LED_BLUE_PIN);
    Driver_LED_Off(LED_RED_PORT,   LED_RED_PIN);
    Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);

    // Enciende el primer color de la secuencia para arrancar ordenadamente
    Driver_LED_On(LED_RED_PORT, LED_RED_PIN);
    
    timerStart(&colorTimer, COLOR_ROTATION_PERIOD_MS);

    while (1) {
        // Máquina de estados
        switch (currentState) {
            case STATE_COLOR_RED:
                if (timer_isExpired(&colorTimer)) {
                    // Transición: Apaga Rojo y enciende Verde
                    Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
                    Driver_LED_On(LED_GREEN_PORT, LED_GREEN_PIN);
                    currentState = STATE_COLOR_GREEN;
                }
                break;

            case STATE_COLOR_GREEN:
                if (timer_isExpired(&colorTimer)) {
                    // Transición: Apaga Verde y enciende Azul
                    Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
                    Driver_LED_On(LED_BLUE_PORT, LED_BLUE_PIN);
                    currentState = STATE_COLOR_BLUE;
                }
                break;

            case STATE_COLOR_BLUE:
                if (timer_isExpired(&colorTimer)) {
                    // Transición: Apaga Azul y vuelve a empezar en Rojo
                    Driver_LED_Off(LED_BLUE_PORT, LED_BLUE_PIN);
                    Driver_LED_On(LED_RED_PORT, LED_RED_PIN);
                    currentState = STATE_COLOR_RED;
                }
                break;

            default:
                // Estado de recuperación ante fallos de memoria o corrupción de estado
                Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
                Driver_LED_Off(LED_BLUE_PORT,  LED_BLUE_PIN);
                Driver_LED_On(LED_RED_PORT,   LED_RED_PIN);
                currentState = STATE_COLOR_RED;
                break;
        }
    }
}
