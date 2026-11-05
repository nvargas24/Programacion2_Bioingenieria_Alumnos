/**
 * @file main.c
 * @brief Control del LED RGB mediante FSM de Moore y comandos UART.
 * @details R, G, B y 0 seleccionan directamente el estado del LED RGB.
 */

#include "app_config.h"
#include "driver_led.h"
#include "fsl_usart.h"
#include "hardware_init.h"

#include <stdbool.h>
#include <stdint.h>

static volatile uint8_t g_receivedChar;
static volatile bool g_charReceived;

int main(void)
{
    estado_fsm_t estado_actual = ST_APAGADO;
    uint8_t caracter_recibido = '\0';

    BSP_Hardware_Init();

    while (1)
    {
        switch (estado_actual)
        {
            case ST_APAGADO:
                Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
                Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_OFF);
                Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_OFF);

                if (g_charReceived)
                {
                    caracter_recibido = g_receivedChar;
                    g_charReceived = false;

                    if (caracter_recibido == 'R')
                    {
                        estado_actual = ST_ROJO;
                    }
                    else if (caracter_recibido == 'G')
                    {
                        estado_actual = ST_VERDE;
                    }
                    else if (caracter_recibido == 'B')
                    {
                        estado_actual = ST_AZUL;
                    }
                }
                break;

            case ST_ROJO:
                Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_ON);
                Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_OFF);
                Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_OFF);

                if (g_charReceived)
                {
                    caracter_recibido = g_receivedChar;
                    g_charReceived = false;

                    if (caracter_recibido == 'R')
                    {
                        estado_actual = ST_ROJO;
                    }
                    else if (caracter_recibido == 'G')
                    {
                        estado_actual = ST_VERDE;
                    }
                    else if (caracter_recibido == 'B')
                    {
                        estado_actual = ST_AZUL;
                    }
                    else if (caracter_recibido == '0')
                    {
                        estado_actual = ST_APAGADO;
                    }
                }
                break;

            case ST_VERDE:
                Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
                Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_ON);
                Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_OFF);

                if (g_charReceived)
                {
                    caracter_recibido = g_receivedChar;
                    g_charReceived = false;

                    if (caracter_recibido == 'R')
                    {
                        estado_actual = ST_ROJO;
                    }
                    else if (caracter_recibido == 'G')
                    {
                        estado_actual = ST_VERDE;
                    }
                    else if (caracter_recibido == 'B')
                    {
                        estado_actual = ST_AZUL;
                    }
                    else if (caracter_recibido == '0')
                    {
                        estado_actual = ST_APAGADO;
                    }
                }
                break;

            case ST_AZUL:
                Driver_LED_Set(LED_RED_PORT, LED_RED_PIN, LED_OFF);
                Driver_LED_Set(LED_GREEN_PORT, LED_GREEN_PIN, LED_OFF);
                Driver_LED_Set(LED_BLUE_PORT, LED_BLUE_PIN, LED_ON);

                if (g_charReceived)
                {
                    caracter_recibido = g_receivedChar;
                    g_charReceived = false;

                    if (caracter_recibido == 'R')
                    {
                        estado_actual = ST_ROJO;
                    }
                    else if (caracter_recibido == 'G')
                    {
                        estado_actual = ST_VERDE;
                    }
                    else if (caracter_recibido == 'B')
                    {
                        estado_actual = ST_AZUL;
                    }
                    else if (caracter_recibido == '0')
                    {
                        estado_actual = ST_APAGADO;
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
