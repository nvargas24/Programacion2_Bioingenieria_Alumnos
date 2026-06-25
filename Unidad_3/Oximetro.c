#include <stdint.h>

typedef struct {
    uint16_t red;
    uint16_t ir;
} PulseOx_Data_t;

/* --- CAPA DE REGISTROS ---*/
#define PERIPHERAL_BASE_ADDR   0x40012400
#define SENSOR_DATA_REG_OFFSET 0x0C
#define SENSOR_HARDWARE ((Medical_Sensor_Ports*)(PERIPHERAL_BASE_ADDR + SENSOR_DATA_REG_OFFSET))

typedef struct {
    volatile uint16_t RED_CHANNEL;  // Registro físico canal Rojo
    volatile uint16_t IR_CHANNEL;   // Registro físico canal Infrarrojo
} Medical_Sensor_Ports;

/* --- CAPA HAL --- */
uint16_t HAL_Read_Optical_Buffer(uint8_t channel) {
    if (channel == 0) {
        return SENSOR_HARDWARE->RED_CHANNEL; // Acceso directo a registro
    } else {
        return SENSOR_HARDWARE->IR_CHANNEL;
    }
}

/* --- CAPA DE DRIVERS --- */ 
PulseOx_Data_t Driver_PulseOx_GetSamples(void) {
    PulseOx_Data_t samples;
    // Combinacion de ambas lecturas fragmentadas
    samples.red = HAL_Read_Optical_Buffer(0);
    samples.ir  = HAL_Read_Optical_Buffer(1);

    return samples;
}

/* --- CAPA DE SERVICIO --- */
float Servicio_Calcular_SpO2(PulseOx_Data_t data) {
    float r_ratio, spo2;
    if (data.ir == 0) return 0.0f;
    
    // Algoritmopara aproximar la saturación de oxígeno
    r_ratio = ((float)data.red) / ((float)data.ir);
    spo2 = 110.0f - (25.0f * r_ratio); // Ecuación de calibración estándar
    
    if (spo2 > 100.0f) spo2 = 100.0f;
    
    return spo2;
}

/* --- CAPA DE APLICACIÓN ---*/
void Disparar_Alarma_Prioridad_Alta(void) {
    // Activar buzzer
}

int main(void) {
    // Inicialización
    PulseOx_Data_t medicion_actual;
    float saturacion_oxigeno;

    while (1) {
        // Se adquiere los datos estructurados
        medicion_actual = Driver_PulseOx_GetSamples();
        
        // Se procesa los datos
        saturacion_oxigeno = Servicio_Calcular_SpO2(medicion_actual);
        
        // Criterio de funcionamiento del sistema
        if (saturacion_oxigeno < 90.0f) {
            Disparar_Alarma_Prioridad_Alta();
        }
    }
    return 0;
}
