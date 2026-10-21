#include "hardware_init.h"
#include "sys_time.h"
#include "app_config.h"

int main(void)
{
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
