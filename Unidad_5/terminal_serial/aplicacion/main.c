#include "hardware_init.h"
#include "sys_time.h"
#include "sys_log.h"
#include "driver_usart.h"
#include "app_config.h"

int main(void)
{
    char received_buffer[64];

    /* Inicializa hardware y servicios de bajo nivel */
    BSP_Hardware_Init();
    sysLog_Init();

    printLPC("--- Terminal USART LPC Listo ---\r\n");
    printLPC("Escriba un mensaje y presione Enter:\r\n");

    while (1)
    {
        if (readLPC(received_buffer, sizeof(received_buffer)))
        {
            printLPC("Recibido: ");
            printLPC(received_buffer);
            printLPC("\r\n");
        }
        printLPC("Devuelta en bucle\n");
        sysTime_delay_ms(1000);
    }
}
