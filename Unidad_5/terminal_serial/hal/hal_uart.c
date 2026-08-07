#include "hal_uart.h"
#include "fsl_clock.h"
#include "fsl_reset.h"
#include "fsl_usart.h"

static USART_Type* const gk_uart_base[] = {USART0, USART1};

void HAL_UART_Init(hal_usart_id_t uart_id, hal_usart_baud_t baudrate){
    if(uart_id >= 2) return; // verifica si existe ID

    usart_config_t config;

    // Configuracion basica de USART - baudios y Tx  
    CLOCK_Select(kUART0_Clk_From_MainClk);
    RESET_PeripheralReset(kUART0_RST_N_SHIFT_RSTn);

    USART_GetDefaultConfig(&config);
    config.baudRate_Bps = baudrate;
    config.enableTx = true;
    config.enableRx = true;

    USART_Init(gk_uart_base[uart_id], &config, CLOCK_GetFreq(kCLOCK_MainClk));
}

void HAL_UART_WriteByte(hal_usart_id_t uart_id, uint8_t data){
    if(uart_id >= 2) return; // verifica si existe ID

    USART_Type *uart_base = gk_uart_base[uart_id];

    while ((USART_GetStatusFlags(uart_base) & kUSART_TxReady) == 0U)
    {
    }

    USART_WriteByte(uart_base, data);
}

bool HAL_UART_ReadByte(hal_usart_id_t uart_id, uint8_t* out_data){
    if(uart_id >= 2) return false; // verifica si existe ID

    // De haber dato en buffer se almande y confirma
    if(USART_GetStatusFlags(gk_uart_base[uart_id]) & kUSART_RxReady){
        *out_data = USART_ReadByte(gk_uart_base[uart_id]);
        return true;
    }

    return false;
}