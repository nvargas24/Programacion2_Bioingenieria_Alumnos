#ifndef DRIVER_TERMINAL_H_
#define DRIVER_TERMINAL_H_

#include "hal_defs.h"

void Driver_USART_Init(const hal_usart_config_t* config_uart);
void Driver_USART_WriteString(const hal_usart_config_t* config_uart, const char* str);
bool Driver_USART_ReadChar(const hal_usart_config_t* config_uart, char* out_char);
bool Driver_USART_ReadString(const hal_usart_config_t* config_uart, char* buffer, unsigned int buffer_size);

#endif /* DRIVER_TERMINAL_H_ */
