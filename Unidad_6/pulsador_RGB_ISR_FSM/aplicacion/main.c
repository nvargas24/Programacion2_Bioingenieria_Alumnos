/**
 * @file main.c
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
#include "fsl_pint.h"

#include <stdint.h>

volatile uint8_t flag_k3 = BTN_RELEASED;

int main() {
    estado_fsm_t estado_actual = ST_ROJO;

    BSP_Hardware_Init();

    while (1) {
    	switch (estado_actual) {
    	        case ST_ROJO:
    	            Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_ON);
    	            Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_OFF);
    	            Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_OFF);

    	            if (flag_k3) {
    	                flag_k3 = false;
    	                estado_actual = ST_VERDE;
    	            }
    	            break;

    	        case ST_VERDE:
    	            Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
    	            Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_ON);
    	            Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_OFF);

    	            if (flag_k3) {
    	                flag_k3 = false;
    	                estado_actual = ST_AZUL;
    	            }
    	            break;

    	        case ST_AZUL:
    	            Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
    	            Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_OFF);
    	            Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_ON);

    	            if (flag_k3) {
    	                flag_k3 = false;
    	                estado_actual = ST_ROJO;
    	            }
    	            break;
    	        }
    	    }
}

/**
 * @brief Rutina de Interrupción (ISR) para K3 (Canal 0 de PINT)
 * @details Se ejecuta de forma asíncrona e inmediata al presionar K3.
 */
void PIN_INT0_IRQHandler(void)
{
    uint32_t flag_rise = PINT_PinInterruptGetRiseFlag(PINT, kPINT_PinInt0);

    if (flag_rise)
    {
        PINT_PinInterruptClrRiseFlag(PINT, kPINT_PinInt0);
        flag_k3 = BTN_PRESSED;
    }

    __DSB();
}
