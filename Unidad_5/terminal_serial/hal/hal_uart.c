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

void HAL_UART_WriteBuffer(hal_usart_id_t uart_id, const uint8_t *data, size_t length) {
    if (uart_id >= 2 || data == NULL || length == 0U) return;

    // Llama directamente a la funcion bloqueante del SDK de NXP
    USART_WriteBlocking(gk_uart_base[uart_id], data, length);
}

bool HAL_UART_ReadBuffer(hal_usart_id_t uart_id, uint8_t *buffer, size_t length) {
    if (uart_id >= 2 || buffer == NULL || length == 0U) return false;

    USART_Type *base = gk_uart_base[uart_id];
    uint32_t status = USART_GetStatusFlags(base);

    /* 1. GESTIÓN DE ERRORES DEL HARDWARE (LPC845)
     * Si venimos saliendo del delay de 1 segundo del main y el hardware está trabado,
     * extraemos el byte sobreviviente para destrabar el chip y lo devolvemos como éxito. */
    if (status & kUSART_HardwareOverrunFlag) {
        *buffer = USART_ReadByte(base);
        USART_ClearStatusFlags(base, kUSART_HardwareOverrunFlag);
        return true; 
    }

    /* 2. LECTURA ORDINARIA DE DATOS (Filtro del SDK)
     * Si el flag kUSART_RxReady (Bit 0) está activo, invocamos la función bloqueante
     * que será instantánea porque el dato ya está en el integrado. */
    if (status & kUSART_RxReady) {
        status_t sdk_status = USART_ReadBlocking(base, buffer, length);
        return (sdk_status == kStatus_Success);
    }

    return false; // Si la UART está vacía, sale inmediatamente (Cero bloqueo aquí)
}
