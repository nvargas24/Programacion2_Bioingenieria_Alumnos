#include "hardware_init.h"
#include "sys_time.h"
#include "app_config.h"

int main(void)
{
    /* Ejemplo completo para mostrar un valor fijo. Para probarlo, reemplazar
     * el codigo activo de main() por este ejemplo (sin los asteriscos).
     * Cambiar numero_fijo por un valor entre 0U y 9U con la configuracion
     * actual de un digito.
     *
     * int main(void)
     * {
     *     const uint8_t numero_fijo = 7U;
     *     uint32_t last_refresh = 0U;
     *
     *     BSP_Hardware_Init();
     *     Driver_Display_SetValue(numero_fijo);
     *
     *     while (1) {
     *         uint32_t now = sysTime_getTicks();
     *
     *         if ((now - last_refresh) >= DISPLAY_REFRESH_PERIOD_MS) {
     *             last_refresh = now;
     *             Driver_Display_Refresh();
     *         }
     *     }
     * }
     *
     * DISPLAY_DIGIT_COUNT = 1U muestra value % 10. Con dos digitos, el
     * driver muestra value % 100 (por ejemplo, 7 se ve como 07).
     * Segmentos encendidos por digito: 0: abcdef, 1: bc, 2: abdeg,
     * 3: abcdg, 4: bcfg, 5: acdfg, 6: acdefg, 7: abc, 8: abcdefg,
     * 9: abcdfg. No controla el punto decimal ni implementa letras.
     */
    uint8_t value = 0U;
    uint32_t last_count = 0U;

    BSP_Hardware_Init();
    BSP_Display_ShowNumber(value);

    while (1) {
        uint32_t now = sysTime_getTicks();

        if ((now - last_count) >= APP_COUNTER_PERIOD_MS) {
            last_count = now;
            value++;
            if (value >= ((DISPLAY_DIGIT_COUNT == 2U) ? 100U : 10U)) {
                value = 0U;
            }
            BSP_Display_ShowNumber(value);
        }
    }
}
