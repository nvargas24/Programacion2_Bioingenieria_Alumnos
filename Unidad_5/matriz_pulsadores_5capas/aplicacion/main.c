#include "hardware_init.h"
#include "app_config.h"
#include "driver_led.h"
#include "driver_matriz.h"
#include "sys_time.h"

#include <stdint.h>

int main(void)
{
    uint32_t intervalo_ms = 0;
    uint8_t led_port = LED1_PORT;
    uint8_t led_pin = LED1_PIN;

    BSP_Hardware_Init();
    Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
    Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);

    while (1) {
        char tecla = Driver_Matriz_Scan();

        if(tecla == '0' || tecla == '1' || tecla == '2'|| tecla == '3'|| tecla == '4' \
        ||tecla == '5' || tecla == '6' || tecla == '7'|| tecla == '8'|| tecla == '9')
        {
            led_port = LED1_PORT;
            led_pin = LED1_PIN;
        }
        else if(tecla == 'A' || tecla == 'B' || tecla == 'C' \
        ||tecla == 'D' || tecla == '*' || tecla == '#')
        {
            led_port = LED2_PORT;
            led_pin = LED2_PIN;
        }
        switch (tecla) {
        case '0':
            intervalo_ms = 1000;
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);
            break;

        case '1':
            intervalo_ms = 900;
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);
            break;

        case '2':
            intervalo_ms = 800;
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);
            break;

        case '3':
            intervalo_ms = 700;
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);
            break;

        case '4':
            intervalo_ms = 600;
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);
            break;

        case '5':
            intervalo_ms = 500;
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);
            break;

        case '6':
            intervalo_ms = 400;
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);
            break;

        case '7':
            intervalo_ms = 300;
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);
            break;

        case '8':
            intervalo_ms = 200;
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);
            break;

        case '9':
            intervalo_ms = 100;
            Driver_LED_Set(LED2_PORT, LED2_PIN, LED_OFF);
            break;

        case 'A':
            intervalo_ms = 600;
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
            break;

        case 'B':
            intervalo_ms = 500;
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
            break;

        case 'C':
            intervalo_ms = 400;
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
            break;

        case 'D':
            intervalo_ms = 300;
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
            break;

        case '#':
            intervalo_ms = 200;
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
            break;

        case '*':
            intervalo_ms = 100;
            Driver_LED_Set(LED1_PORT, LED1_PIN, LED_OFF);
            break;

        default:
            break;
        }

        if (intervalo_ms != 0) {
            Driver_LED_Toggle(led_port, led_pin);
            sysTime_delay_ms(intervalo_ms);
        }
    }
}
