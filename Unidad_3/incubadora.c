#include <stdint.h>

#define PIN_CALEFACTOR 15

/*--- CAPA DE REGISTROS ---*/
#define GPIO_BASE_ADDR 0x40044000
#define LPC845_GPIO ((GPIO_LPC845_Type *) GPIO_BASE_ADDR)

typedef struct {
    volatile uint32_t DIR;  // Registro de dirección (Entrada/Salida)
    volatile uint32_t PIN;  // Registro de lectura/escritura de datos
} GPIO_LPC845_Type;

/*--- CAPA HAL ---*/
void HAL_GPIO_SetPinAsOutput(uint8_t pin) {
    LPC845_GPIO->DIR |= (1 << pin); // Configura el bit de salida
}

void HAL_GPIO_WritePin(uint8_t pin, uint8_t state) {
    if (state) {
        LPC845_GPIO->PIN |= (1 << pin);  // Enciende
    } else {
        LPC845_GPIO->PIN &= ~(1 << pin); // Apaga
    }
}

/*--- CAPA DE DRIVERS  ---*/
void Driver_Calefactor_Init(void) {
    HAL_GPIO_SetPinAsOutput(PIN_CALEFACTOR);
}

void Driver_Calefactor_SetEstado(uint8_t encendido) {
    // Cambio de estado de GPIO
    HAL_GPIO_WritePin(PIN_CALEFACTOR, encendido);
}

/*--- CAPA DE SERVICIO ---*/
float Servicio_Obtener_Temperatura_Promedio(void) {
    // Lectura del bus de la termocupla de 16 bit y estabilizacion de señal
    return 36.8f; 
}

/*--- CAPA DE APLICACIÓN ---*/
int main(void) {
    // Inicialización del Driver
    Driver_Calefactor_Init();
    
    float temperatura_actual;

    while (1) {
        // Adquisición de datos
        temperatura_actual = Servicio_Obtener_Temperatura_Promedio();
        
        // Lógica deL sistema
        if (temperatura_actual < 36.5f) {
            Driver_Calefactor_SetEstado(1); // Enciende calefactor si hay hipotermia
        } else if (temperatura_actual > 37.2f) {
            Driver_Calefactor_SetEstado(0); // Apaga si la temperatura es la adecuada
        }
    }
    return 0;
}
