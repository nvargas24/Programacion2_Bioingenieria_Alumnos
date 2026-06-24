#include <stdint.h>

#define VALOR_MAX_ADC_12BIT    4095
#define FACTOR_CONVERSION_MGDL 0.05f 

/*--- CAPA DE REGISTROS ---*/
#define ADC1_BASE_ADDRESS 0x3FF48800
#define ESP32_ADC1 ((ADC_ESP32_RegisterMap *) ADC1_BASE_ADDRESS)

typedef struct {
    volatile uint32_t CTRL;  // Registro de control del ADC interno
    volatile uint32_t DATA;  // Registro donde cae el resultado de 12 bits
} ADC_ESP32_RegisterMap;

/*--- CAPA HAL ---*/
void HAL_ADC_Init(void) {
    ESP32_ADC1->CTRL |= (1 << 0); // Habilita el módulo ADC en el ESP32
}

uint16_t HAL_ADC_Read_Raw(void) {
    ESP32_ADC1->CTRL |= (1 << 1); // Inicia conversión por hardware
    while ((ESP32_ADC1->CTRL & (1 << 2)) == 0); // Espera que termine (polling flag)
    return (uint16_t)(ESP32_ADC1->DATA & 0x0FFF); // Enmascara el bus a 12 bits
}

/*--- CAPA DE DRIVERS ---*/
uint16_t Driver_Glucometer_GetAdcReading(void) {
    // El driver sabe en qué canal físico específico está soldada la tira reactiva
    return HAL_ADC_Read_Raw();
}

/*--- CAPA DE SERVICIO ---*/
float Servicio_Calcular_Nivel_Glucosa(uint16_t adc_raw_value) {
    // Conversion a mg/dL
    float voltaje = ((float)adc_raw_value / VALOR_MAX_ADC_12BIT) * 3.3f;
    return (voltaje * FACTOR_CONVERSION_MGDL); 
}

/*--- CAPA DE APLICACIÓN ---*/
void Aplicacion_Enviar_Datos_Bluetooth(float resultado) {
    // Logica para enviar datos
}

int main(void) {
    HAL_ADC_Init(); // Inicializacion
    
    uint16_t lectura_cruda;
    float resultado_glucosa;

    while (1) {
        // Adquision de datos del sensor
        lectura_cruda = Driver_Glucometer_GetAdcReading();
        
        // Conversión 
        resultado_glucosa = Servicio_Calcular_Nivel_Glucosa(lectura_cruda);
        
        // Envío de mediciones al usuario
        Aplicacion_Enviar_Datos_Bluetooth(resultado_glucosa);
    }
  
    return 0;
}
