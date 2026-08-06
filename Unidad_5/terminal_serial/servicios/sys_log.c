#include "sys_log.h"
#include "driver_usart.h"
#include <stddef.h>

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
