#include "hardware_init.h"
#include "sys_time.h"
#include "sys_log.h"
#include "driver_usart.h"
#include "app_config.h"
#include <string.h>

int main(void)
{
    char received_buffer[64];

    /* Inicializa hardware y servicios de bajo nivel */
    BSP_Hardware_Init();
    sysLog_Init();

    sysTerminal_write("[LPC845] --- Terminal USART Listo ---\r\n");

    while(true)
    {
        if (sysTerminal_read(received_buffer, sizeof(received_buffer))){
            sysTerminal_write("[LPC845] Recibo: ");
            sysTerminal_write(received_buffer);
            sysTerminal_write("\r\n");
        }

        if (received_buffer[0] != '\0')
        {
            if (strcmp(received_buffer, "hola") == 0){
                sysTerminal_write("[LPC845] Enviaste: un saludo\r\n");
            }
            else if (strcmp(received_buffer, "chau") == 0){
                sysTerminal_write("[LPC845] Enviaste: una despedida\r\n");
            }    
            else {
                sysTerminal_write("[LPC845] No reconozco palabra\r\n");
            }
            
            received_buffer[0] = '\0';  // vacio buffer
        }

        //sysTime_delay_ms(1000); // es bloqueante - se puede llegar a perder info
        //sysTerminal_write("Devuelta en bucle\n");
    }
}
