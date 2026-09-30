#include "hardware_init.h"
#include "sys_time.h"
#include "app_config.h"

int main(void)
{
    uint8_t value = 0U;
    uint32_t last_refresh = 0U;
    uint32_t last_count = 0U;

    BSP_Hardware_Init();
    Driver_Display_SetValue(value);

    while (1) {
        uint32_t now = sysTime_getTicks();

        if ((now - last_refresh) >= DISPLAY_REFRESH_PERIOD_MS) {
            last_refresh = now;
            Driver_Display_Refresh();
        }

        if ((now - last_count) >= APP_COUNTER_PERIOD_MS) {
            last_count = now;
            value++;
            if (value >= ((DISPLAY_DIGIT_COUNT == 2U) ? 100U : 10U)) {
                value = 0U;
            }
            Driver_Display_SetValue(value);
        }
    }
}
