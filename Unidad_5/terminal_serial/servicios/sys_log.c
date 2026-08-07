#include "sys_log.h"
#include "driver_usart.h"
#include <stddef.h>
#include <string.h>

static const hal_usart_config_t gsk_cosole_hardware = {
    .usart_id = HAL_USART_0,
    .baudrate = HAL_BAUD_9600
};

void sysLog_Init(){
    Driver_USART_Init(&gsk_cosole_hardware);
}

void printLPC(const char* str){
    if(str == NULL) return;

    Driver_USART_WriteString(&gsk_cosole_hardware, str);
}

bool readLPC(char* buffer, unsigned int buffer_size)
{
    // Llama al driver bloqueante; se quedará aquí hasta completar el string con Enter
    return Driver_USART_ReadString(&gsk_cosole_hardware, buffer, buffer_size);
}

bool readSingleCharLPC(char* out_char)
{
    if (out_char == NULL)
    {
        return false;
    }

    // Llama al driver bloqueante; esperará activamente la pulsación de una única tecla
    return Driver_USART_ReadChar(&gsk_cosole_hardware, out_char);
}
