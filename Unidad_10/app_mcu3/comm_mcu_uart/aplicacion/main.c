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

                break;

            case ST_ROJO:

                break;

            case ST_VERDE:

                break;

            case ST_AZUL:

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
