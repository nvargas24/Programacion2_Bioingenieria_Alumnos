#### Problema 1
Un glucómetro digital de uso doméstico fue diseñado inicialmente para leer datos por medio de un convertidor analógico-digital (ADC) básico de 8 bits y mostrar el resultado en una pantalla monocromática. 

Sin embargo, para cumplir con las nuevas normativas de salud pública, se requiere actualizar el dispositivo para que utilice un sensor electroquímico de alta precisión con un bus de salida de datos de 12 bits y, además, transmita las lecturas automáticamente al teléfono del paciente por Wi-Fi.

1. Determine cual de las siguientes placas de desarrollo es la adecuada para testear este nuevo periferico, justifique adecuadamente.  
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
1. Determine cual de las siguientes placas de desarrollo es la adecuada para testear este nuevo periferico, justifique adecuadamente.  
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

1. Determine cual puede garantizar un optimo control, evitando desperdiciar recursor de procesamiento de los datos. Justifique adecuadamente.
2. Para el testeo del sensor, una de las modificaciones a realizar es la logica en las condiciones que deben actuar los perifericos, para esto se implemento:
    ```cpp
    float temperatura_actual = Obtener_Temperatura_Promedio();
    
    if (temperatura_actual > 37.5 || temperatura_actual < 36.0) {
        Disparar_Alarma_Prioridad_Alta(ALERTA_TERMICA_NEONATAL);
    }
    Delay_Monitoreo(100);
    ```
    ¿En qué capa de la arquitectura del software debe insertarse este bloque de código para minimizar el impacto en la lógica de funcionamiento global del proyecto?  
    Justifique desde el punto de vista de capas de abstracción.

#### Problema 4
Un prototipo de electromiógrafo portátil (mide pulsos electricos generados por los músculos) fue diseñado usando un microcontrolador básico para capturar señales analógicas a través de un canal lento. 

Para la nueva versión deportiva de alto rendimiento, se integra un sensor analógico médico que procesa y transmite datos con un ancho de bus de 16 bits por canal, requiriendo algoritmos de transformada rápida de Fourier (FFT) en tiempo real para analizar la fatiga muscular.

Al probar el nuevo sensor en el hardware anterior, el microcontrolador se cuelga inmediatamente al intentar fragmentar los datos de 16 bits del bus y realizar los cálculos matemáticos simultáneos. Se requiere cambiar la placa por una de bajo costo pero con una arquitectura de 32 bits eficiente para procesar aritmética de enteros sin desbordamientos.
1. Determine cual de las siguientes placas de desarrollo es la adecuada para testear este nuevo periferico, justifique adecuadamente.  
    - Arduino UNO (ATMega328P AVR - 8 bits)
    - LPC845BRK (ARM Cortex-M0+ - 32 bits)
    - Bluepill (STM32F103C8T6 - ARM Cortex-M3 de 32 bits)
2. Para el testeo del sensor, una de las modificaciones a realizar es la logica del en las condiciones que deben actuar los perifericos, para esto se implemento:
```cpp
#include "hal_adc_interface.h"
#define REG_EMG_CHANNEL_1  0x3A

uint16_t Adquirir_Muestra_Muscular(void) {
    uint8_t buffer_bytes[2];
    uint16_t muestra_combinada;

    // Solicita a la HAL la lectura secuencial de los 2 bytes
    HAL_Read_Peripheral_Registers(REG_EMG_CHANNEL_1, buffer_bytes, 2);   
    
    // Se reconstruye el ancho de bus nativo de 16 bits del sensor
    muestra_combinada = (buffer_bytes[0] << 8) | buffer_bytes[1];
    
    return muestra_combinada;
}
```
Justifique desde el punto de vista de capas de abstracción.

#### Problema 5
Se está desarrollando un control mioeléctrico (un sistema que utiliza señales eléctricas naturales del cuerpo) para una prótesis de extremidades. Uno de los sensores a utilizar es un FSR (resistencia variable por fuerza) para interpretar la intención del movimiento. Se sabe que este sensor varía su resistencia entre $1\text{ k}\Omega$ y $100\text{ k}\Omega$, con un tiempo de respuesta de $3\text{ ms}$ y un margen de error de $\pm5\%$.   
1.  Determine cuál de las siguientes placas de desarrollo es la adecuada para testear el periférico sin desperdiciar recursos. Justifique adecuadamente su elección:   
    -   Arduino UNO (ATMega328P AVR - 8 bits)  
    -   LPC845BRK (ARM Cortex-M0+ - 32 bits)   
    -   Bluepill (STM32F103C8T6 - ARM Cortex-M3 de 32 bits)   

2.  El firmware para este sensor se desarrolló en C y, para garantizar su reutilización, se implementaron capas de abstracción. Si se requiere modificar la lógica principal del proyecto, ¿cuál capa se vería afectada principalmente?
```cpp
#define UMBRAL_FUERZA

int main(){
    sytem_init();

    float fuerza_actual = 0.0f;

    while(1){
        if(SERVICE_system_isTickReady()){
            fuerza_actual = SERVICE_FSR_GetForce();

            switch(estado_actiual){
                case PROTESIS_REPOSO:
                    // Detener motor
                    break;
                case PROTESIS_CERRANDO:
                    // Mover motores para cerrar
                    break;
                case PROTESIS_SUJETANDO:
                    // Mantener torque y posicion  
                    break;
            }
        }
    }
    return 0;
}
```
Justifique desde el punto de vista de capas de abstracción.

#### Problema 6
Se esta desarrollando un sistema portatil de telemetria medica para el monitores de pacientes cardiorrespiratorios. El dispositivo utiliza un Oximetro (sensor de oximetris de pulso y frecuencia cardiaca) que se comunica por I2C. El sistema debe procesar las señales de forma local y transmitir los datos de manera inalambrica a una central.
1.  Determine cuál de las siguientes placas de desarrollo es la adecuada para testear el periferico y sin desperdiciar recursos.Justifique adecuadamente su elección:
    -   Bluepill (STM32F103C8T6 - ARM Cortex-M3 de 32 bits)
    -   EDU-CIAA NXP (ARM Cortex-M4 de 32 bits - LPC4337)
    -   ESP32 (Dual-Core Xtensa de 32 bits)

2. La arquitectura del software se mantiene reutilizando capas de abstraccion. Debido a desperfecto en los pines I2C del microcontrolador, deben seleccionarse el otro par de pines. Para esto se realizo la siguiente modificacion:
    ```cpp
    #define I2C_SDA_PIN   GPIO_NUM_18 
    #define I2C_SCL_PIN   GPIO_NUM_19

    void I2C_Init(uint32_t velocidad_hz) {
        i2c_config_t conf = {
            // Cambio de pin físico 
            // Velocidad de comunicacion
            .master.clk_speed = velocidad_hz
        };
        i2c_param_config(I2C_NUM_0, &conf);
    }
    ```
Determine a que capa se esta afecta al realizar el cambio de pines fisicos, bajo el punto de vista de placas de abstraccion.

#### Problema 7
Se esta desarrollando un exoesqueleto robotico para rehabilitacion de pacientes con lesiones. El sistema utiliza sensores de angulo de efecto Hall de valor absoluto, colocados en las articulaciones para medir la flexo-extension. Debido a la geometria mecanica del exoesqueleto se requiere emplear un calculo preciso para calcular el angulo, esto se logra mediante el metodo numerico Newton-Raphson. Por motivos de seguridad está prohibido usar conexiones inalámbricas (Wi-Fi/Bluetooth) para evitar interferencias. El sistema exige enviar los datos a un software de análisis clínico instaldo en una PC de manera cableada, robusta y con aislamiento (tipo industrial).
1.  Determine cuál de las siguientes placas de desarrollo es la adecuada para testear los periféricos y cumplir con las necesidades del sistema sin desperdiciar recursos. Justifique adecuadamente su elección:
    -   Bluepill (STM32F103C8T6 - ARM Cortex-M3 de 32 bits)
    -   EDU-CIAA NXP (ARM Cortex-M4/M0 Dual Core - LPC4337)
    -   ESP32 (Dual-Core Xtensa de 32 bits)

2.  El firmware está estructurado bajo una arquitectura de capas de abstracción. Para procesar los datos magnéticos crudos del sensor y convertirlos en grados sexagesimales de la articulación, se implementó el método de Newton-Raphson. Determine y justifique a qué capa pertenece este algoritmo:

    ```cpp
    #include "service_kinematics.h"
    #include "hal_sensors.h" 

    #define MAX_ITERACIONES  12
    #define TOLERANCIA  0.0005f

    float exo_GetJointAngle(void) {
        // Solicita lectura del dato
        uint32_t raw_magnetic = Sensor_ReadMagneticRaw();
        float x_ant = (float)raw_magnetic / 100.0f; // Estimación inicial 
        float x_act = 0.0f;

        for (int i = 0; i < MAX_ITERACIONES; i++) {
            float f_x = (x_ant * x_ant * x_ant) + x_ant - (float)raw_magnetic;
            float df_x = (3.0f * x_ant * x_ant) + 1.0f;

            // Fórmula estándar de Newton-Raphson
            x_act = x_ant - (f_x / df_x);
            // Si es buena aproxima se rompe ciclo

            if (float_abs(x_act - x_ant) < TOLERANCIA) break;
            x_ant = x_act;
        }
        return x_act; 
    }
    ```

#### Problema 8
Se está desarrollando un chaleco corrector de postura inteligente para fisioterapia para prevenir lesiones lumbares en trabajadores de almacén. El sistema utiliza un goniométmetro digital de eje único (un sensor que mide la flexión de la espalda). Este sensor integra su propio convertidor interno y entrega la información angular directamente de forma digital en un ancho de bus de 8 bits.
Al tratarse de un vestible de monitoreo biomecánico preventivo, no requiere procesamiento en tiempo real de alta velocidad.
1.  Determine cuál de las siguientes placas de desarrollo es la adecuada para testear el periféricosin desperdiciar recursos. Justifique adecuadamente su elección:
    -   Arduino UNO (ATMega328P AVR - 8 bits)
    -   LPC845BRK (ARM Cortex-M0+ - 32 bits)
    -   ESP32 (Dual-Core Xtensa de 32 bits)     
2.  Originalmente, el chaleco solo emitía un pitido cuando el usuario se agachaba de forma incorrecta (flexión mayor a 60°). Sin embargo, se solicita modificar la lógica del proyecto para implementar una alerta de fatiga por postura estática. Si el usuario permanece agachado por más de 10 segundos continuos, el chaleco debe activar un motor de vibración con un patrón intermitente. Considerando que se estructuro implementando capas de abstraccion determine qué capa se ve afectada principalmente por este cambio en la lógica del proyecto, si la logica se cambio a:

    ```cpp
    #include "services_goniometer.h" 
    #include "hal_peripherals.h"    

    #define ANGULO_LIMITE_CRITICO   60.0f
    #define TIEMPO_FATIGA_TICKS 1000

    typedef enum {
        POSTURA_CORRECTA,
        POSTURA_INCORRECTA_RAPIDA,
        POSTURA_FATIGA_ESTATICA
    } estadoChaleco_t;

    int main(void) {
        estadoChaleco_t estado_actual = POSTURA_CORRECTA;
        float angulo_espalda = 0.0f;
        uint32_t contador_tiempo_agachado = 0;

        system_init();

        while(1) {
            if (system_IsTickReady()) {
                angulo_espalda = Goniometer_GetAngle();
                switch(estado_actual) {
                    case POSTURA_CORRECTA:
                        vibrador_Off();
                        contador_tiempo_agachado = 0;
                        if (angulo_espalda > ANGULO_LIMITE_CRITICO)
                            estado_actual = POSTURA_INCORRECTA_RAPIDA;
                        break;
                    case POSTURA_INCORRECTA_RAPIDA:
                        vibrador_On_Suave();
                        contador_tiempo_agachado++;
                        if (angulo_espalda <= ANGULO_LIMITE_CRITICO) 
                            estado_actual = POSTURA_CORRECTA;
                        else if (contador_tiempo_agachado >= TIEMPO_FATIGA) 
                            estado_actual = POSTURA_FATIGA_ESTATICA;
                        break;
                    case POSTURA_FATIGA_ESTATICA:
                        vibrador_Pattern_Intermitente()
                        if (angulo_espalda <= ANGULO_LIMITE_CRITICO) 
                            estado_actual = POSTURA_CORRECTA;
                        break;
                }
            }
        }
        return 0;
    }
    ```
