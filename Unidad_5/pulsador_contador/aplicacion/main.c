#include "hardware_init.h"
#include "driver_led.h"
#include "driver_pulsador.h"
#include "app_config.h"
#include "sys_time.h"

int main() {
    app_state_t state = READ_BTN;
    app_state_t next_state = LED_OFF;
    hal_gpio_state_t button_prev = HAL_GPIO_HIGH;
    hal_gpio_state_t button_current = HAL_GPIO_HIGH;

    Driver_LED_Init(LED_RED_PORT, LED_RED_PIN);
    Driver_LED_Init(LED_GREEN_PORT, LED_GREEN_PIN);
    Driver_LED_Init(LED_BLUE_PORT, LED_BLUE_PIN);

    Driver_Pulsador_Init(PULSADOR_PORT, PULSADOR_PIN);

    while (1) {
        switch (state) {
            case READ_BTN:
                button_current = Driver_Pulsador_Read(PULSADOR_PORT, PULSADOR_PIN);

                if ((button_current == HAL_GPIO_LOW) && (button_prev == HAL_GPIO_HIGH)) {
                    sysTime_delay_ms(50);
                    state = next_state;
                }

                button_prev = button_current;
                break;
            case LED_OFF:
                Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
                Driver_LED_Off(LED_BLUE_PORT, LED_BLUE_PIN);
                Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
                next_state = LED_RED;
                state = READ_BTN;
                break;
            case LED_RED:
                Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
                Driver_LED_Off(LED_BLUE_PORT, LED_BLUE_PIN);
                Driver_LED_On(LED_RED_PORT, LED_RED_PIN);
                next_state = LED_GREEN;
                state = READ_BTN;
                break;

            case LED_GREEN:
                Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
                Driver_LED_Off(LED_BLUE_PORT, LED_BLUE_PIN);
                Driver_LED_On(LED_GREEN_PORT, LED_GREEN_PIN);
                next_state = LED_BLUE;
                state = READ_BTN;
                break;

            case LED_BLUE:
                Driver_LED_Off(LED_GREEN_PORT, LED_GREEN_PIN);
                Driver_LED_Off(LED_RED_PORT, LED_RED_PIN);
                Driver_LED_On(LED_BLUE_PORT, LED_BLUE_PIN);
                next_state = LED_OFF;
                state = READ_BTN;
                break;

            default:
                state = LED_OFF;
                break;
        }
    }
}
