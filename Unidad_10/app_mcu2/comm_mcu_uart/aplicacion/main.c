/**
 * @file main.c
 * @brief Control del LED RGB mediante FSM de Moore y comandos UART.
 * @details R, G, B y 0 seleccionan un estado. Se confirma por UART el estado
 *          despues de aplicar sus salidas al hardware.
 */

#include "app_config.h"
#include "driver_led.h"
#include "fsl_usart.h"
#include "hardware_init.h"

#include <stdbool.h>
#include <stdint.h>

static volatile uint8_t g_receivedChar;
static volatile bool g_charReceived;

static void uart_write_char(uint8_t character)
{
    USART_WriteBlocking(USART0, &character, 1U);
}

int main(void)
{
    estado_fsm_t estado_actual = ST_APAGADO;
    uint8_t caracter_recibido = '\0';
    bool confirmacion_pendiente = false;
    uint8_t caracter_confirmacion = '0';

    BSP_Hardware_Init();

    while (1)
    {
        switch (estado_actual)
        {
            case ST_APAGADO:
                Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
                Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_OFF);
                Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_OFF);

                if (confirmacion_pendiente)
                {
                    uart_write_char(caracter_confirmacion);
                    confirmacion_pendiente = false;
                }

                if (g_charReceived)
                {
                    caracter_recibido = g_receivedChar;
                    g_charReceived = false;

                    if (caracter_recibido == 'R')
                    {
                        estado_actual = ST_ROJO;
                        caracter_confirmacion = '1';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == 'G')
                    {
                        estado_actual = ST_VERDE;
                        caracter_confirmacion = '2';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == 'B')
                    {
                        estado_actual = ST_AZUL;
                        caracter_confirmacion = '3';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == '0')
                    {
                        caracter_confirmacion = '0';
                        confirmacion_pendiente = true;
                    }
                }
                break;

            case ST_ROJO:
                Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_ON);
                Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_OFF);
                Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_OFF);

                if (confirmacion_pendiente)
                {
                    uart_write_char(caracter_confirmacion);
                    confirmacion_pendiente = false;
                }

                if (g_charReceived)
                {
                    caracter_recibido = g_receivedChar;
                    g_charReceived = false;

                    if (caracter_recibido == 'R')
                    {
                        caracter_confirmacion = '1';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == 'G')
                    {
                        estado_actual = ST_VERDE;
                        caracter_confirmacion = '2';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == 'B')
                    {
                        estado_actual = ST_AZUL;
                        caracter_confirmacion = '3';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == '0')
                    {
                        estado_actual = ST_APAGADO;
                        caracter_confirmacion = '0';
                        confirmacion_pendiente = true;
                    }
                }
                break;

            case ST_VERDE:
                Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
                Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_ON);
                Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_OFF);

                if (confirmacion_pendiente)
                {
                    uart_write_char(caracter_confirmacion);
                    confirmacion_pendiente = false;
                }

                if (g_charReceived)
                {
                    caracter_recibido = g_receivedChar;
                    g_charReceived = false;

                    if (caracter_recibido == 'R')
                    {
                        estado_actual = ST_ROJO;
                        caracter_confirmacion = '1';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == 'G')
                    {
                        caracter_confirmacion = '2';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == 'B')
                    {
                        estado_actual = ST_AZUL;
                        caracter_confirmacion = '3';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == '0')
                    {
                        estado_actual = ST_APAGADO;
                        caracter_confirmacion = '0';
                        confirmacion_pendiente = true;
                    }
                }
                break;

            case ST_AZUL:
                Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
                Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_OFF);
                Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_ON);

                if (confirmacion_pendiente)
                {
                    uart_write_char(caracter_confirmacion);
                    confirmacion_pendiente = false;
                }

                if (g_charReceived)
                {
                    caracter_recibido = g_receivedChar;
                    g_charReceived = false;

                    if (caracter_recibido == 'R')
                    {
                        estado_actual = ST_ROJO;
                        caracter_confirmacion = '1';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == 'G')
                    {
                        estado_actual = ST_VERDE;
                        caracter_confirmacion = '2';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == 'B')
                    {
                        caracter_confirmacion = '3';
                        confirmacion_pendiente = true;
                    }
                    else if (caracter_recibido == '0')
                    {
                        estado_actual = ST_APAGADO;
                        caracter_confirmacion = '0';
                        confirmacion_pendiente = true;
                    }
                }
                break;
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
