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
#include "fsl_pint.h"

#include <stdint.h>

volatile uint8_t flag_btn = BTN_RELEASED;

int main() {
    estado_fsm_t estado_actual = ST_LED_OFF;

    BSP_Hardware_Init();

    while (1) {
        switch (estado_actual) {
        case ST_LED_OFF:
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
            if (flag_btn == BTN_PRESSED) {
                estado_actual = ST_LED_ON;
            }
            break;

        case ST_LED_ON:
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_ON);
            if (flag_btn == BTN_RELEASED) {
                estado_actual = ST_LED_OFF;
            }
            break;
        }
    }
}

/**
 * @brief Rutina de Interrupción (ISR) para K3 (Canal 0 de PINT)
 * @details Se ejecuta de forma asíncrona e inmediata al presionar K3.
 *          Es ultra breve: levanta un flag y limpia el periférico.
 */
void PIN_INT0_IRQHandler(void)
{
    uint32_t flag_fall = PINT_PinInterruptGetFallFlag(PINT, kPINT_PinInt0);
    uint32_t flag_rise = PINT_PinInterruptGetRiseFlag(PINT, kPINT_PinInt0);

    if (flag_fall) // Detecta flanco descendente de HIGH a LOW
    {
        PINT_PinInterruptClrFallFlag(PINT, kPINT_PinInt0);
        flag_btn = BTN_PRESSED;
    }
    if (flag_rise) // Detecta flanco ascendente de LOW a HIGH
    {
        PINT_PinInterruptClrRiseFlag(PINT, kPINT_PinInt0);
        flag_btn = BTN_RELEASED;
    }

    __DSB();
}
