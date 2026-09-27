/**
 * @file main.c
 * @brief Ejemplo de lectura de K3 y control del LED azul.
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
#include "driver_led.h"
#include "driver_pulsador.h"
#include "app_config.h"


int main() {
	/* Variables */
    pulsador_state_t state_btn = BTN_RELEASED;

    /* Setup - Configuracion HW*/
    BSP_Hardware_Init(); //Inicializa pines, clocks y SysTick de la placa

    Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
    
    /* Loop */
    while(1) {
        state_btn = Driver_Pulsador_Read(PULSADOR1_PORT, PULSADOR1_PIN);

        if (state_btn == BTN_PRESSED) {
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_ON);
        } 
        else {
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
        }
    }
}
