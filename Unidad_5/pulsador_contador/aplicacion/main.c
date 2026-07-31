#include "hardware_init.h"
#include "driver_led.h"
#include "driver_pulsador.h"
#include "app_config.h"

int main() {
    // La máquina de estados es gobernada estrictamente por esta variable
    app_state_t pulseCount = STATE_LED_OFF; 

    // 1. Inicialización de los tres canales del LED RGB
    Driver_LED_Init(LED_RED_PORT, LED_RED_PIN);
    Driver_LED_Init(LED_GREEN_PORT, LED_GREEN_PIN);
    Driver_LED_Init(LED_BLUE_PORT, LED_BLUE_PIN);

    // ARRANQUE APAGADO SEGURO: Al energizar la placa, se apaga todo el hardware
    Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
    Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
    Driver_LED_Off(LED_BLUE_PORT, LED_BLUE_PIN);
    
    // 2. Inicialización del pulsador de la placa
    Driver_Pulsador_Init(PULSADOR_PORT, PULSADOR_PIN);

    while(1) {
        // Switch único gobernado por el contador/macro de estado
        switch (pulseCount) 
        {
            case STATE_LED_OFF:
                // El LED inicia y se mantiene APAGADO aquí de manera estable
                if (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN)) {
                    
                    // Acción al presionar: Encendemos Rojo
                    Driver_LED_On(LED_RED_PORT, LED_RED_PIN);
                    
                    // El filtro antirebote detiene el flujo hasta que se suelte el botón física y mecánicamente
                    #ifdef ANTIREBOTE
                    while (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN));
                    #endif
                    
                    // Incrementamos/Cambiamos el estado una vez liberado el pulsador
                    pulseCount = STATE_LED_RED; 
                }
                break;

            case STATE_LED_RED:
                // El LED se mantiene en ROJO estable aquí
                if (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN)) {
                    
                    // Acción al presionar: Cambiar a Verde
                    Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
                    Driver_LED_On(LED_GREEN_PORT, LED_GREEN_PIN);
                    
                    #ifdef ANTIREBOTE
                    while (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN));
                    #endif
                    
                    pulseCount = STATE_LED_GREEN; 
                }
                break;

            case STATE_LED_GREEN:
                // El LED se mantiene en VERDE estable aquí
                if (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN)) {
                    
                    // Acción al presionar: Cambiar a Azul
                    Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
                    Driver_LED_On(LED_BLUE_PORT, LED_BLUE_PIN);
                    
                    #ifdef ANTIREBOTE
                    while (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN));
                    #endif
                    
                    pulseCount = STATE_LED_BLUE; 
                }
                break;

            case STATE_LED_BLUE:
                // El LED se mantiene en AZUL estable aquí
                if (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN)) {
                    
                    // Acción al presionar: Cambiar a Blanco (Rojo + Verde + Azul encendidos)
                    Driver_LED_On(LED_GREEN_PORT, LED_GREEN_PIN);
                    Driver_LED_On(LED_BLUE_PORT, LED_BLUE_PIN);
                    Driver_LED_On(LED_RED_PORT, LED_RED_PIN); // bajo nivel de tension para obtener el blanco --- testear con fuente externa

                    #ifdef ANTIREBOTE
                    while (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN));
                    #endif
                    
                    pulseCount = STATE_LED_WHITE; 
                }
                break;

            case STATE_LED_WHITE:
                // El LED se mantiene en BLANCO estable aquí (Todos los canales encendidos)
                if (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN)) {
                    
                    Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
                    Driver_LED_Off(LED_BLUE_PORT, LED_BLUE_PIN);
                    Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
                    
                    #ifdef ANTIREBOTE
                    while (Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN));
                    #endif
                    
                    // Ciclo directo: Regresamos al estado de color Rojo
                    pulseCount = STATE_LED_OFF; 
                }
                break;
            
            default:
                pulseCount = STATE_LED_OFF;
                break;
        }
    }
}
