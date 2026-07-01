#include <stdint.h>

/*--- CAPA DE REGISTROS ---*/
#define ADC_NXP_BASE  0x40034000
#define NXP_HARDWARE_ADC ((ADC_NXP_Registers*)ADC_NXP_BASE)

typedef struct {
    volatile uint32_t CR;     // Registro de control del ADC
    volatile uint32_t GDR;    // Registro de datos globales (32-bit)
    volatile uint32_t STAT;   // Registro de estado de la conversión
} ADC_NXP_Registers;

/*--- CAPA HAL ---*/
void HAL_ADC_Start_Conversion(void) {
    NXP_HARDWARE_ADC->CR |= (1 << 24);
}

uint32_t HAL_ADC_Get_Result(void) {
    while (!(NXP_HARDWARE_ADC->STAT & (1 << 0))); // Espera el fin del ciclo
    return (NXP_HARDWARE_ADC->GDR & 0xFFFFFFFF);  // Retorna el registro de 32 bits
}

/*--- CAPA DE DRIVERS ---*/
uint16_t Driver_ECG_Read_Lead_I(void) {
    HAL_ADC_Start_Conversion();
    uint32_t raw_data = HAL_ADC_Get_Result();
 
    return (uint16_t)((raw_data >> 16) & 0x0FFF); 
}

/*--- CAPA DE SERVICIO ---*/
float Servicio_Filtro_Notch_50Hz(uint16_t raw_ecg) {
    // filtro de ruido de la red eléctrica
    float valor_anterior = 0.0f;
    float ecg_filtrado = (float)raw_ecg * 0.95f + valor_anterior * 0.05f; 

    valor_anterior = ecg_filtrado;
    
    return ecg_filtrado;
}

/*--- CAPA DE APLICACIÓN ---*/
void Aplicacion_Detectar_Taquicardia(float ecg_mv) {
    // si la señal supera un umbral
    if (ecg_mv > 2.5f) { 
        // reporte de frecuencia cardíaca elevada
    }
}

int main(void) {
    uint16_t muestra_cruda;
    float señal_limpia;

    while (1) {
        muestra_cruda = Driver_ECG_Read_Lead_I();
        señal_limpia   = Servicio_Filtro_Notch_50Hz(muestra_cruda);
        Aplicacion_Detectar_Taquicardia(señal_limpia);
    }    
    return 0;
}
