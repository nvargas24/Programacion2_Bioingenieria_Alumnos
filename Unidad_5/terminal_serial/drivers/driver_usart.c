#include "driver_usart.h"
#include "hal_uart.h"
#include <stddef.h>


void Driver_USART_Init(const hal_usart_config_t* config_uart){
    if (config_uart==NULL) return;
    HAL_UART_Init(config_uart->usart_id, config_uart->baudrate);
}

void Driver_USART_WriteString(const hal_usart_config_t* config_uart, const char* str){
    if(config_uart==NULL || str == NULL) return;

    // Se lee string y "descomprime" en byte 
    while(*str !='\0'){
        HAL_UART_WriteByte(config_uart->usart_id, (uint8_t)(*str));
        str++;
    }
}

bool Driver_USART_ReadChar(const hal_usart_config_t* config_uart, char* out_char){
    if(config_uart==NULL || out_char == NULL) return false;
    
    return HAL_UART_ReadByte(config_uart->usart_id, (uint8_t*)out_char);
}
