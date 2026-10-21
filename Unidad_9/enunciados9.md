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

>**Nota**: Asuma que el sistema se queda en este estado de alerta de forma indefinida.

#### Problema 3
Desarrolle una máquina de estados de Moore bloqueante para el sistema de seguridad de un respirador pulmonar. El sistema debe vigilar el sensor de presión; si detecta una sobrepresión, la máquina debe encender el LED Rojo de alarma y ejecutar un retraso bloqueante de protección de **sysTime_delay_ms(1000)**. Al finalizar este tiempo, la alarma debe quedarse encendida de forma estática y el sistema no puede retornar al modo normal automáticamente, sino que debe retener la alerta y esperar por polling a que el operario presione el botón de reset.

>**Equivalente de Hardware Básico**  
> -  Entradas:
>    - SENSOR_PRESION (Pulsador auxiliar):   
>      Presión normal = 1, Sobrepresión = 0.   
>    - BOTON_RESET (Pulsador en K3):   
>      Presionado = 0.       
> - Salidas (Lógica Negativa): 
>   - LED Rojo (PIO1_2).

> **Estados Base Sugeridos**   
> **ST_MONITOR_NORMAL** (Salida: LED Rojo apagado).   
> **ST_DISPARO_ALARMA** (Salida: LED Rojo encendido + acción de retraso).  
> **ST_RETENCION_ALERTA** (Salida: LED Rojo encendido, en espera de confirmación por polling).

#### Problema 4
Desarrolle una máquina de estados de Moore utilizando polling directo para gestionar dos perfiles térmicos estables dentro de una cámara de cultivos biológicos. La FSM debe arrancar en un estado de consulta del pulsador. Cada vez que el programa registre que el botón fue presionado y soltado por el usuario, la máquina debe alternar cíclicamente entre el Perfil 1 (encender solo el LED Verde y mostrar el número 1 en el display) y el Perfil 2 (encender solo el LED Rojo y mostrar el número 2 en el display).

>**Equivalente de Hardware Básico**      
> - **Entrada**: BOTON_MODO (Pulsador en PIO0_4):    
>   - Presionado = 0.  
> - **Salidas** (Lógica Negativa):    
>   - LED Verde (PIO1_0), LED Rojo (PIO1_2).   
>   - Display de 1 Dígito: Muestra el número identificador del modo activo.

> **Estados Base Sugeridos**   
> **ST_CONSULTA_BOTON** (Estado central de polling).  
> **ST_PERFIL_1** (Salida: LED Verde ON, Display = 1).  
> **ST_PERFIL_2** (Salida: LED Rojo ON, Display = 2).

#### Problema 5
Diseñe una máquina de estados de Moore que gestione los modos de operación de un equipo de fisioterapia TENS. El sistema inicia en el *estado de reposo* con ambos **LEDs apagados** y el **display de 2 dígitos mostrando 00**. Mediante polling constante de la matriz 4x4, el sistema debe responder a las siguientes acciones:  
1. Si el usuario **presiona la tecla A**, la máquina transiciona al **perfil analgésico**: enciende de forma fija el LED Verde y el display de 2 dígitos muestra el número 80 (80 Hz).  
2. Si el usuario **presiona la tecla B**, la máquina transiciona al **perfil de tonificación muscular**: apaga el LED Verde, enciende de forma fija el LED Rojo y el display cambia para mostrar el número 02 (2 Hz).

> **Nota**: Se deben considerar estados de espera de liberación para evitar que la máquina salte erráticamente entre perfiles si se deja la tecla presionada de forma continua.

>**Equivalente de Hardware Básico**   
> - **Entrada**: Matriz de pulsadores 4x4. Para este problema solo se evalúa por polling la tecla A (Frecuencia Analgésica) y la tecla B (Frecuencia de Tonificación).
> - **Salidas** (Lógica Negativa): 
>   - LED Verde (PIO1_0) y LED Rojo (PIO1_2).
>   - Display de 2 Dígitos: Muestra el valor numérico de la frecuencia seleccionada en hercios (02, 80 o 00 si está apagado).


> **Estados Base Sugeridos**   
> **ST_REPOSO_OFF** (Salida: LEDs apagados, Display = 00).
> **ST_ESPERA_TECLA** (Bloque de polling de la matriz 4x4).
> **ST_MODO_ANALGESIA** (Salida: LED Verde ON, Display = 80).
> **ST_MODO_TONIFICACION** (Salida: LED Rojo ON, Display = 02).

#### Problema 6
Desarrolle una máquina de estados de Moore para un monitor centralizado de un hospital. El sistema arranca en un estado base esperando una señal de emergencia con el **LED Rojo apagado** y el **display de 1 dígito mostrando el número 0**. El programa realiza polling a las columnas de la matriz 4x4; en el momento en que se detecta la presión de **cualquiera de las teclas numéricas (1, 2, 3 o 4)**, la máquina debe almacenar el número de cama, **encender el LED Rojo** de alerta general y pasar a un estado bloqueante que ejecuta un retraso de protección de **sysTime_delay_ms(2000)**. Durante este tiempo, el display de 1 dígito debe mostrar fijamente el número de la cama pulsada. Al finalizar el retraso, el sistema regresa de forma incondicional al estado base de espera, apagando el LED Rojo y regresando el display a 0.

>**Equivalente de Hardware Básico**   
> - **Entrada**: 
>   - Matriz de pulsadores 4x4. Se realiza polling a las teclas numéricas del 1 al 4 (representan los números de camas del pabellón).
> - **Salidas** (Lógica Negativa):  
>   - LED Rojo (PIO1_2) para indicar estado de alarma activa.
>   - Display de 1 Dígito: Muestra el número de la cama que requiere asistencia médica.


> **Estados Base Sugeridos**    
> **ST_ESPERA_ALERTA** (Salida: LED Rojo OFF, Display = 0).
> **ST_CAMA_ACTIVA** (Salida: LED Rojo ON, Display = Número seleccionado + acción de retraso).

#### Problema 7
Desarrolle una máquina de estados de Moore que actúe como la interfaz de programación de una bomba de infusión de medicamentos. Al iniciar, el dispositivo se encuentra en standby, **mostrando 00 en el display de 2 dígitos** y con el **LED Azul apagado**. Mediante polling de la matriz 4x4, el usuario puede configurar la dosis deseada: al pulsar la tecla 1, la máquina guarda una dosis de 05 ml; al pulsar la tecla 2, guarda una dosis de 25 ml. El display de 2 dígitos reflejará inmediatamente el valor elegido (05 o 25). El **sistema se quedará esperando** en ese estado de preconfiguración hasta que el operario presione la tecla de confirmación **'*'**. Al registrarse dicha tecla, la FSM avanzará al estado de infusión activa, encendiendo el LED Azul de forma bloqueante durante el tiempo programado, para finalmente borrar el display a 00 y retornar incondicionalmente al reposo.

>**Equivalente de Hardware Básico**  
> - **Entrada**: 
>   - Matriz de pulsadores 4x4. Se realiza polling a las teclas 1 (Dosis Baja), 2 (Dosis Media) y * (Confirmar/Disparar infusión).     
> - **Salidas** (Lógica Negativa): LED Azul (PIO1_1) que emula el motor de la jeringa de infusión.   
>   - **Display de 2 Dígitos**: Muestra el volumen en mililitros preconfigurado para inyectar (05, 25 o 00).

> **Estados Base Sugeridos**   
> **ST_STANDBY** (Salida: LED Azul OFF, Display = 00).  
> **ST_DOSIS_5ML** (Salida: LED Azul OFF, Display = 05).  
> **ST_DOSIS_25ML** (Salida: LED Azul OFF, Display = 25).  
> **ST_INFUNDIENDO** (Salida: LED Azul ON + retraso bloqueante proporcional a la dosis).  

