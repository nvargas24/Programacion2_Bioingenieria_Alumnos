#### Problema 1
Un glucómetro digital de uso doméstico fue diseñado inicialmente para leer datos por medio de un convertidor analógico-digital (ADC) básico de 8 bits y mostrar el resultado en una pantalla monocromática. 

Sin embargo, para cumplir con las nuevas normativas de salud pública, se requiere actualizar el dispositivo para que utilice un sensor electroquímico de alta precisión con un bus de salida de datos de 12 bits y, además, transmita las lecturas automáticamente al teléfono del paciente por Wi-Fi.

1. Determine cual de las siguientes placas de desarrollo es la adecuada para testear este nuevo periferico a su maximo rendimiento, justifique adecuadamente.  
    - Arduino UNO (ATMega328P AVR - 8bits)
    - ESP32 (Espressif - 32bits)
    - LPC845BRK (ARM Cortex-M0+ - 32bits)
2. Para el testeo del sensor, una de las modificaciones a realizar es el cálculo del nivel de glucosa, para esto se implemento la siguiente función:
    ```cpp
    #define VALOR_MAX_ADC_12BIT  4095
    #define FACTOR_CONVERSION_MGDL 0.05 // Factor para glucosa

    float Calcular_Nivel_Glucosa(uint16_t adc_raw_value) {
        float voltaje = ((float)adc_raw_value / VALOR_MAX_ADC_12BIT) * 3.3;
        // Retorna el valor final en mg/dL
        return (voltaje * FACTOR_CONVERSION_MGDL); 
    }
    ```
    ¿En qué capa de la arquitectura del software debe insertarse este bloque de código para minimizar el impacto en la lógica de funcionamiento global del proyecto?  
    Justifique desde el punto de vista de capas de abstracción.

#### Problema 2
Un reloj inteligente utiliza un sensor PPG en la muñeca para calcular el ritmo cardíaco. El prototipo original se diseñó con un microcontrolador básico que leía el sensor mediante un bus de datos lento. 

Para la versión avanzada, se monta un sensor de grado médico que transmite ráfagas constantes de datos con un ancho de bus de 16 bits por canal, requiriendo algoritmos de Procesamiento Digital de Señales (DSP) a alta velocidad.

El hardware de desarrollo anterior se cuelga inmediatamente al intentar procesar la matriz de datos de 16 bits en tiempo real.
1. Determine cual de las siguientes placas de desarrollo es la adecuada para testear este nuevo periferico a su maximo rendimiento, justifique adecuadamente.  
    - Bluepill (STM32F103C8T6 - ARM Cortex-M3 de 32 bits)
    - LPC845BRK (ARM Cortex-M0+ - 32 bits)
    - Arduino Portenta (STM32H7 - Dual Core ARM Cortex-M7/M4 de 32 bits)
2. Para el testeo del sensor, una de las modificaciones a realizar es la medición con el nuevo PPG, para esto se implemento la siguiente función:
    ```cpp
    #include "hal_bus_communication.h"
    #define REG_HEART_RATE_DATA  0x2A

    uint16_t Leer_Muestra_Sensor_PPG(void) {
        uint8_t buffer_datos[2];
        uint16_t muestra_completa;
  
        HAL_Read_Bus_Registers(REG_HEART_RATE_DATA, buffer_datos, 2);   
        muestra_completa = (buffer_datos[0] << 8) | buffer_datos[1];
        
        return muestra_completa;
    }
    ```
    ¿En qué capa de la arquitectura del software debe insertarse este bloque de código para minimizar el impacto en la lógica de funcionamiento global del proyecto?  
    Justifique desde el punto de vista de capas de abstracción.

#### Problema 3
Un sistema embebido es desarrollado para supervisar una incubadora neonatal utilizando una placa educativa básica de 8 bits para leer sensores térmicos de 8 bits. 

El cliente exige cambiar el hardware del sensor por un arreglo de termocuplas de uso médico con registros internos de 16 bits que alerten inmediatamente si la temperatura fluctúa más de 0.1°C.

La arquitectura de 8 bits genera demoras críticas (latencia) al fragmentar lso datos de 16 bits, poniendo en riesgo los tiempos de respuesta del actuador de la incubadora. Para solucionar esto se cuenta con las siguientes placas:   
 - Arduino UNO (ATMega328P AVR - 8bits)    
 - EDU-CIAA-NXP (LPC4337 - Dual-Core ARM Cortex-M4/M0 de 32 bits)  
 - Arduino Q

1. Determine cual puede garantizar un optimo control, evitando desperciar recursor de procesamiento de los datos. Justifique adecuadamente.
2. Para el testeo del sensor, una de las modificaciones a realizar es la logica de las condiciones que deben actuar los perifericos, para esto se implemento:
    ```cpp
    float temperatura_actual = Obtener_Temperatura_Promedio();
    
    if (temperatura_actual > 37.5 || temperatura_actual < 36.0) {
        Disparar_Alarma_Prioridad_Alta(ALERTA_TERMICA_NEONATAL);
    }
    Delay_Monitoreo(100);
    ```
    ¿En qué capa de la arquitectura del software debe insertarse este bloque de código para minimizar el impacto en la lógica de funcionamiento global del proyecto?  
    Justifique desde el punto de vista de capas de abstracción.