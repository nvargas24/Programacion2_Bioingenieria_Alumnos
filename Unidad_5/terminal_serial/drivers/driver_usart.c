#include "driver_usart.h"
#include "hal_uart.h"
#include <stddef.h>
#include <string.h>

void Driver_USART_Init(const hal_usart_config_t* config_uart){
    if (config_uart != NULL) {
        HAL_UART_Init(config_uart->usart_id, config_uart->baudrate);
    }
}

void Driver_USART_WriteString(const hal_usart_config_t* config_uart, const char* str){
    if (config_uart == NULL || str == NULL) return;

    // Calculamos la longitud de la cadena para enviarla en un solo bloque atómico
    size_t length = strlen(str);
    if (length > 0U) {
        HAL_UART_WriteBuffer(config_uart->usart_id, (const uint8_t*)str, length);
    }
}

bool Driver_USART_ReadChar(const hal_usart_config_t* config_uart, char* out_char){
    if (config_uart == NULL || out_char == NULL) return false;
    
    // Al ser HAL_UART_ReadBuffer bloqueante, se quedará aquí hasta recibir 1 byte real
    return HAL_UART_ReadBuffer(config_uart->usart_id, (uint8_t*)out_char, 1U);
}

bool Driver_USART_ReadString(const hal_usart_config_t* config_uart, char* buffer, unsigned int buffer_size){
    if (config_uart == NULL || buffer == NULL || buffer_size < 2U) return false;

    static char rx_accumulator[128U]; 
    static unsigned int index = 0U;
    char received_char = '\0';
    bool string_complete = false;

    volatile uint32_t driver_timeout = TIMEOUT_READ;

    while (driver_timeout > 0U) {
        
        // Llamamos a la HAL instantánea. Si lee un carácter, procesamos y reiniciamos el tiempo.
        if (Driver_USART_ReadChar(config_uart, &received_char)) {
            
            // Cada vez que llega un byte de la ráfaga, le damos más tiempo al timeout
            driver_timeout = TIMEOUT_READ; 

            // Si detecta un fin de línea (Enter de la terminal)
            if (received_char == '\r' || received_char == '\n') {
                if (index > 0U) { 
                    rx_accumulator[index] = '\0'; // Cierra la cadena interna
                    string_complete = true;
                    break; // Rompe el bucle de tiempo ya que el comando llegó completo
                }
                continue; // Ignora Enter suelto
            }

            // Acumula la letra de forma persistente en la RAM del driver
            if (index < (sizeof(rx_accumulator) - 1U)) {
                rx_accumulator[index++] = received_char;
            }
        } else {
            // Si la UART está vacía en este instante, decrementamos el contador de espera
            driver_timeout--;
        }
    }

    // Si encontramos el Enter completo antes de agotar el tiempo
    if (string_complete) {
        unsigned int copy_size = (index < buffer_size) ? index : (buffer_size - 1U);
        for (unsigned int i = 0U; i < copy_size; i++) {
            buffer[i] = rx_accumulator[i];
        }
        buffer[copy_size] = '\0'; // Terminador nulo para el main.c
        
        index = 0U;   // Limpieza del índice para el próximo mensaje
        return true;  // Éxito: El main entrará al condicional
    }

    return false; // Retorna false si el timeout expiró sin encontrar un Enter (UART vacía)
}
