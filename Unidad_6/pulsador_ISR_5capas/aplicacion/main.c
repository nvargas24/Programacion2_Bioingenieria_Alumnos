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
#include "fsl_gpio.h"
#include "fsl_pint.h"

#include <stdint.h>

volatile uint8_t g_btn_pressed_flag = 0;

int main() {
    /* Setup - Configuracion HW*/
    BSP_Hardware_Init(); // Inicializa pines, clocks, SysTick, PINT y NVIC

    Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
    
    /* Loop */
    while(1) {
        /* Evaluamos directamente el estado reflejado por la interrupción */
        if (g_btn_pressed_flag == 1U) {
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_ON);  // Enciende si está presionado
        }
        else {
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF); // Apaga si se soltó
        }
    }
}

/**
 * @brief Rutina de Servicio de Interrupción (ISR) para K3 (Canal 0 de PINT)
 * @details Se ejecuta de forma asíncrona e inmediata al presionar K3.
 *          Es ultra breve: levanta un flag y limpia el periférico.
 */
void PIN_INT0_IRQHandler(void)
{
    uint32_t fall_flag = PINT_PinInterruptGetFallFlag(PINT, kPINT_PinInt0);
    uint32_t rise_flag = PINT_PinInterruptGetRiseFlag(PINT, kPINT_PinInt0);

    if (fall_flag != 0U)
    {
        PINT_PinInterruptClrFallFlag(PINT, kPINT_PinInt0);
    }
    if (rise_flag != 0U)
    {
        PINT_PinInterruptClrRiseFlag(PINT, kPINT_PinInt0);
    }
    if ((fall_flag != 0U) || (rise_flag != 0U))
    {
        g_btn_pressed_flag = (GPIO_PinRead(GPIO, PULSADOR1_PORT, PULSADOR1_PIN) == 0U) ? 1U : 0U;
    }

    __DSB();
}
