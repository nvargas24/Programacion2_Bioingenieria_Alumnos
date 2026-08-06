#ifndef HAL_UART_H_
#define HAL_UART_H_

#include "hal_defs.h"

void HAL_UART_Init(hal_usart_id_t uart_id, hal_usart_baud_t baudrate);
void HAL_UART_WriteByte(hal_usart_id_t uart_id, uint8_t data);
bool HAL_UART_ReadByte(hal_usart_id_t uart_id, uint8_t* out_data);

#endif