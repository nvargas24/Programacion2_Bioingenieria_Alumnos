/**
 * @file main.c
 * @brief Ejemplo de lectura de una matriz de teclas y control del LED azul.
 * @details Para LPC845BRK y arquitectura de cinco capas. El LED cambia de estado
 *          una vez por cada pulsacion estable detectada en la matriz.
 * @note Uso: importar en MCUXpresso, compilar para LPC845BRK y debuggear en la placa.
 * @warning La matriz sin diodos se interpreta como una tecla simultanea.
 * @author Ing. Vargas Nahuel (nvargas@frh.utn.edu.ar)
 * @copyright 2026 Bioingenieria - UTN-FRH. Todos los derechos reservados.
 * @note Licencia: este ejemplo no declara una licencia independiente. Los archivos de NXP/CMSIS
 *       conservan sus avisos y licencias originales; consultarlos antes de redistribuir.
 */

#include "hardware_init.h"
#include "app_config.h"
#include "../drivers/driver_led.h"
#include "../drivers/driver_matriz.h"
#include "../servicios/sys_time.h"

volatile char g_ultima_tecla = MATRIZ_TECLA_NINGUNA;

int main(void)
{
    char tecla_candidata = MATRIZ_TECLA_NINGUNA;
    char tecla_estable = MATRIZ_TECLA_NINGUNA;
    uint32_t inicio_candidata = 0U;

    BSP_Hardware_Init();

    Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);

    while (1) {
        uint32_t ahora = sysTime_getTicks();
        char tecla_leida = Driver_Matriz_Scan();

        if (tecla_leida != tecla_candidata) {
            tecla_candidata = tecla_leida;
            inicio_candidata = ahora;
        }

        if ((tecla_candidata != tecla_estable) &&
            ((ahora - inicio_candidata) >= MATRIX_DEBOUNCE_MS)) {
            tecla_estable = tecla_candidata;
            if (tecla_estable != MATRIZ_TECLA_NINGUNA) {
                g_ultima_tecla = tecla_estable;
                Driver_LED_Toggle(LED1_PORT, LED1_PIN);
            }
        }
    }
}
