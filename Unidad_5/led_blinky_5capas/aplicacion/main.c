/**
 * @file main.c
 * @brief Ejemplo de parpadeo del LED rojo de la LPC845BRK.
 * @details Inicializa la BSP y el driver, enciende y apaga el LED en bucle y
 *          espera BLINK_PERIOD_MS en cada fase mediante un retardo bloqueante.
 * @note Uso: importar en MCUXpresso, compilar para LPC845BRK y debuggear en la placa.
 * @warning Durante sysTime_delay_ms la CPU queda bloqueante y no procesa otras tareas.
 * @author Ing. Vargas Nahuel (nvargas@frh.utn.edu.ar)
 * @copyright 2026 Bioingenieria - UTN-FRH. Todos los derechos reservados.
 * @note Licencia: este ejemplo no declara una licencia independiente. Los archivos de NXP/CMSIS
 *       conservan sus avisos y licencias originales; consultarlos antes de redistribuir.
 */

#include "hardware_init.h"
#include "sys_time.h"
#include "driver_led.h"
#include "app_config.h"

int main(){
	/* Setup - Configuracion HW**/
    BSP_Hardware_Init(); // Inicializa pines, clocks y SysTick de la placa

    Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);

    /* Bucle */
    while(1){
        Driver_LED_Set(LED1_PORT, LED1_PIN, LED_ON);
        sysTime_delay_ms(BLINK_PERIOD_MS); // Se recurre a servicio de delay bloqueante
        Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
        sysTime_delay_ms(BLINK_PERIOD_MS);
    }
}
