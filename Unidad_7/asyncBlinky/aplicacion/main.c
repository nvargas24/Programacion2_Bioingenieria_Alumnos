// src/app/main.c
#include "hardware_init.h"  
#include "sys_timer.h"       
#include "driver_led.h"     
#include "app_config.h"     

int main(void) {
    BSP_Hardware_Init();
    
    Driver_LED_Init(LED_GREEN_PORT, LED_GREEN_PIN);
    Driver_LED_Init(LED_RED_PORT,   LED_RED_PIN);

    Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
    Driver_LED_Off(LED_RED_PORT,   LED_RED_PIN);

    // Modo Normal (Verde Fijo)
    Driver_LED_On(LED_GREEN_PORT, LED_GREEN_PIN);
    estado_sistema_t estadoActual = ESTADO_NORMAL;

    // Declaramos dos temporizadores 
    sw_timer_t timer_ritmo_rojo;
    sw_timer_t timer_duracion_alerta;

    // Iniciamos un temporizador general de 3 segundos para forzar la primera alerta
    timerStart(&timer_duracion_alerta, DURACION_TOTAL_ALERTA_MS);

    while (1) {
        
        switch (estadoActual) {
            
            case ESTADO_NORMAL:
                // El LED Verde está encendido fijo. 
                // Espera que expiren los 3 segundos.
                if (timer_isExpired(&timer_duracion_alerta)) {
                    
                    // TRANSICIÓN: Apagamos Verde
                    Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
                    Driver_LED_On(LED_RED_PORT,   LED_RED_PIN); // Prende Rojo
                    
                    // Activa temporizadores para la alerta:
                    timerStart(&timer_ritmo_rojo, TIEMPO_PARPADEO_ALERTA_MS); 
                    timerStart(&timer_duracion_alerta, DURACION_TOTAL_ALERTA_MS);
                    
                    estadoActual = ESTADO_ALERTA;
                }
                break;

            case ESTADO_ALERTA:
                // TAREA ASÍNCRONA 1: Rojo destellar rápidamente
                if (timer_isExpired(&timer_ritmo_rojo)) {
                    Driver_LED_Toggle(LED_RED_PORT, LED_RED_PIN);
                }

                // TAREA ASÍNCRONA 2: Evaluar si ya se cumplieron los 3 segundos
                if (timer_isExpired(&timer_duracion_alerta)) {
                    Driver_LED_Off(LED_RED_PORT,   LED_RED_PIN);
                    Driver_LED_On(LED_GREEN_PORT, LED_GREEN_PIN);
                    
                    // Apagamos el temporizador de ritmo 
                    timerStop(&timer_ritmo_rojo);
                    
                    // Reiniciamos el reloj de 3 segundos
                    timerStart(&timer_duracion_alerta, DURACION_TOTAL_ALERTA_MS);
                    
                    estadoActual = ESTADO_NORMAL;
                }
                break;

            default:
                estadoActual = ESTADO_NORMAL;
                break;
        }
    }
}