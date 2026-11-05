/**
 * @file main.c
 * @brief Ejemplo didactico de recepcion UART por interrupcion.
 * @details Cada tecla enviada desde la terminal ejecuta una accion y genera
 *          una respuesta. La ISR recibe el byte; el main lo procesa.
 * @note Terminal: 115200 baudios, 8N1, sin control de flujo y eco local desactivado.
 *       Enviar una tecla y esperar la respuesta antes de enviar la siguiente.
 */

#include "board.h"
#include "driver_led.h"
#include "fsl_usart.h"
#include "hardware_init.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>

static volatile uint8_t g_receivedChar;
static volatile bool g_charReceived;
static bool g_blueLedOn;

static void uart_write(const char *text)
{
    USART_WriteBlocking(USART0, (const uint8_t *)text, strlen(text));
}

static void process_command(uint8_t command)
{
    switch (command)
    {
        case '?':
            uart_write(
                "\r\nComandos:\r\n"
                "  1: encender LED azul\r\n"
                "  0: apagar LED azul\r\n"
                "  t: invertir LED azul\r\n"
                "  s: consultar estado del LED\r\n"
                "  p: probar UART (responde pong)\r\n");
            break;

        case '1':
            Driver_LED_Set(BOARD_LED_BLUE_GPIO_PORT, BOARD_LED_BLUE_GPIO_PIN, LED_ON);
            g_blueLedOn = true;
            uart_write("\r\nLED azul encendido.\r\n");
            break;

        case '0':
            Driver_LED_Set(BOARD_LED_BLUE_GPIO_PORT, BOARD_LED_BLUE_GPIO_PIN, LED_OFF);
            g_blueLedOn = false;
            uart_write("\r\nLED azul apagado.\r\n");
            break;

        case 't':
            Driver_LED_Toggle(BOARD_LED_BLUE_GPIO_PORT, BOARD_LED_BLUE_GPIO_PIN);
            g_blueLedOn = !g_blueLedOn;
            uart_write("\r\nLED azul invertido.\r\n");
            break;

        case 's':
            uart_write(g_blueLedOn ? "\r\nLED azul: encendido.\r\n" : "\r\nLED azul: apagado.\r\n");
            break;

        case 'p':
            uart_write("\r\npong\r\n");
            break;

        default:
            uart_write("\r\nTecla no reconocida. Pulsa ? para ayuda.\r\n");
            break;
    }

    uart_write("> ");
}

int main(void)
{
    const gpio_pin_config_t ledConfig = {kGPIO_DigitalOutput, 1U};

    BSP_Hardware_Init();
    GPIO_PinInit(GPIO, BOARD_LED_BLUE_GPIO_PORT, BOARD_LED_BLUE_GPIO_PIN, &ledConfig);

    uart_write("\r\nConsola UART0 - LPC845BRK\r\nPulsa ? para ver los comandos.\r\n> ");

    while (1)
    {
        if (g_charReceived)
        {
            uint8_t command;

            /* Tomar el byte y limpiar la bandera sin que la ISR los modifique. */
            DisableIRQ(USART0_IRQn);
            command = g_receivedChar;
            g_charReceived = false;
            EnableIRQ(USART0_IRQn);

            /* El eco permite ver la tecla recibida aunque el eco local este apagado. */
            if ((command != '\r') && (command != '\n'))
            {
                USART_WriteBlocking(USART0, &command, 1U);
                process_command(command);
            }
        }
    }
}

void USART0_IRQHandler(void)
{
    if ((kUSART_RxReady & USART_GetStatusFlags(USART0)) != 0U)
    {
        g_receivedChar = USART_ReadByte(USART0);
        g_charReceived = true;
    }

    SDK_ISR_EXIT_BARRIER;
}
