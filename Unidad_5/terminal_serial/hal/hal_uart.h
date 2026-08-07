#ifndef HAL_UART_H_
#define HAL_UART_H_

#include "hal_defs.h"
#include <stddef.h>

void HAL_UART_Init(hal_usart_id_t uart_id, hal_usart_baud_t baudrate);
void HAL_UART_WriteBuffer(hal_usart_id_t uart_id, const uint8_t *data, size_t length);
bool HAL_UART_ReadBuffer(hal_usart_id_t uart_id, uint8_t *buffer, size_t length);

#endif /* HAL_UART_H_ */
