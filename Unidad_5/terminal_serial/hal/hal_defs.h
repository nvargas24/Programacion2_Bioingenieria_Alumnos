/*
    Definiciones generales de estado
    Por ejemplo, como se interpreta estado HIGH/LOW u entrada/salida.
*/
#ifndef HAL_DEFS_H_
#define HAL_DEFS_H_

#include <stdint.h>
#include <stdbool.h>

#define TIMEOUT_READ 20U

typedef enum{
    HAL_USART_0,
    HAL_USART_1,
    HAL_USART_2
}hal_usart_id_t;

typedef enum{
    HAL_BAUD_9600 = 9600,
    HAL_BAUD_19200 = 19200,
    HAL_BAUD_38400 = 38400,
    HAL_BAUD_57600 = 57600,
    HAL_BAUD_115200 = 115200,
    HAL_BAUD_230400 = 230400
}hal_usart_baud_t;

typedef struct{
    hal_usart_id_t usart_id;
    hal_usart_baud_t baudrate;
}hal_usart_config_t;


#endif 