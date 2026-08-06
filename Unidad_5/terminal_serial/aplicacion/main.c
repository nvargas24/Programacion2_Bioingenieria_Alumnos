#include "hardware_init.h"
#include "sys_time.h"
#include "sys_log.h"
#include "app_config.h"

int main(){
    /* Inicializa hardware */
    BSP_Hardware_Init(); 

    sysLog_Init();

    printLPC("---------------------------------------");
    printLPC("Ejemplo de utilizar print personalizado----");
    /* Bucle */
    while(1){
        printLPC("Avanza bucle\r\n");
        sysTime_delay_ms(25); // Se recurre a servicio de delay bloqueante
    }
}