#### Problema 1
Diseñe una máquina de estados de Moore para el control básico de una prótesis. El sistema consta de dos estados únicos: **ST_REPOSO** y **ST_CONTRACCION**.

1.  Estando en **ST_REPOSO**, la máquina mantiene encendido el LED Verde y apagado el LED Rojo. Si el programa detecta que el SENSOR_EMG es presionado, transiciona al estado **ST_CONTRACCION**.

2. Estando en **ST_CONTRACCION**, el LED Verde se apaga y se enciende de forma fija el LED Rojo (simulando que el motor de la mano se cierra). La máquina permanecerá en este estado hasta que el usuario suelte el pulsador, regresando de inmediato a **ST_REPOSO**.

> **Equivalente de Hardware Básico**:
>> - Entrada:   
>>    1 Pulsador que simula un sensor de fuerza muscular.  
>>   - Suelto (LOW): Fuerza baja.  
>>   - Presionado (HIGH): Fuerza alta.
>> - Salidas:   
>>   2 LEDs (LED Verde: Reposo / LED Rojo: Motor activado).

#### Problema 2
Diseñe una máquina de estados de Moore que gestione las alertas de una habitación hospitalaria utilizando 3 estados: **ST_NORMAL**, **ST_ESPERA_LIBERACION** y **ST_ALERTA**.
1. El sistema inicia en **ST_NORMAL**, donde el LED Verde está encendido y el Azul apagado. Si el paciente presiona el BOTON_LLAMADA, la máquina avanza al estado **ST_ESPERA_LIBERACION**.
2. En **ST_ESPERA_LIBERACION**, el LED Verde se apaga y el LED Azul se enciende. La máquina se queda congelada en este estado sondeando el botón; solo cuando el paciente retira el dedo (el botón vuelve a estar suelto), el sistema avanza al estado definitivo **ST_ALERTA**.
3. En **ST_ALERTA**, el LED Azul permanece encendido fijamente para que la enfermera sepa que la llamaron, sin importar que el paciente ya haya soltado el botón. 

Nota: Asuma que el sistema se queda en este estado de alerta de forma indefinida.

#### Problema 3
